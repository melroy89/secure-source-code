import * as fs from 'fs-extra';
import { readCredentialFile } from '@joplin/lib/utils/credentialFiles';

const fetch = require('node-fetch');
const execa = require('execa');
const { splitCommandString } = require('@joplin/lib/string-utils');
const moment = require('moment');

export interface GitHubReleaseAsset {
	name: string;
	browser_download_url: string;
}

export interface GitHubRelease {
	assets: GitHubReleaseAsset[];
	tag_name: string;
	upload_url: string;
	html_url: string;
	prerelease: boolean;
	draft: boolean;
}

function quotePath(path: string) {
	if (!path) return '';
	if (path.indexOf('"') < 0 && path.indexOf(' ') < 0) return path;
	path = path.replace(/"/, '\\"');
	return `"${path}"`;
}

function commandToString(commandName: string, args: string[] = []) {
	const output = [quotePath(commandName)];

	for (const arg of args) {
		output.push(quotePath(arg));
	}

	return output.join(' ');
}

async function insertChangelog(tag: string, changelogPath: string, changelog: string, isPrerelease: boolean, repoTagUrl: string = '') {
	repoTagUrl = repoTagUrl || 'https://github.com/laurent22/joplin/releases/tag';

	const currentText = await fs.readFile(changelogPath, 'UTF-8');
	const lines = currentText.split('\n');

	const beforeLines = [];
	const afterLines = [];

	for (const line of lines) {
		if (afterLines.length) {
			afterLines.push(line);
			continue;
		}

		if (line.indexOf('##') === 0) {
			afterLines.push(line);
			continue;
		}

		beforeLines.push(line);
	}

	const header = [
		'##',
		`[${tag}](${repoTagUrl}/${tag})`,
	];
	if (isPrerelease) header.push('(Pre-release)');
	header.push('-');
	// eslint-disable-next-line no-useless-escape
	header.push(`${moment.utc().format('YYYY-MM-DD\THH:mm:ss')}Z`);

	let newLines = [];
	newLines.push(header.join(' '));
	newLines.push('');
	newLines = newLines.concat(changelog.split('\n'));
	newLines.push('');

	const output = beforeLines.concat(newLines).concat(afterLines);

	return output.join('\n');
}

export function releaseFinalGitCommands(appName: string, newVersion: string, newTag: string): string {
	const finalCmds = [
		'git pull',
		'git add -A',
		`git commit -m "${appName} ${newVersion}"`,
		`git tag "${newTag}"`,
		'git push',
		'git push --tags',
	];

	return finalCmds.join(' && ');
}

export async function completeReleaseWithChangelog(changelogPath: string, newVersion: string, newTag: string, appName: string, isPreRelease: boolean, repoTagUrl = '') {
	const changelog = (await execCommand2(`node ${rootDir}/packages/tools/git-changelog ${newTag} --publish-format full`, { showStdout: false })).trim();

	const newChangelog = await insertChangelog(newTag, changelogPath, changelog, isPreRelease, repoTagUrl);

	await fs.writeFile(changelogPath, newChangelog);

	console.info('');
	console.info('Verify that the changelog is correct:');
	console.info('');
	console.info(`${process.env.EDITOR} "${changelogPath}"`);
	console.info('');
	console.info('Then run these commands:');
	console.info('');
	console.info(releaseFinalGitCommands(appName, newVersion, newTag));
}

async function loadGitHubUsernameCache() {
	const path = `${__dirname}/github_username_cache.json`;

	if (await fs.pathExists(path)) {
		const jsonString = await fs.readFile(path, 'utf8');
		return JSON.parse(jsonString);
	}

	return {};
}

async function saveGitHubUsernameCache(cache: any) {
	const path = `${__dirname}/github_username_cache.json`;
	await fs.writeFile(path, JSON.stringify(cache));
}

// Returns the project root dir
export const rootDir: string = require('path').dirname(require('path').dirname(__dirname));

export function execCommand(command: string, options: any = null): Promise<string> {
	options = options || {};

	const exec = require('child_process').exec;

	return new Promise((resolve, reject) => {
		exec(command, options, (error: any, stdout: any, stderr: any) => {
			if (error) {
				if (error.signal === 'SIGTERM') {
					resolve('Process was killed');
				} else {
					reject(error);
				}
			} else {
				resolve([stdout.trim(), stderr.trim()].join('\n'));
			}
		});
	});
}

export function resolveRelativePathWithinDir(baseDir: string, ...relativePath: string[]): string {
	const path = require('path');
	const resolvedBaseDir = path.resolve(baseDir);
	const resolvedPath = path.resolve(baseDir, ...relativePath);
	if (resolvedPath.indexOf(resolvedBaseDir) !== 0) throw new Error(`Resolved path for relative path "${JSON.stringify(relativePath)}" is not within base directory "${baseDir}" (Was resolved to ${resolvedPath})`);
	return resolvedPath;
}

export function execCommandVerbose(commandName: string, args: string[] = []) {
	console.info(`> ${commandToString(commandName, args)}`);
	const promise = execa(commandName, args);
	promise.stdout.pipe(process.stdout);
	return promise;
}

interface ExecCommandOptions {
	showInput?: boolean;
	showStdout?: boolean;
	showStderr?: boolean;
	quiet?: boolean;
}

// There's lot of execCommandXXX functions, but eventually all scripts should
// use the one below, which supports:
//
// - Printing the command being executed
// - Printing the output in real time (piping to stdout)
// - Returning the command result as string
export async function execCommand2(command: string | string[], options: ExecCommandOptions = null): Promise<string> {
	options = {
		showInput: true,
		showStdout: true,
		showStderr: true,
		quiet: false,
		...options,
	};

	if (options.quiet) {
		options.showInput = false;
		options.showStdout = false;
		options.showStderr = false;
	}

	if (options.showInput) {
		if (typeof command === 'string') {
			console.info(`> ${command}`);
		} else {
			console.info(`> ${commandToString(command[0], command.slice(1))}`);
		}
	}

	const args: string[] = typeof command === 'string' ? splitCommandString(command) : command as string[];
	const executableName = args[0];
	args.splice(0, 1);
	const promise = execa(executableName, args);
	if (options.showStdout) promise.stdout.pipe(process.stdout);
	if (options.showStderr) promise.stdout.pipe(process.stderr);
	const result = await promise;
	return result.stdout.trim();
}

export function execCommandWithPipes(executable: string, args: string[]) {
	const spawn = require('child_process').spawn;

	return new Promise((resolve, reject) => {
		const child = spawn(executable, args, { stdio: 'inherit' });

		child.on('error', (error: any) => {
			reject(error);
		});

		child.on('close', (code: any) => {
			if (code !== 0) {
				reject(`Ended with code ${code}`);
			} else {
				resolve(null);
			}
		});
	});
}

export function toSystemSlashes(path: string) {
	const os = process.platform;
	if (os === 'win32') return path.replace(/\//g, '\\');
	return path.replace(/\\/g, '/');
}

export async function setPackagePrivateField(filePath: string, value: any) {
	const text = await fs.readFile(filePath, 'utf8');
	const obj = JSON.parse(text);
	if (!value) {
		delete obj.private;
	} else {
		obj.private = true;
	}
	await fs.writeFile(filePath, JSON.stringify(obj, null, 2), 'utf8');
}

export async function downloadFile(url: string, targetPath: string) {
	const https = require('https');
	const fs = require('fs');

	return new Promise((resolve, reject) => {
		const file = fs.createWriteStream(targetPath);
		https.get(url, function(response: any) {
			if (response.statusCode !== 200) reject(new Error(`HTTP error ${response.statusCode}`));
			response.pipe(file);
			file.on('finish', function() {
				// file.close();
				resolve(null);
			});
		}).on('error', (error: any) => {
			reject(error);
		});
	});
}

export function fileSha256(filePath: string) {
	return new Promise((resolve, reject) => {
		const crypto = require('crypto');
		const fs = require('fs');
		const algo = 'sha256';
		const shasum = crypto.createHash(algo);

		const s = fs.ReadStream(filePath);
		s.on('data', function(d: any) { shasum.update(d); });
		s.on('end', function() {
			const d = shasum.digest('hex');
			resolve(d);
		});
		s.on('error', function(error: any) {
			reject(error);
		});
	});
}

export async function unlinkForce(filePath: string) {
	const fs = require('fs-extra');

	try {
		await fs.unlink(filePath);
	} catch (error) {
		if (error.code === 'ENOENT') return;
		throw error;
	}
}

export function fileExists(filePath: string) {
	const fs = require('fs-extra');

	return new Promise((resolve, reject) => {
		fs.stat(filePath, function(err: any) {
			if (!err) {
				resolve(true);
			} else if (err.code === 'ENOENT') {
				resolve(false);
			} else {
				reject(err);
			}
		});
	});
}


export async function gitRepoClean(): Promise<boolean> {
	const output = await execCommand2('git status --porcelain', { quiet: true });
	return !output.trim();
}


export async function gitRepoCleanTry() {
	if (!(await gitRepoClean())) throw new Error(`There are pending changes in the repository: ${process.cwd()}`);
}

export async function gitPullTry(ignoreIfNotBranch = true) {
	try {
		await execCommand('git pull');
	} catch (error) {
		if (ignoreIfNotBranch && error.message.includes('no tracking information for the current branch')) {
			console.info('Skipping git pull because no tracking information on current branch');
		} else {
			throw error;
		}
	}
}

export const gitCurrentBranch = async (): Promise<string> => {
	const output = await execCommand2('git rev-parse --abbrev-ref HEAD', { quiet: true });
	return output.trim();
};

export async function githubUsername(email: string, name: string) {
	const cache = await loadGitHubUsernameCache();
	const cacheKey = `${email}:${name}`;
	if (cacheKey in cache) return cache[cacheKey];

	let output = null;

	const oauthToken = await githubOauthToken();

	const urlsToTry = [
		`https://api.github.com/search/users?q=${encodeURI(email)}+in:email`,

		// Note that this can fail if the email could not be found and the user
		// shares a name with someone else. It's rare enough that we can leave
		// it for now.
		// https://github.com/laurent22/joplin/pull/5390
		`https://api.github.com/search/users?q=user:${encodeURI(name)}`,
	];

	for (const url of urlsToTry) {
		const response = await fetch(url, {
			method: 'GET',
			headers: {
				'Content-Type': 'application/json',
				'Authorization': `token ${oauthToken}`,
			},
		});

		const responseText = await response.text();

		if (!response.ok) continue;

		const responseJson = JSON.parse(responseText);
		if (!responseJson || !responseJson.items || responseJson.items.length !== 1) continue;

		output = responseJson.items[0].login;
		break;
	}

	cache[cacheKey] = output;
	await saveGitHubUsernameCache(cache);

	return output;
}

export function patreonOauthToken() {
	return readCredentialFile('patreon_oauth_token.txt');
}

export function githubOauthToken() {
	return readCredentialFile('github_oauth_token.txt');
}

// Note that the GitHub API releases/latest is broken on the joplin-android repo
// as of Nov 2021 (last working on 3 November 2021, first broken on 19
// November). It used to return the latest **published** release but now it
// retuns... some release, always the same one, but not the latest one. GitHub
// says that nothing has changed on the API, although it used to work. So since
// we can't use /latest anymore, we need to fetch all the releases to find the
// latest published one.
export async function gitHubLatestRelease(repoName: string): Promise<GitHubRelease> {
	let pageNum = 1;

	while (true) {
		const response: any = await fetch(`https://api.github.com/repos/laurent22/${repoName}/releases?page=${pageNum}`, {
			headers: {
				'Content-Type': 'application/json',
				'User-Agent': 'Joplin Readme Updater',
			},
		});

		if (!response.ok) throw new Error(`Cannot fetch releases: ${response.statusText}`);

		const releases = await response.json();
		if (!releases.length) throw new Error('Cannot find latest release');

		for (const release of releases) {
			if (release.prerelease || release.draft) continue;
			return release;
		}

		pageNum++;
	}
}

export async function githubRelease(project: string, tagName: string, options: any = null): Promise<GitHubRelease> {
	options = Object.assign({}, {
		isDraft: false,
		isPreRelease: false,
	}, options);

	const oauthToken = await githubOauthToken();

	const response = await fetch(`https://api.github.com/repos/laurent22/${project}/releases`, {
		method: 'POST',
		body: JSON.stringify({
			tag_name: tagName,
			name: tagName,
			draft: options.isDraft,
			prerelease: options.isPreRelease,
		}),
		headers: {
			'Content-Type': 'application/json',
			'Authorization': `token ${oauthToken}`,
		},
	});

	const responseText = await response.text();

	if (!response.ok) throw new Error(`Cannot create GitHub release: ${responseText}`);

	const responseJson = JSON.parse(responseText);
	if (!responseJson.url) throw new Error(`No URL for release: ${responseText}`);

	return responseJson;
}

export function readline(question: string) {
	return new Promise((resolve) => {
		const readline = require('readline');

		const rl = readline.createInterface({
			input: process.stdin,
			output: process.stdout,
		});

		rl.question(`${question} `, (answer: string) => {
			resolve(answer);
			rl.close();
		});
	});
}

export function isLinux() {
	return process && process.platform === 'linux';
}

export function isWindows() {
	return process && process.platform === 'win32';
}

export function isMac() {
	return process && process.platform === 'darwin';
}

export async function insertContentIntoFile(filePath: string, markerOpen: string, markerClose: string, contentToInsert: string) {
	const fs = require('fs-extra');
	let content = await fs.readFile(filePath, 'utf-8');
	// [^]* matches any character including new lines
	const regex = new RegExp(`${markerOpen}[^]*?${markerClose}`);
	content = content.replace(regex, markerOpen + contentToInsert + markerClose);
	await fs.writeFile(filePath, content);
}

export function dirname(path: string) {
	if (!path) throw new Error('Path is empty');
	const s = path.split(/\/|\\/);
	s.pop();
	return s.join('/');
}

export function basename(path: string) {
	if (!path) throw new Error('Path is empty');
	const s = path.split(/\/|\\/);
	return s[s.length - 1];
}

export function filename(path: string, includeDir = false) {
	if (!path) throw new Error('Path is empty');
	const output = includeDir ? path : basename(path);
	if (output.indexOf('.') < 0) return output;

	const splitted = output.split('.');
	splitted.pop();
	return splitted.join('.');
}

export function fileExtension(path: string) {
	if (!path) throw new Error('Path is empty');

	const output = path.split('.');
	if (output.length <= 1) return '';
	return output[output.length - 1];
}
