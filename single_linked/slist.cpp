#include "slist.h"

// constructors:
slist::slist() : na(0) {}
slist::slist(slist_elem se) : na(&se) { se.next = 0; }
slist::slist(char c) {
  slist_elem new_elem = {c,0};
  na = &new_elem;
}
// destructor:
slist::~slist() { erase(); }
// methods:
void slist::add(char c) {
  slist_elem new_elem = {c,na};
  na = &new_elem;
}
void slist::del() {
  slist_elem* tempa = (*na).next;
  delete(na);
  na = tempa;
}
void slist::erase() {
  while(na != 0)
    del();
}
char slist::first_char() const { return((*na).c); }
slist_elem slist::pop() {
  slist_elem* temp = na;
  slist_elem* tempa = na->next;
  temp->next = 0;
  //delete(*na);
  na = tempa;
  return *temp;
}
void slist::push(slist_elem se) {
  se.next = na;
  na = &se;
}
void slist::reverse() {
  slist_elem* temp_na = 0;
  do {
    slist_elem* saved_na = na->next;
    na->next = temp_na;
    temp_na = na;
    na = saved_na;
  } while(na != 0);
}

std::ostream& operator<<(std::ostream& os, const slist& sl) {
  slist_elem* temp = sl.first_address();
  while(temp != 0) {
    os << (*temp).c << " ";
    temp = sl.first_address();
  }
  return os;
}
