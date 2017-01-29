#ifndef QUICK_FIND_H_INCLUDED
#define QUICK_FIND_H_INCLUDED

#include <cassert>
#include <vector>
#include <ostream>
#include "file_utils.hpp"

/**
 * Quick find: 
 * all that are connected have the same value
 * until first connection, points have their own index as value
 */
class quick_find {
public:
  quick_find(unsigned int s = 10); // points with no connection
  quick_find(const char*);	// file name constructor
  ~quick_find() { delete(points); }
  void init();			// value set to index
  // the value of 'b' and all connected to it change the value equal to the value of 'a':
  void connect(unsigned int a, unsigned int b);
  // two points are connected when their values are identical
  // in a connected graph, there is only one value in 'points'
  bool is_connected(unsigned int a, unsigned int b) { return points->at(a) == points->at(b); }
  unsigned int size() const { return points->size(); }
  unsigned int point_value(unsigned int i) const {
    assert(0 <= i && i < points->size());
    return points->at(i);
  }
  friend std::ostream& operator<<(std::ostream&, const quick_find&);
protected:
  std::vector<unsigned int> *points;
};

#endif //QUICK_FIND_H_INCLUDED

// Local Variables:
// mode: c++
// End:
