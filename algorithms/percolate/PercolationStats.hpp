#ifndef PERCOLATIONSTATS_H_INCLUDED
#define PERCOLATIONSTATS_H_INCLUDED

#include <vector>
#include <ostream>

class PercolationStats {
public:
  // perform trials independent experiments on an n-by-n grid:
  PercolationStats(unsigned int n, int trials);
  double mean();                          // sample mean of percolation threshold
  double variance();
  double stddev();                        // sample standard deviation of percolation threshold
  double confidenceLo();                  // low  endpoint of 95% confidence interval
  double confidenceHi();                  // high endpoint of 95% confidence interval
  double getsum() const { return sum; }
  double getsumsq() const { return sumsq; }
  friend std::ostream& operator<<(std::ostream&, const PercolationStats&);
protected:

private:
  unsigned long long sum;
  unsigned long long sumsq;
  double avg;
  double var;
  double sd;
  std::vector<unsigned int> tv;	// the values of the number of opened sites at percolation time.
};

#endif //PERCOLATIONSTATS_H_INCLUDED

// Local Variables:
// mode: c++
// End:
