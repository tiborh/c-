#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <array>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cassert>

using namespace std;
using namespace std::chrono;

const int NUM = 100;
const int MAX = 100;
const int MIN = -MAX;

std::vector<int> make_array(int num=NUM,int min=MIN, int max=MAX);
std::array<int,3> proc_input(int, char**);
int three_sum(std::vector<int>);

int main(int argc, char** argv) {
  array<int,3> invals = proc_input(argc,argv);
  int num = invals.at(0);
  int min = invals.at(1);
  int max = invals.at(2);
  cout << "num: " << num << '\n';
  cout << "min: " << min << '\n';
  cout << "max: " << max << '\n';

  vector<int> the_nums = make_array(num,min,max);
  for (auto it = the_nums.begin(); it != the_nums.end(); ++it)
    cout << *it << ", ";
  cout << '\n';

  double ert = 3.97 * pow(10,-5) * pow(num,2.999);
  cout << "Estimated running time: " << ert << " milliseconds\n";
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  int zerosums = three_sum(the_nums);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  auto durmilli = duration_cast<milliseconds>( t2 - t1 ).count();
  cout << "Actual duration: " << durmilli << " (milliseconds)\n";
  cout << "The number of zero sums: " << zerosums << '\n';
  
  return 0;
}

std::array<int,3> proc_input(int argc, char **argv) {
  int num = NUM;
  int min = MIN;
  int max = MAX;
  int readsuccess = 0, tempnum = 0;
  if (argc > 2) {
    readsuccess = sscanf(argv[2],"%d",&tempnum);
    if (readsuccess > 0)
      max = tempnum;
    tempnum = 0;
    assert(max > 0);
    min = -max;
  }
  if (argc > 1) {
    readsuccess = sscanf(argv[1],"%d",&tempnum);
    if (readsuccess > 0)
      num = tempnum;
  }

  array<int,3> outarr = {num,min,max};
  
  return outarr;
}

std::vector<int> make_array(int num, int min, int max) {
  std::vector<int> outvect(num);
  uniform_int_distribution<int> u(min,max);
  default_random_engine e(time(0));

  for(int i = 0; i < num; ++i)
    outvect.at(i) = u(e);

  return(outvect);
}

int three_sum(std::vector<int> invect) {
  int zerosums = 0;
  for (auto ita = invect.begin(); ita != invect.end(); ++ita)
      for (auto itb = invect.begin(); itb != invect.end(); ++itb)
	  for (auto itc = invect.begin(); itc != invect.end(); ++itc)
	    if (*ita + *itb + *itc == 0)
	      ++zerosums;
  return zerosums;
}
