#include "slist.h"

// constructors:
slist::slist() : na(0) {}
slist::slist(slist_elem se) : na(&se) { se.next = 0; }
slist::slist(char c) {
  slist_elem new_elem = new slist_elem;
  new_elem.c = c;
  slist(new_elem);
}
// destructor:
slist::~slist() { erase(); }
// methods:
slist::add(char c) {
  slist_elem new_elem = new slist_elem;
  new_elem.c = c;
  new_elem.na = na;
  na = &new_elem;
}
slist::del() {
  slist_elem* tempa = (*na).na;
  delete(*na);
  na = tempa;
}
slist::erase() {
  while(na != 0)
    del();
}
