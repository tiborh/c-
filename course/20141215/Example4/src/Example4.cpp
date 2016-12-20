//============================================================================
// Name        : Example4.cpp
// Author      : VA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdlib.h>
#include <stdio.h>
#include "months.h"
#include "months.h"


int main() {
	char** months;
	getMonthNames(&months);
	months[8][0] = 'B';
	for (int var = 0; var < 12; ++var) {
		printf("%s\n", months[var]);
		free(months[var]);
	}
	free(months);
	return 0;
}
