/*
 * FileLogger.cpp
 *
 *  Created on: 2014 dec. 17
 *      Author: vincze.attila
 */

#include "FileLogger.h"
#include <stdio.h>

FileLogger::FileLogger() {
	// TODO Auto-generated constructor stub

}

FileLogger::~FileLogger() {
	// TODO Auto-generated destructor stub
}

void FileLogger::log(const char * severity, const char* message) {
	FILE* fp;
	if ((fp = fopen("f:\\iqjb\\database4.dat", "w+")) == NULL) {
		printf("ERROR");
		return;
	}

	fprintf(fp,"%s\t%s\n", severity, message);
	fclose(fp);
}
