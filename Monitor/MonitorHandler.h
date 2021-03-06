/*
 *  Copyright 2005,2006 Fabrice Colin
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
#ifndef _MONITORHANDLER_HH
#define _MONITORHANDLER_HH

#include <string>
#include <set>
#include <map>

#include "MonitorInterface.h"

/// Handles events generated by a monitor.
class MonitorHandler
{
	public:
		MonitorHandler();
		virtual ~MonitorHandler();

		/// Initializes things before starting monitoring.
		virtual void initialize(void);

		/// Handles flushing the index.
		virtual void flushIndex(void);

		/// Handles file existence events.
		virtual bool fileExists(const std::string &fileName);

		/// Handles file creation events.
		virtual bool fileCreated(const std::string &fileName);

		/// Handles directory creation events.
		virtual bool directoryCreated(const std::string &dirName);

		/// Handles file modified events.
		virtual bool fileModified(const std::string &fileName);

		/// Handles file moved events.
		virtual bool fileMoved(const std::string &fileName,
			const std::string &previousFileName);

		/// Handles directory moved events.
		virtual bool directoryMoved(const std::string &dirName,
			const std::string &previousDirName);

		/// Handles file deleted events.
		virtual bool fileDeleted(const std::string &fileName);

		/// Handles directory deleted events.
		virtual bool directoryDeleted(const std::string &dirName);

		/// Returns the names of files to monitor.
		const std::set<std::string> &getFileNames(void) const;

	protected:
		std::set<std::string> m_fileNames;

	private:
		MonitorHandler(const MonitorHandler &other);
		MonitorHandler &operator=(const MonitorHandler &other);

};

#endif	// _MONITORHANDLER_HH
