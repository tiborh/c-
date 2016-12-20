/*
 * Employee.cpp
 *
 *  Created on: 2014 dec. 19
 *      Author: vincze.attila
 */

#include "Employee.h"

int Employee::nextId = 0;

std::ostream& operator << (std::ostream& os, const Employee& employee){
	return os << "(" << employee.id << "," << employee.name << "," << employee.salary << ")" ;
}

Employee::Employee()
:id(++nextId) {
	// TODO Auto-generated constructor stub
}

Employee::~Employee() {
	// TODO Auto-generated destructor stub
}

