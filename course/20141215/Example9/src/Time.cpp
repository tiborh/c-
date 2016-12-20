#include "Time.h"
#include  <iostream>
using std::ostream;

namespace TimeSpace {
Time::Time() :
		hour(new int(0)), min(new int(0)), sec(new int(0)) {
	std::cout << "Time::Time()" << std::endl;
}

Time::Time(int hour, int min, int sec) :
		hour(new int(hour)), min(new int(min)), sec(new int(sec)) {
}

Time::Time(const Time& t) :
		hour(new int(*t.hour)), min(new int(*t.min)), sec(new int(*t.sec)) {
}

Time::~Time() {
	std::cout << "Time::~Time()" << std::endl;
	delete hour;
	delete min;
	delete sec;
}

void Time::setparts(int actual) {
	*hour = actual / 3600;
	actual %= 3600;
	*min = actual / 60;
	actual %= 60;
	*sec = actual;
}

Time& Time::operator ++() {
	int actual = *this;
	setparts(++actual);
	return *this;
}

Time::operator int() {
	return *hour * 60 * 60 + *min * 60 + *sec;
}

const Time Time::operator++(int) {
	Time orig = *this;
	int actual = *this;
	setparts(++actual);
	return orig;
}

const Time Time::operator+(const Time& other) {
	int actual =

	static_cast<int>(*this) + static_cast<int>(const_cast<Time&>(other));
	int h = actual / 3600;
	actual %= 3600;
	int m = actual / 60;
	actual %= 60;
	int s = actual;
	return Time(h, m, s);
}
int Time::operator==(const Time& other) {
	return static_cast<int>(*this) == static_cast<int>(const_cast<Time&>(other));
}

int& Time::operator[](int i) {
	switch (i) {
	case 0:
		return *hour;
	case 1:
		return *min;
	default:
		return *sec;
	}
}


void* Time::operator new(size_t size){
	static Time* pool[] =
	{::new Time, ::new Time, ::new Time};
	static int actual = 0;
	return pool[actual++%3];
}


void Time::operator delete(void* p){

	std::cout << "Time::operator delete(void* p)" << std::endl;
	::delete p;
}

std::ostream& operator<<(std::ostream& os, const TimeSpace::Time& time) {
	return os
			<< "(" << *time.hour << "," << *time.min << "," << *time.sec
			<< ")";
}

}

