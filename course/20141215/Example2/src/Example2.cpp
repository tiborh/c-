//============================================================================
// Name        : Example2.cpp
// Author      : VA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string.h>
#include <stdio.h>


int isMirror(char word[])
{
	for(int i = 0, j = strlen(word) -1; i < j; ++i, --j )
	{
		if ( word[i]  != word[j]) return 0;
	}
	return 1;
}

int main() {

	printf("%s: %s","gorogll", isMirror("gorogll") ? "yes" : "no");

	return 0;
}
