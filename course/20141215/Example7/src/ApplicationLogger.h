/*
 * ApplicationLogger.h
 *
 *  Created on: 2014 dec. 17
 *      Author: vincze.attila
 */

#ifndef APPLICATIONLOGGER_H_
#define APPLICATIONLOGGER_H_
#include "Logger.h"

class ApplicationLogger {
	int size;
	Logger* reg[10];
	ApplicationLogger();
public:
	void Attach(Logger*);
	void Detach(Logger*);
	void LogError(const char*);
	void LogInfo(const char*);

public:
	static ApplicationLogger& getInstance(){
		static ApplicationLogger instance;
		return instance;
	}
	virtual ~ApplicationLogger();
};

#endif /* APPLICATIONLOGGER_H_ */
