#include "MyArray.h"

#include <stdlib.h>
#include <cstdio>
#include <cstring>

#include "Address.h"
#include "Employee.h"
#include "Name.h"
#include "PersistentEmployee.h"

Employee* container = NULL;
int size = 0;
int capacity = 0;

void insert(Employee* employee) {
	if (!container) {
		capacity = 2 * size + 1;
		container = (Employee*) malloc(capacity * sizeof(Employee));
	} else if (size == capacity) {
		capacity = 2 * size + 1;
		Employee* newContainer = (Employee*) calloc(capacity, sizeof(Employee));
		for (int i = 0; i < size; ++i) {
			(newContainer + i)->title = (container + i)->title;
			(newContainer + i)->salary = (container + i)->salary;
			(newContainer + i)->name.firstName =
					(container + i)->name.firstName;
			(newContainer + i)->name.lastName = (container + i)->name.lastName;
			(newContainer + i)->address = (container + i)->address;
		}
		free(container);
		container = newContainer;
	}

	(container + size)->title = (char*) calloc(strlen(employee->title) + 1,
			sizeof(char));
	strcpy((container + size)->title, employee->title);
	(container + size)->salary = employee->salary;

	(container + size)->name.firstName = (char*) calloc(strlen(employee->name.firstName) + 1,
			sizeof(char));
	strcpy((container + size)->name.firstName, employee->name.firstName);
	(container + size)->name.lastName = (char*) calloc(strlen(employee->name.lastName) + 1,
				sizeof(char));
		strcpy((container + size)->name.lastName, employee->name.lastName);


	(container + size)->address = (Address*) calloc(1, sizeof(Address));
	(container + size)->address->zip = employee->address->zip;
	(container + size)->address->street = (char*) calloc(
			strlen(employee->address->street) + 1, sizeof(char));
	strcpy(container->address->street, employee->address->street);
	(container + size)->address->city = (char*) calloc(
			strlen(employee->address->city) + 1, sizeof(char));
	strcpy((container + size)->address->city, employee->address->city);

	size++;
}

void clear() {
	for (int i = 0; i < size; ++i) {
		free((container + i)->title);
		free(container[i].address->city);
		free(container[i].address->street);
		free(container[i].name.firstName);
		free(container[i].name.lastName);
		free(container[i].address);

	}
	free(container);
	capacity = 0;
	size = 0;
	container = NULL;
}

int getSize() {
	return size;
}

void insert2(PersistentEmployee*);

void load()
{
	FILE* fp;
	if (!(fp = fopen("f:\\iqjb\\database3.dat", "rb")))
	{
		printf("ERROR");
		return;
	}
	fseek(fp, 0L, SEEK_END);
	int numberOfEmployees = ftell(fp)/sizeof(PersistentEmployee);
	fseek(fp, 0L, SEEK_SET);

	for(int i = 0; i < numberOfEmployees; ++i)
	{
		PersistentEmployee persistentEmployee;
		fread(&persistentEmployee, sizeof(persistentEmployee), 1, fp);
		insert2(&persistentEmployee);
	}

}


void insert2(PersistentEmployee *persistentEmployee)
{
	Employee employee;
	employee.title = persistentEmployee->title;
	employee.salary = persistentEmployee->salary;

	employee.name.firstName = persistentEmployee->firstName;
	employee.name.lastName = persistentEmployee->lastName;

	Address address;
	address.zip = persistentEmployee->zip;
	address.city = persistentEmployee->city;
	address.street = persistentEmployee->street;

	employee.address = &address;

	insert(&employee);
}

void save()
{
	FILE* fp;
	if( (fp = fopen("f:\\iqjb\\database3.dat", "wb")) == NULL )
	{
		printf("ERROR");
		return;
	}

	for(int i = 0 ; i < size ; ++i)
	{
		PersistentEmployee persistentEmployee;
		strcpy_s(persistentEmployee.title, 100, container[i].title);
		persistentEmployee.salary = container[i].salary;

		persistentEmployee.zip = container[i].address->zip;
		strcpy_s(persistentEmployee.street, 100, container[i].address->street);
		strcpy_s(persistentEmployee.city, 100, container[i].address->city);

		strcpy(persistentEmployee.firstName, container[i].name.firstName);
		strcpy(persistentEmployee.lastName, container[i].name.lastName);

		fwrite(&persistentEmployee, sizeof(PersistentEmployee), 1, fp);
	}
	fclose(fp);
}

