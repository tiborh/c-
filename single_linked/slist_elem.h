#ifndef SLIST_ELEM_H
#define SLIST_ELEM_H

#include <ostream>

struct slist_elem {
  slist_elem() : c(0),na(0) {}
  slist_elem(char inc, slist_elem* inna = 0) : c(inc),na(inna) {}
  slist_elem(const slist_elem& other) : c(other.get_c()),na(other.get_na()) {}
  ~slist_elem() {}
  char get_c() const { return c; }
  slist_elem* get_na() const { return na; }
  void set_na(slist_elem* ne) { na = ne; }
  void set_c(const char& inc) { c = inc; }
  void set(const slist_elem* ne) {
    c = ne->get_c();
    na = ne->get_na(); 
  }
private:
  char c;
  slist_elem* na;
};

std::ostream& operator<<(std::ostream&, const slist_elem&);

#endif //SLIST_ELEM_H
