//============================================================================
// Name        : Example3.cpp
// Author      : VA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include "Operation.h"
#include "Add.h"
#include "Multiply.h"
#include "Condition.h"
#include "Positive.h"
#include "Negative.h"
#include <algorithm>
#include <iostream>

int accum(int init, int t[], int length) {
	for (int i = 0; i < length; ++i) {
		init += *(t + i);
	}
	return init;
}

int accum1(int init, int t[], int length, int (*fp)(int, int)) {
	for (int i = 0; i < length; ++i) {
		init = fp(init, *(t + i));
	}
	return init;
}

int multiply(int a, int b) {
	return a * b;
}

int accum(int init, int* t, int length, Operation* operation) {
	for (int i = 0; i < length; ++i) {
		init = (*operation)(init, *(t + i));
	}
	return init;
}

int accum(int init, int* t, int length, Operation* operation,
		Condition& condition) {
	for (int i = 0; i < length; ++i) {
		if (condition(*(t + i))) {
			init = (*operation)(init, *(t + i));
		}
	}
	return init;
}

int accum(int* begin, int* end, int init, Operation& operation,
		Condition& condition) {
	for (; begin != end; ++begin) {
		if (condition(*begin)) {
			init = operation(init, *begin);
		}
	}
	return init;
}

template<typename T, typename I, typename O, typename C>
T accumt(I begin, I end, T init, O operation, C condition) {
	for (; begin != end; ++begin) {
		if (condition(*begin)) {
			init = operation(init, *begin);
		}
	}
	return init;
}

template<typename T = int>
struct MyPrint {
	void operator()(T arg) {
		std::cout << arg << std::endl;
	}
};

struct MyPrint2 {
	void operator()(int arg) {
		std::cout << arg << std::endl;
	}
};

template<typename T>
void MyFPrint(T arg) {
	std::cout << arg << std::endl;
};

template <typename T>
struct MyAverage{
	T sum;
	int count;
	MyAverage():sum(T()), count(0){}
	void operator()(T arg){
		std::cout << sum << std::endl;
		sum+=arg;
		count++;
	}
	double average(){
		return static_cast<double>(sum) / static_cast<double>(count);
	}
	operator double(){
		return static_cast<double>(sum) / static_cast<double>(count);
	}
};

int main() {
	int a[] = { -1, 2, 3, 4, 5, 6, 7, 8, 9, -10 };
	//printf("%d\n", accum1(1, a, 10, multiply));

	Add add;
	Multiply multiply1;
	Positive positive;
	Negative negative;
	printf("%d\n", accum(1, a, 10, &add));
	printf("%d\n", accum(1, a, 10, &multiply1));

	printf("%d\n", accum(1, a, 10, &add, positive));
	printf("%d\n", accum(1, a, 10, &multiply1, negative));

	printf("%d\n",
			accumt<int, int*, Multiply, Negative>(a, a + 10, 1, multiply1,
					negative));

	printf("%.3f",static_cast<double>( std::for_each(a, a + 10, MyAverage<int>())));

	return 0;
}
