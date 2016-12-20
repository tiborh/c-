#pragma once
#include <iostream>

class Time
{
	int* hour;
	int* min;
	int* sec;

public:
	void settimeparts(int);
	Time();
	Time(int, int, int);
	Time(const Time&);
	~Time();
	Time& operator++();
	const Time operator++(int);
	const Time operator+(const Time&);
	Time* operator->();
	Time& operator=(const Time&);
	operator int();
	int& operator[](int);
	int operator==(const Time&);
	void* operator new(size_t size);
	void operator delete (void*);
	friend
	std::ostream& operator<<(std::ostream& os, const Time& time);
};

std::ostream& operator<<(std::ostream& os, const Time& time);
