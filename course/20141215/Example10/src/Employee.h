/*
 * Employee.h
 *
 *  Created on: 2014 dec. 19
 *      Author: vincze.attila
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string>
#include <iostream>

class Employee {
	static int nextId;
public:
	int id;
	std::string name;
	double salary;

	Employee();
	virtual ~Employee();
};

std::ostream& operator << (std::ostream& os, const Employee& employee);

#endif /* EMPLOYEE_H_ */
