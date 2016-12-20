#pragma once
#include <iostream>



namespace TimeSpace{

class Time
{
	int* hour;
	int* min;
	int* sec;
	void setparts(int);

public:
	Time();
	Time(int, int, int);
	Time(const Time&);
	~Time();

	Time& operator ++();
	operator int();
	const Time operator++(int);
	const Time operator+(const Time&);
	int operator==(const Time&);
	int& operator[](int);
	void * operator new (size_t size);
	void operator delete(void*);


	friend
	std::ostream& operator<<(std::ostream& os, const TimeSpace::Time& time);




};

std::ostream& operator<<(std::ostream& os, const TimeSpace::Time& time);


}



