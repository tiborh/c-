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
#include <vector>
#include <iostream>

using namespace std;

inline void sum(int& p, int n, vector<int> d)
{
  int i;
  p = 0;

  for(i = 0; i < n; ++i)
    p = p + d.at(i);
}

int main()
{
  const int N = 40;
  int i;
  int accum = 0;
  vector<int> data(N);

  for(i = 0; i < N; ++i)
    data.at(i) = i;

  sum(accum, N, data);

  cout << "sum is " << accum << endl;

  return 0;
}
