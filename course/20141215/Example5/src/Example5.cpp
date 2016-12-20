//============================================================================
// Name        : Example5.cpp
// Author      : VA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Employee.h"
#include "MyArray.h"
#include <stdio.h>

using namespace std;

int main() {
	Employee employee1;
	employee1.title = "title 1";
	employee1.salary = 100;

	employee1.name.firstName = "first name 1";
	employee1.name.lastName = "last name 1";

	Address address1;
	address1.zip = 1234;
	address1.city = "city 1";
	address1.street = "street 1";

	employee1.address = &address1;

	insert(&employee1);

	Employee employee2;
	employee2.title = "title 2";
	employee2.salary = 200;

	employee2.name.firstName = "first name 2";
	employee2.name.lastName = "last name 2";

	Address address2;
	address2.zip = 1234;
	address2.city = "city 2";
	address2.street = "street 2";

	employee2.address = &address2;

	insert(&employee2);

	save();
	clear();
	load();
	printf("%d", getSize());


	return 0;
}
