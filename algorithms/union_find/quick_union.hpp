#ifndef QUICK_UNION_H_INCLUDED
#define QUICK_UNION_H_INCLUDED

#include "quick_find.hpp"

class quick_union: public quick_find {
public:
  quick_union(unsigned int s):quick_find(s) {}
  quick_union(const char*);
  void connect(unsigned int, unsigned int);
  bool is_connected(unsigned int, unsigned int);
};

#endif //QUICK_UNION_H_INCLUDED

// Local Variables:
// mode: c++
// End:
