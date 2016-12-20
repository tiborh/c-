//============================================================================
// Name        : Example8.cpp
// Author      : VA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Time.h"
using namespace std;

int main() {
	Time time(1, 59, 59);
	//time->settimeparts(12);
	++++++time;
	time++;
	cout << time << endl;

	Time* t = new Time(1, 2, 3);
	t = new Time(1, 2, 3);
	t = new Time(1, 2, 3);
	t = new Time(1, 2, 3);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
