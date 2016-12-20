#include "Time.h"

std::ostream& operator<<(std::ostream& os, const Time& time) {
	return os << "(" << *time.hour << "," << *time.min << "," << *time.sec
			<< ")";
}

Time::Time() :
		hour(new int(0)), min(new int(0)), sec(new int(0)) {
}

Time::Time(int hour, int min, int sec) :
		hour(new int(hour)), min(new int(min)), sec(new int(sec)) {
}

Time::Time(const Time& t) :
		hour(new int(*t.hour)), min(new int(*t.min)), sec(new int(*t.sec)) {
}

Time::~Time() {
	delete hour;
	delete min;
	delete sec;
}

void Time::settimeparts(int actual) {
	*hour = (actual / 3600) % 24;
	actual %= 3600;
	*min = actual / 60;
	*sec = actual %= 60;
}

Time& Time::operator++() {
	int actual = *this;
	settimeparts(++actual);
	return *this;
}

Time::operator int() {
	return *hour * 3600 + *min * 60 + *sec;
}

const Time Time::operator++(int) {
	Time original = *this;
	int actual = *this;
	settimeparts(++actual);
	return original;
}

const Time Time::operator+(const Time& t) {
	int actual = (int) *this + (int) const_cast<Time&>(t);
	int h = (actual / 3600) % 24;
	actual %= 3600;
	int m = actual / 60;
	actual %= 60;
	int s = actual;
	return Time(h, m, s);
}

Time& Time::operator=(const Time& t) {
	if (this != &t) {
		*hour = *t.hour;
		*min = *t.min;
		*sec = *t.sec;
	}
	return *this;
}

Time* Time::operator->() {
	return this;
}

int& Time::operator[](int index) {
	switch (index) {
	case 0:
		return *hour;
	case 1:
		return *min;
	default:
		return *sec;
	}
}

int Time::operator==(const Time& t) {
	return *this == (int) const_cast<Time&>(t);
}

void* Time::operator new(size_t size) {
	static Time* pool[] = { ::new Time, ::new Time, ::new Time, ::new Time };
	static int actual = 0;
	return pool[actual++ % 3];
}

void Time::operator delete(void* p) {

}

