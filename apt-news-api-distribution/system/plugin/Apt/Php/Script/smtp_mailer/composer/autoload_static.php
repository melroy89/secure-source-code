<?php

// autoload_static.php @generated by Composer

namespace Composer\Autoload;

class ComposerStaticInite00c3447eed9db313a6c59aedbbbbe76
{
    public static $prefixLengthsPsr4 = array (
        'P' => 
        array (
            'PHPMailer\\PHPMailer\\' => 20,
        ),
    );

    public static $prefixDirsPsr4 = array (
        'PHPMailer\\PHPMailer\\' => 
        array (
            0 => __DIR__ . '/..' . '/phpmailer/phpmailer/src',
        ),
    );

    public static $classMap = array (
        'Composer\\InstalledVersions' => __DIR__ . '/..' . '/composer/InstalledVersions.php',
    );

    public static function getInitializer(ClassLoader $loader)
    {
        return \Closure::bind(function () use ($loader) {
            $loader->prefixLengthsPsr4 = ComposerStaticInite00c3447eed9db313a6c59aedbbbbe76::$prefixLengthsPsr4;
            $loader->prefixDirsPsr4 = ComposerStaticInite00c3447eed9db313a6c59aedbbbbe76::$prefixDirsPsr4;
            $loader->classMap = ComposerStaticInite00c3447eed9db313a6c59aedbbbbe76::$classMap;

        }, null, ClassLoader::class);
    }
}
