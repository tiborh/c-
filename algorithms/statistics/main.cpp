#include <iostream>
#include <random>
#include <ctime>

#include "RunningStat.hpp"

const int MINNUM = 0;
const int MAXNUM = 1000;
const int NUM_OF_NUMS = 1000;

using namespace std;

int main() {
  uniform_int_distribution<unsigned> u(MINNUM,MAXNUM);
  default_random_engine e(time(0));
  RunningStat rs;
  
  for (int i = 0; i < NUM_OF_NUMS; ++i)
    rs.Push(u(e));

  cout << "Minimum number: " << MINNUM << '\n';
  cout << "Maximum number: " << MAXNUM << '\n';
  cout << "Type of distribution: uniform\n";
  cout << "Number of numbers generated: " << NUM_OF_NUMS << '\n';
  cout << "Mean: " << rs.Mean() << '\n';
  cout << "Variance: " << rs.Variance() << '\n';
  cout << "Standard Deviation: " << rs.StandardDeviation() << '\n';
  
  return 0;
}
