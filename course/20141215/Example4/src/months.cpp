/*
 * months.cpp
 *
 *  Created on: 2014 dec. 15
 *      Author: vincze.attila
 */
#include "months.h"
#include <string.h>
#include <stdlib.h>

void getMonthNames(char*** ret) {
	*ret = (char**) malloc(sizeof(char*) * 12);
	const char* names[] = { "jan", "febr", "march", "apr", "may", "june", "july", "aug", "sept", "oct", "nov", "dec" };
	for (int var = 0; var < 12; ++var) {
		*(*ret + var) = (char*) malloc( (strlen(names[var]) + 1) * sizeof(char) );
		strcpy(*(*ret + var), names[var]);
	}
}


