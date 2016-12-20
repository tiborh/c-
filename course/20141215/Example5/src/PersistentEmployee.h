#ifndef PERSISTENTEMPLOYEE_H
#define PERSISTENTEMPLOYEE_H

typedef struct
{
	char title[50];
	double salary;
	int zip;
	char street[100];
	char city[100];
	char firstName[100];
	char lastName[100];
} PersistentEmployee;

#endif
