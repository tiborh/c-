/*
 * EmployeeRepository.cpp
 *
 *  Created on: 2014 dec. 19
 *      Author: vincze.attila
 */

#include "EmployeeRepository.h"
#include <algorithm>
#include <functional>
using namespace std;
using  std::placeholders;

EmployeeRepository::EmployeeRepository() {
	// TODO Auto-generated constructor stub

}

EmployeeRepository::~EmployeeRepository() {
	// TODO Auto-generated destructor stub
}

void EmployeeRepository::add(Employee emp){
	database.push_back(emp);
}

void EmployeeRepository::add2(Employee emp){
	database.push_back(emp);
}

void EmployeeRepository::add(std::vector<Employee> emp){
	std::for_each(emp.begin(), emp.end(), std::bind(&EmployeeRepository::add2, *this,  _1)(emp) );
}
