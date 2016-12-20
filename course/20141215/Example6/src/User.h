/*
 * User.h
 *
 *  Created on: 2014 dec. 16
 *      Author: vincze.attila
 */

#ifndef USER_H_
#define USER_H_
#include <string.h>

class User {
private:
	int* age;
	char* name;
	double salary;
public:
	int getAge(){
		return *age;
	}
	void setAge(int age) {
		*this->age = age;
	}
	char* getName(){
		char* ret = new char[strlen(name) + 1];
		strcpy(ret, name);
		return ret;
	}
	void setName(const char * name) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	double getSalary() const{
		return salary;
	}
	void setSalary(double salary){
		this->salary = salary;
	}


	User();
	User(int, double, const char*);
	User(const User&);
	virtual ~User();
};

#endif /* USER_H_ */
