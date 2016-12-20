//============================================================================
// Name        : Example9.cpp
// Author      : VA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Time.h"
using  std::cout;
using namespace TimeSpace;

int main() {
	Time t(1,2,3);
	Time* p = new Time;
	delete p;
	cout << *p;
	cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	return 0;
}
