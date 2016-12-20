/*
 * FileLogger.h
 *
 *  Created on: 2014 dec. 17
 *      Author: vincze.attila
 */

#ifndef FILELOGGER_H_
#define FILELOGGER_H_

#include "Logger.h"

class FileLogger: public Logger {
public:
	virtual void log(const char*, const char*);
	FileLogger();
	virtual ~FileLogger();
};

#endif /* FILELOGGER_H_ */
