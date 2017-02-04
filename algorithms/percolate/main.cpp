#include <iostream>
#include <random>
#include <ctime>
#include "main.hpp"
#include "Percolation.hpp"
#include "PercolationStats.hpp"

using namespace std;

int main() {
  cout << "\nSimple tests:\n";
  cout << "===============\n";
  simple_tests();
  cout << "\nBasic Percolate tests:\n";
  cout << "========================\n";
  percolate_tests();
  cout << "\nRandom Open Percolate test:\n";
  cout << "=============================\n";
  random_open_percolate_test();
  cout << "\nPercolate Statistics tests:\n";
  cout << "=============================\n";
  percolate_stat_tests();
  return 0;
}

void percolate_stat_tests() {
  print_perc_results(4,4,5);
  print_perc_results(100,100,100);
  print_perc_results(200,200,100);
  cout << "Same again:\n";
  print_perc_results(200,200,100);
  print_perc_results(4,4,10000);
  print_perc_results(4,4,100000);
}

void print_perc_results(unsigned int rows, unsigned int cols, int trials) {
  PercolationStats a = PercolationStats(rows,cols);
  cout << "Case " << rows << " * " << cols << " nodes per " << trials << " trials:\n";
  cout << '\t' << a << '\n';
  cout << "\tSum: " << a.getsum() << '\n';
  cout << "\tMean: " << a.mean() << " (" << 100.0*(a.mean()/static_cast<double>(rows*cols)) << "%)\n";
  cout << "\tVariance: " << a.variance() << '\n';
  cout << "\tStandard Deviation: " << a.stddev() << '\n';
  cout << "\tConfidence (Low,High): ( " << a.confidenceLo() << ", " << a.confidenceHi() << " )\n";
}

void random_open_percolate_test() {
  int grid_size = 10;
  int nu_of_sites = grid_size * grid_size;
  Percolation a = Percolation(grid_size,grid_size);
  uniform_int_distribution<unsigned> u(0,grid_size-1);
  default_random_engine e(time(0));
  while(!a.percolates() && a.numberOfOpenedSites() <= nu_of_sites) {
    unsigned int row = u(e);
    unsigned int col = u(e);
    //cout << a << '\n';
    if (a.isBlocked(row,col))
	a.open(row,col);
  }
  cout << "number of opened sites: " << a.numberOfOpenedSites() << '\n';
  cout << a << '\n';
}

void simple_tests() {
  Percolation a = Percolation();
  cout << a << '\n';
  assert(!a.percolates());
  assert(a.numberOfOpenedSites() == 0);
  Percolation b = Percolation(5,10);
  assert(!b.isOpen(4,9));
  assert(!b.isFilled(4,9));
  assert(b.isBlocked(4,9));
  b.open(4,9);
  assert(b.isOpen(4,9));
  assert(!b.isFilled(4,9));
  assert(!b.isBlocked(4,9));
  assert(b.numberOfOpenedSites() == 1);
  assert(!b.percolates());
  
  cout << b << '\n';
  Percolation c = Percolation(10,5);
  cout << c << '\n';
  assert(!c.percolates());
}

void percolate_tests() {
  Percolation a = Percolation(1);
  assert(!a.percolates());
  a.open(0,0);
  cout << a << '\n';
  assert(a.percolates());
  assert(a.isFilled(0,0));
  cout << a << '\n';

  Percolation b = Percolation(2);
  assert(!b.percolates());
  b.open(0,0);
  assert(!b.percolates());
  cout << b << '\n';
  b.open(1,0);
  cout << b << '\n';
  assert(b.percolates());
  assert(b.isFilled(1,0));
  cout << b << '\n';

  Percolation c = Percolation(2,2);
  assert(!c.percolates());
  c.open(0,0);
  c.open(1,1);
  cout << c << '\n';
  assert(!c.percolates());
  c.open(0,1);
  cout << c << '\n';
  assert(c.percolates());
  cout << c << '\n';

  Percolation d = Percolation(3,3);
  d.open(2,2);
  d.open(1,2);
  d.open(1,1);
  d.open(1,0);
  assert(!d.percolates());
  cout << d << '\n';
  d.open(0,0);
  assert(d.percolates());
  cout << d << '\n';

  Percolation e = Percolation(4,4);
  e.open(0,1);
  assert(!e.percolates());
  e.open(1,2);
  assert(!e.percolates());
  e.open(1,1);
  assert(!e.percolates());
  e.open(2,1);
  assert(!e.percolates());
  e.open(2,2);
  assert(!e.percolates());
  e.open(2,3);
  assert(!e.percolates());
  e.open(3,3);
  assert(e.percolates());
  cout << e << '\n';
  assert(e.numberOfOpenedSites() == 7);
}
