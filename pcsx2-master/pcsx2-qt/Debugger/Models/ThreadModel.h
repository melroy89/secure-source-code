/*  PCSX2 - PS2 Emulator for PCs
 *  Copyright (C) 2002-2023  PCSX2 Dev Team
 *
 *  PCSX2 is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU Lesser General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  PCSX2 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with PCSX2.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QtCore/QAbstractTableModel>

#include "DebugTools/DebugInterface.h"
#include "DebugTools/BiosDebugData.h"

#include <map>

class ThreadModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	enum ThreadColumns : int
	{
		ID = 0,
		PC,
		ENTRY,
		PRIORITY,
		STATE,
		WAIT_TYPE,
		COLUMN_COUNT
	};

	explicit ThreadModel(DebugInterface& cpu, QObject* parent = nullptr);

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

	void refreshData();

private:
	const std::map<int, QString> ThreadStateStrings{
		{THS_BAD, tr("BAD")},
		{THS_RUN, tr("RUN")},
		{THS_READY, tr("READY")},
		{THS_WAIT, tr("WAIT")},
		{THS_SUSPEND, tr("SUSPEND")},
		{THS_WAIT_SUSPEND, tr("WAIT SUSPEND")},
		{THS_DORMANT, tr("DORMANT")}};

	const std::map<int, QString> ThreadWaitStrings{
		{WAIT_NONE, tr("NONE")},
		{WAIT_WAKEUP_REQ, tr("WAKEUP REQUEST")},
		{WAIT_SEMA, tr("SEMAPHORE")}};

	DebugInterface& m_cpu;
};
