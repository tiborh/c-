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
	void add3();
public:

	void add(Employee emp);

	void add(std::vector<Employee> emp);
	std::vector<Employee> findAll();
	std::vector<Employee> findById(int);

	EmployeeRepository();
	virtual ~EmployeeRepository();
};


struct MyFindIf {
	int id;
	MyFindIf(int id): id(id){}
	bool operator()(const Employee& emp){
		return emp.id == id;
};
#endif /* EMPLOYEEREPOSITORY_H_ */
