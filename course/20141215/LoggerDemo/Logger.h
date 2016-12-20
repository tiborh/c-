/*
 * Logger.h
 *
 *  Created on: 2014 dec. 17
 *      Author: vincze.attila
 */

#ifndef LOGGER_H_
#define LOGGER_H_

class Logger {

public:
	static const char * Info;
	static const char * Error;
	void LogError(const char* message){
		log(Info, message);
	}
	void LogInfo(const char* message){
		log(Error, message);
	}
	virtual void log(const char*, const char*) = 0;
	Logger();
	virtual ~Logger();
};

#endif /* LOGGER_H_ */
