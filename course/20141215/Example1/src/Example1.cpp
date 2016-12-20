//============================================================================
// Name        : Example1.cpp
// Author      : VA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>

int main() {
	int t[3] = {0};
	int index = -1;
	int third = -1;
	for(;;)
	{
		scanf("%d", &t[index = (++index)%3]);
		if (!t[index]) break;
		if (index == 2) third = 1;
		if (third && (t[index] ==
				(t[(index + 1)%3] + t[(index + 2)%3])))
			printf("%d\n", t[index]);
	}
	return 0;
}
