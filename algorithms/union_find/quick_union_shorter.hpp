#ifndef QUICK_UNION_SHORTER_H_INCLUDED
#define QUICK_UNION_SHORTER_H_INCLUDED

#include "quick_union_lazy.hpp"

class quick_union_shorter: public quick_union_lazy {
public:
  quick_union_shorter(unsigned int s=10):quick_union_lazy(s) {}
  quick_union_shorter(const char*);
  void connect(unsigned int, unsigned int);
  std::vector<unsigned int> get_root_and_size(unsigned int);
};

#endif //QUICK_UNION_SHORTER_H_INCLUDED

// Local Variables:
// mode: c++
// End:
