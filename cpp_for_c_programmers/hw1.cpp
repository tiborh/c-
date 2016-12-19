// Title: summing the elements of a vector
// Author: tiborh
// Date: 2016-12-19
// Topic: Peer-graded Assignment: Homework 1: Convert a C program to C++
// Course: https://www.coursera.org/learn/c-plus-plus-a/

// Task:                                  Example:
// =========================================================================
// Convert this program to C++            .c -> .cpp
// change to C++ io:                      stdio.h -> iostream
// change to one line comments            // blah blah blah
// change defines of constants to const   const int N = 40;
// change array to vector<>               vector<int> data(N); vector.at(i)
// inline any short function              inline void sum(int& p, ...
//
// Additional changes:
// =========================================================================
// names of the variables have been change to make them more meaningful
// iteration variable i is encapsulated in the for loops now
// modifications in sum function
//    introductory comments have been added
//    generic to practise that material too
//    no side effect but a returned value
//    taking an immutable vector
//
#include <vector>
#include <iostream>

using namespace std;

// to sum the elements of a vector
// the_sum: the sum of the vector elements
// the_data: the vector storing the elements to sum
// returns the sum of elements. No side effect
template<class T>
inline T sum(T the_sum, const vector<T>& the_data) {
  the_sum = 0;
  int data_length = the_data.size();
  
  for(int i = 0; i < data_length; ++i)
    the_sum += the_data.at(i);

  return(the_sum);
}

int main() {
  const int NUM_OF_DATA = 40;
  int accum = 0;
  vector<int> data(NUM_OF_DATA);

  for(int i = 0; i < NUM_OF_DATA; ++i)
    data.at(i) = i;

  accum = sum<int>(accum, data);

  cout << "sum is " << accum << endl;

  return 0;
}
