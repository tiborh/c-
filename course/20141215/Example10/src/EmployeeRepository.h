/*
 * EmployeeRepository.h
 *
 *  Created on: 2014 dec. 19
 *      Author: vincze.attila
 */

#ifndef EMPLOYEEREPOSITORY_H_
#define EMPLOYEEREPOSITORY_H_
#include <vector>
#include "Employee.h"
class EmployeeRepository {
	std::vector<Employee> database;
	void add2(Employee emp);
public:

	void add(Employee emp);

	void add(std::vector<Employee> emp);

	EmployeeRepository();
	virtual ~EmployeeRepository();
};

#endif /* EMPLOYEEREPOSITORY_H_ */
