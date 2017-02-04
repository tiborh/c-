#include "PercolationStats.hpp"
#include "Percolation.hpp"

#include <random>
#include <ctime>

PercolationStats::PercolationStats(unsigned int n, int trials):avg(0),var(0),sd(0) {
  tv = std::vector<unsigned int>(trials);
  sum = 0;
  sumsq = 0;
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
    unsigned int nu_oped = a.numberOfOpenedSites();
    tv.at(i) = nu_oped;
    sum += nu_oped;
    sumsq += nu_oped * nu_oped;
  }
}

double PercolationStats::mean() {
  avg = 0.0;
  if (sum > 0.0)
    avg =  sum / static_cast<double>(tv.size());
  return avg;
}

double PercolationStats::variance() {
  double the_mean = avg > 0.0 ? avg : mean();
  double sum_of_diffs = 0.0;
  for (auto it = tv.begin(); it != tv.end(); ++it)
    sum_of_diffs += (static_cast<double>(*it) - the_mean) * (static_cast<double>(*it) - the_mean);
  var = sum_of_diffs / static_cast<double>(tv.size() - 1);
  return var;
}

double PercolationStats::stddev() {
  sd = 0.0;
  if (var > 0.0 && tv.size() > 1)
    sd = sqrt(var);
  return sd;
}

double PercolationStats::confidenceLo() {
  double my_sd = sd > 0.0 ? sd : stddev();
  return avg - (1.96*my_sd)/sqrt(tv.size());
}

double PercolationStats::confidenceHi() {
  double my_sd = sd > 0.0 ? sd : stddev();
  return avg + (1.96*my_sd)/sqrt(tv.size());
}

std::ostream& operator<<(std::ostream& os, const PercolationStats& ps) {
  os << "( ";
  for (auto it = ps.tv.begin(); it != ps.tv.end(); ++it)
    os << *it << ", ";
  os << " )";
  return os;
}
