#ifndef UNION_FIND_H_INCLUDED
#define UNION_FIND_H_INCLUDED

#include <cassert>
#include <vector>
#include <ostream>

class union_find {
public:
  union_find(unsigned int);
  union_find(const char*);
  ~union_find() { delete(points); }
  void init();
  void connect(unsigned int a, unsigned int b);
  bool is_connected(unsigned int a, unsigned int b) { return points->at(a) == points->at(b); }
  unsigned int size() const { return points->size(); }
  unsigned int point_value(unsigned int i) const {
    assert(0 <= i && i < points->size());
    return points->at(i);
  }
  friend std::ostream& operator<<(std::ostream&, const union_find&);
private:
  std::vector<unsigned int> *points;
};

#endif //UNION_FIND_H_INCLUDED

// Local Variables:
// mode: c++
// End:
