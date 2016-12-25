#ifndef SLIST_H
#define SLIST_H

#include <ostream>

struct slist_elem {
  char c;
  slist_elem* next;
};

struct slist {
  slist();
  slist(char);
  slist(slist_elem);
  ~slist();
  void add(char);
  void del();
  void erase();
  char first_char() const;
  slist_elem* first_address() const { return na; };
  slist_elem pop();
  void push(slist_elem);
  void reverse();
  bool is_empty() { return((na == 0) ? true : false); }
private:
  slist_elem* na;
};

std::ostream& operator<<(std::ostream&, const slist&);

#endif // SLIST_H
