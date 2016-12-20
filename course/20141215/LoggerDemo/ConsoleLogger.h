/*
 * ConsoleLogger.h
 *
 *  Created on: 2014 dec. 17
 *      Author: vincze.attila
 */

#ifndef CONSOLELOGGER_H_
#define CONSOLELOGGER_H_

#include "Logger.h"

class ConsoleLogger: public Logger {
public:
	virtual void log(const char*, const char*);
	ConsoleLogger();
	virtual ~ConsoleLogger();
};

#endif /* CONSOLELOGGER_H_ */
