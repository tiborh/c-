#ifndef QUICK_UNION_H_INCLUDED
#define QUICK_UNION_H_INCLUDED

#include <cassert>
#include <vector>
#include <ostream>
#include "file_utils.hpp"

class quick_union {
public:
  quick_union(unsigned int s);  // initial size of vector
  quick_union(const char*);	// file name constructor
  ~quick_union() { delete(points); }
  void init();			// value set to index
  void connect(unsigned int a, unsigned int b);
  // two points are connected when they have the same root
  // the root is the point that points at itself, but others connect to it
  bool is_connected(unsigned int a, unsigned int b);
  unsigned int size() const { return points->size(); }
  unsigned int point_value(unsigned int i) const {
    assert(0 <= i && i < points->size());
    return points->at(i);
  }
  friend std::ostream& operator<<(std::ostream&, const quick_union&);
private:
  std::vector<unsigned int> *points;
  std::vector<unsigned int> get_root_and_size(unsigned int);
};

#endif //QUICK_UNION_H_INCLUDED

// Local Variables:
// mode: c++
// End:
