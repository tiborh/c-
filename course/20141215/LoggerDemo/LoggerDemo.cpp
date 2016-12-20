// LoggerDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Employee.h"
#include "EmployeeRepository.h"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	EmployeeRepository repository;
	Employee e1;
	e1.name = "a";
	e1.salary = 100.;
	Employee e2;
	e2.name = "b";
	e2.salary = 200.;
	Employee e3;
	e3.name = "c";
	e3.salary = 300.;

	repository.add(e3);

	vector<Employee> emps;
	emps.push_back(e1);
	emps.push_back(e2);
	

	repository.add(emps);
	vector<Employee> ret = repository.findById(1);
	copy(ret.begin(), ret.end(), ostream_iterator<Employee>(std::cout, "\n"));


	return 0;
}

