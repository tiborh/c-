#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Address.h"
#include "Name.h"

typedef struct
{
	char* title;
	double salary;
	Name name;
	Address* address;
} Employee;

#endif
