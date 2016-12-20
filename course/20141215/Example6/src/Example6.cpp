//============================================================================
// Name        : Example6.cpp
// Author      : VA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "User.h"

using namespace std;

int main() {

	User user1(1, 2., "name 1");
	User user2 = user1;
	user1.setName("name 2");
	User user3;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
