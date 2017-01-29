#ifndef QUICK_UNION_LAZY_H_INCLUDED
#define QUICK_UNION_LAZY_H_INCLUDED

#include "quick_find.hpp"

class quick_union_lazy: public quick_find {
public:
  quick_union_lazy(unsigned int s = 10):quick_find(s) {}
  quick_union_lazy(const char*);
  void connect(unsigned int, unsigned int);
  bool is_connected(unsigned int, unsigned int);
  unsigned int get_root(unsigned int);
};

#endif //QUICK_UNION_LAZY_H_INCLUDED

// Local Variables:
// mode: c++
// End:
