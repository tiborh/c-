/*
 * ConsoleLogger.cpp
 *
 *  Created on: 2014 dec. 17
 *      Author: vincze.attila
 */

#include "ConsoleLogger.h"
#include <stdio.h>

ConsoleLogger::ConsoleLogger() {
	// TODO Auto-generated constructor stub

}

ConsoleLogger::~ConsoleLogger() {
	// TODO Auto-generated destructor stub
}

void ConsoleLogger::log(const char * severity, const char* message){
	printf("%s\t%s\n", severity, message);
}

