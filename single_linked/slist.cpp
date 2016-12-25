#include "slist.h"

// constructors:
slist::slist() : na(0) {}
slist::slist(const slist_elem& se) {
  slist_elem* new_elem = new slist_elem(se);
  na = new_elem;
  new_elem->set_na(0);
}
slist::slist(char c) {
  slist_elem* new_elem = new slist_elem(c);
  na = new_elem;
}

// destructor:
slist::~slist() { erase(); }

// methods:
void slist::add(char c) {
  slist_elem* new_elem = new slist_elem{c,na};
  na = new_elem;
}
void slist::del() {
  slist_elem* tempa = na->get_na();
  delete(na);
  na = tempa;
}
void slist::erase() {
  while(na != 0)
    del();
}
void slist::push(const slist_elem* se) {
  slist_elem* new_elem = new slist_elem(*se);
  new_elem->set_na(na);
  na = new_elem;
}
slist_elem* slist::pop() {
  slist_elem* out = na;
  na = na->get_na();
  out->set_na(0);
  return out;
}
void slist::reverse() {
  slist_elem* temp = na;
  na = 0;
  while(temp != 0) {
    slist_elem* temp_na = temp->get_na();
    temp->set_na(na);
    na = temp;			// could be skipped with a more intelligent code
    temp = temp_na;
  }
}

// external method:
std::ostream& operator<<(std::ostream& os, const slist& sl) {
  slist_elem* temp = sl.top();
  while(temp != 0) {
    os << temp->get_c() << " -> ";
    temp = temp->get_na();
  }
  os << '0';
  return os;
}
