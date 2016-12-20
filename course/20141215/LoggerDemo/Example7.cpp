//============================================================================
// Name        : Example7.cpp
// Author      : VA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "ApplicationLogger.h"
#include "FileLogger.h"
#include "ConsoleLogger.h"

int main() {
	Logger* consoleLogger = new ConsoleLogger();
	Logger* fileLogger = new FileLogger();
	ApplicationLogger::getInstance()->Attach(consoleLogger);
	ApplicationLogger::getInstance()->Attach(fileLogger);
	ApplicationLogger::getInstance()->LogError("my error");
	ApplicationLogger::getInstance()->LogInfo("my info");
	ApplicationLogger::getInstance()->Detach(fileLogger);
	ApplicationLogger::getInstance()->LogInfo("my info 2");
	delete consoleLogger;
	delete fileLogger;

	return 0;
}
