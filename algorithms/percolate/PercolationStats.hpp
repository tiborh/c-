#ifndef PERCOLATIONSTATS_H_INCLUDED
#define PERCOLATIONSTATS_H_INCLUDED

#include <vector>

class PercolationStats {
public:
  // perform trials independent experiments on an n-by-n grid:
  PercolationStats(unsigned int n, int trials);
  double mean();                          // sample mean of percolation threshold
  double stddev();                        // sample standard deviation of percolation threshold
  double confidenceLo();                  // low  endpoint of 95% confidence interval
  double confidenceHi();                  // high endpoint of 95% confidence interval
protected:

private:
  std::vector<unsigned int> tv;	// the values of the number of opened sites at percolation time.
};

#endif //PERCOLATIONSTATS_H_INCLUDED

// Local Variables:
// mode: c++
// End:
