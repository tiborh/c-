#ifndef QUICK_UNION_COMPRESS_H_INCLUDED
#define QUICK_UNION_COMPRESS_H_INCLUDED

#include "quick_union_shorter.hpp"

class quick_union_compress: public quick_union_shorter {
public:
  quick_union_compress(unsigned int s=10):quick_union_shorter(s) {}
  quick_union_compress(const char*);
  void connect(unsigned int a, unsigned int b);
  std::vector<unsigned int> get_root_and_size(unsigned int);
};

#endif //QUICK_UNION_COMPRESS_H_INCLUDED

// Local Variables:
// mode: c++
// End:
