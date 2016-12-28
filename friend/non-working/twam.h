#ifndef TWAM_H_INCLUDED
#define TWAM_H_INCLUDED
#include "friend.h"
class twam {
  friend class twim;
  int i;
  char* ch;
  twem* a;
  int magic() {
    int i = rand();
    return i;
  }
  char* get_str_pt() { return ch; }
 public:
  void make_str(const char*& instr) {
    a = new twem();
    a->internal_string = new char[strlen(instr) + 1];
    strcpy(a->internal_string,instr);
    ch = a->internal_string;
  }
};
#endif //TWAM_H_INCLUDED
