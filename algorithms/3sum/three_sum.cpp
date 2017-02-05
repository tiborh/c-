#include <iostream>
#include <chrono>
#include <cmath>
#include "utils.hpp"

using namespace std;
using namespace std::chrono;

int three_sum(std::multiset<int>);
int three_sum_faster(std::multiset<int>);

int main(int argc, char** argv) {
  array<int,3> invals = proc_input(argc,argv);
  int num = invals.at(0);
  int min = invals.at(1);
  int max = invals.at(2);
  cout << "num: " << num << '\n';
  cout << "min: " << min << '\n';
  cout << "max: " << max << '\n';

  multiset<int> the_nums = make_set(num,min,max);
  for (auto it = the_nums.begin(); it != the_nums.end(); ++it)
    cout << *it << ", ";
  cout << '\n';

  double ert = 3.97 * pow(10,-5) * pow(num,2.999);
  cout << "Estimated running time (for cubic): " << ert << " milliseconds\n";
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  //int zerosums = three_sum(the_nums);
  int zerosums = three_sum_faster(the_nums);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  auto durmilli = duration_cast<milliseconds>( t2 - t1 ).count();
  cout << "Actual duration: " << durmilli << " (milliseconds) with quadratic logarithmic\n";
  cout << "The number of zero sums: " << zerosums << '\n';
  
  return 0;
}

int three_sum(std::multiset<int> inset) {
  int zerosums = 0;
  for (auto ita = inset.begin(); ita != inset.end(); ++ita)
      for (auto itb = inset.begin(); itb != inset.end(); ++itb)
	  for (auto itc = inset.begin(); itc != inset.end(); ++itc)
	    if (*ita + *itb + *itc == 0)
	      ++zerosums;
  return zerosums;
}

int three_sum_faster(std::multiset<int> inset) {
  int zerosums = 0;
  for (auto ita = inset.begin(); ita != inset.end(); ++ita)
    for (auto itb = inset.begin(); itb != inset.end(); ++itb) {
        int twosum = *ita + *itb;
	int to_search4 = 0 - twosum;
	auto itc = inset.find(to_search4);
	if (itc != inset.end())
	  ++zerosums;
    }
  return zerosums;
}
