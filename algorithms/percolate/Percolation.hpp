#ifndef PERCOLATION_H_INCLUDED
#define PERCOLATION_H_INCLUDED

#include <vector>
#include <queue>
#include <cassert>
#include <ostream>
#include <iostream>

/**
 * The condition of percolation: an open path is available from the top to the bottom row.
 * A path is through horizontally or vertically neighbouring cells. No diagonal connection.
 * The current object is designed to examine how many cells are opened when the percolation happens.
 *
 * Field symbol explanation:
 * blocked: B
 * open:    _
 * full:    f
 */

const unsigned int DEFSIZE = 10;

class Percolation {
public:
  // create n-by-n grid, with all sites blocked:
  Percolation(unsigned int rows = DEFSIZE, unsigned int cols = DEFSIZE);
  virtual ~Percolation() {}
  // open site (row, col) if it is not open already: 
  void open(unsigned int, unsigned int);
  bool isBlocked(unsigned int row, unsigned int col) { // is site (row, col) blocked?
    assert(row < fsrows && col < fscols);
    return f[row][col] == s[0];
  }
  bool isOpen(unsigned int row, unsigned int col) {  // is site (row, col) open?
    assert(row < fsrows && col < fscols);
    return f[row][col] == s[1];
  }
  bool isOpen(std::pair<unsigned int, unsigned int> coords) {
    return isOpen(coords.first,coords.second);
  }
  bool isFilled(unsigned int row, unsigned int col) {  // is site (row, col) full?
    assert(row < fsrows && col < fscols);
    return f[row][col] == s[2];
  }
  bool isFilled(std::pair<unsigned int, unsigned int> coords) {
    return isFilled(coords.first,coords.second);
  }
  int numberOfOpenedSites() { return(nuOfOpened); }  // number of open sites
  bool percolates();                                 // does the system percolate?
  friend std::ostream& operator<<(std::ostream&, const Percolation&);
protected:

private:
  const char s[3] = {'B','_','f'};    // statuses: 0:Blocked, 1:Open, 2:Filled
  void fill(unsigned int row, unsigned int col) {	      // fill the space if open
    assert(row < fsrows && col < fscols);
    if (isOpen(row,col))
      f[row][col] = s[2];
    else
      std::cout << "Site: ( " << row << ", " << col << " ) is not open. (<row>,<col>)\n";
  }
  void fill(std::pair<unsigned int, unsigned int> coords) {
    fill(coords.first,coords.second);
  }
  void init();
  std::vector<std::vector<char>> f; // the field of points, a 2D matrix
  unsigned int fsrows;		    // the number of rows in the field
  unsigned int fscols;		    // the number of columns in the field
  unsigned int nuOfOpened;	    // the number of opened (not necessarily open) spaces
  std::queue<std::pair<unsigned int, unsigned int>> bag;
  void examine_element(std::pair<unsigned int, unsigned int>);
  std::queue<std::pair<unsigned int,unsigned int>> examine_neighbours(unsigned int, unsigned int);
  std::queue<std::pair<unsigned int,unsigned int>> examine_neighbours(std::pair<unsigned int,unsigned int> coords) {
    return examine_neighbours(coords.first,coords.second);
  }
  bool has_filled_neighbour(unsigned int, unsigned int);
  bool percolated;
};

#endif //PERCOLATION_H_INCLUDED

// Local Variables:
// mode: c++
// End:
