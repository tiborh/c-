#ifndef TWEM_H_INCLUDED
#define TWEM_H_INCLUDED
#include "friend.h"
class twem {
  friend void foo();
  friend void twam::make_str(const char*&);
  char* get_str_pt() {
    return internal_string;
  }
public:
  char* internal_string;
};
#endif //TWEM_H_INCLUDED
