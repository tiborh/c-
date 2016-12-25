#ifndef SLIST_H
#define SLIST_H
#include "slist_elem.h"
#include <ostream>

struct slist {
  slist();
  slist(char);
  slist(const slist_elem&);
  ~slist();
  void add(char);
  void del();
  void erase();
  slist_elem* top() const { return na; }
  slist_elem* pop();
  void push(const slist_elem*);
  void reverse();
  bool is_empty() { return(na == 0); }
private:
  slist_elem* na;
};

std::ostream& operator<<(std::ostream&, const slist&);

#endif // SLIST_H
