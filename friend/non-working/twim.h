#ifndef TWIM_H_INCLUDED
#define TWIM_H_INCLUDED
#include "friend.h"
class twim {
public:
  static int gen_num() {
    twam* a = new twam();
    return a->magic();
  }
};
#endif //TWIM_H_INCLUDED
