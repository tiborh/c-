/*
 * User.cpp
 *
 *  Created on: 2014 dec. 16
 *      Author: vincze.attila
 */

#include "User.h"

#include <cstring>

User::User() :
		age(0), salary(0), name(0) {

}

User::~User() {
	delete age;
	delete[] name;
}

User::User(int age, double salary, const char* name) :
		age(new int(age)), salary(salary), name(new char[strlen(name) + 1]) {
	strcpy(this->name, name);
}

User::User(const User& cc) :
		age(new int(*cc.age)), salary(cc.salary), name(
				new char[strlen(cc.name) + 1]) {
	strcpy(this->name, cc.name);
}

