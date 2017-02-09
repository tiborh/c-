#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

#include <cassert>
#include <iostream>
#include <ostream>
#include <exception>
#include "Item.hpp"

struct nomoreitems: public std::exception {
  virtual const char* what() const throw() {
    return "No items in the list.";
  }
};

template<typename T>
class Deque {
public:
  struct iterator;
  Deque():first(nullptr),last(nullptr),n(0) {}
  bool isEmpty() const { return n == 0; }
  int size() const { return n; }
  void addFirst(Item<T>);
  void addLast(Item<T>);
  Item<T> removeFirst();
  Item<T> removeLast();
protected:
  Item<T> *first,*last;
  int n;
private:

};

#endif //DEQUE_H_INCLUDED

// Local Variables:
// mode: c++
// End:
