/*
 * EmployeeRepository.cpp
 *
 *  Created on: 2014 dec. 19
 *      Author: vincze.attila
 */

#include "EmployeeRepository.h"
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;
using  namespace std::placeholders;

EmployeeRepository::EmployeeRepository() {
	// TODO Auto-generated constructor stub

}

EmployeeRepository::~EmployeeRepository() {
	// TODO Auto-generated destructor stub
}

void EmployeeRepository::add(Employee emp){
	add2(emp);
}

void EmployeeRepository::add2(Employee emp){
	database.push_back(emp);
}

void EmployeeRepository::add3(){
	
}

void EmployeeRepository::add(std::vector<Employee> emp){

	std::copy(emp.begin(), emp.end(), back_inserter(database));

	for(vector<Employee>::iterator i = emp.begin(); i != emp.end(); ++i)
	{
		add(*i);
	}


	std::for_each(emp.begin(), emp.end(), std::bind(&EmployeeRepository::add2, this, _1));
	cout << database.size() << std::endl;
}

vector<Employee> EmployeeRepository::findAll(){
	return database;
}

vector<Employee> EmployeeRepository::findById(int id){
	vector<Employee> ret;
	ret.push_back(* 
		
		find_if(database.begin(), database.end(),
		//MyFindIf(id);
		[id](Employee& emp){return emp.id == id;}
	
	)
		
		);
	return ret;
}