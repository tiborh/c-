/*
 * ApplicationLogger.cpp
 *
 *  Created on: 2014 dec. 17
 *      Author: vincze.attila
 */

#include "ApplicationLogger.h"
#include <algorithm>
#include <functional>

using namespace std;

ApplicationLogger::ApplicationLogger() :
		size(-1) {
	// TODO Auto-generated constructor stub
	for (int var = 0; var < 10; ++var) {
		reg[var] = 0;
	}

}

ApplicationLogger::~ApplicationLogger() {
	// TODO Auto-generated destructor stub
}

void ApplicationLogger::Attach(Logger* logger) {
	int found = 0;
	for (int var = 0; var < 10; ++var) {
		if (reg[var] == logger) {
			found = 1;
		}
	}
	if (!found) {
		reg[++size] = logger;
	}

}

void ApplicationLogger::Detach(Logger* logger) {
	for (int var = 0; var < 10; ++var) {
		if (reg[var] == logger) {
			reg[var] = 0;
		}
	}
}

void ApplicationLogger::LogError(const char* message) {
	for (int var = 0; var < 10; ++var) {
		reg[var]->LogError(message);
	}
}

void ApplicationLogger::LogInfo(const char* message) {
	for (int var = 0; var < 10; ++var) {
		reg[var]->LogInfo(message);
	}
}
