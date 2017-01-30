#include "PercolationStats.hpp"
#include "Percolation.hpp"

#include <random>
#include <ctime>

PercolationStats::PercolationStats(unsigned int n, int trials) {
  tv = std::vector<unsigned int>(trials);
  std::uniform_int_distribution<unsigned> u(0,n-1);
  std::default_random_engine e(time(0));
  for (int i = 0; i < trials; ++i) {
    Percolation a = Percolation(n,n);
    while(!a.percolates()) {
      unsigned int row = u(e);
      unsigned int col = u(e);
      //cout << a << '\n';
      if (a.isBlocked(row,col))
	a.open(row,col);
    }
    tv.at(i) = a.numberOfOpenedSites();
  }
}

double PercolationStats::mean() {
  unsigned long long int sum_of_percs = 0;
  for(auto it = tv.begin(); it != tv.end(); ++it)
    sum_of_percs += *it;
  return sum_of_percs / static_cast<double>(tv.size());
}
