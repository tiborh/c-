#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <cassert>
#include <iostream>
#include <ostream>
#include <exception>
#include "node.hpp"

struct nomoreitems: public std::exception {
  virtual const char* what() const throw()
  {
    return "No items in the list.";
  }
};

template<typename T> class stack;
template<typename T> std::ostream& operator<<(std::ostream&, const stack<T>&);

template<typename T>
class stack {
public:
  stack():first(nullptr),n(0) {}
  //stack(const stack& other):first(other.first),n(other.n) {}
  ~stack() {}
  void push(const T);
  //void push(const node<T>);
  T pop();
  T view() const;
  //void erase();
  int size() const { return n; }
  bool is_empty() const { return first == nullptr; }
  friend std::ostream& operator<< <> (std::ostream&, const stack<T>&);
protected:
  node<T> *first;
  int n;
private:

};

template<typename T>
T stack<T>::view() const {
  if (n == 0 || first == nullptr )
    throw nomoreitems();
  
  return first->item;
}

template<typename T>
void stack<T>::push(const T payload) {
  node<T>* a_node = new node<T>(payload);
  a_node->next_node = first;
  first = a_node;
  assert(first->item == payload);
  assert(first == a_node);
  ++n;
}

template<typename T>
T stack<T>::pop() {
  if (n == 0 || first == nullptr )
    throw nomoreitems();

  T to_return = first->item;
  node<T>* old_node = first;
  first = first->next_node;
  delete(old_node);
  --n;
  return to_return;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const stack<T>& st) {
  node<T>* ptr = st.first;
  //int n = st.size();
  //for(int i = 0; i < n; ++i) {
  while (ptr != nullptr) {
    os << '\t' << *ptr << '\n';
    ptr = ptr->next_node;
  }
  return os;
}

// template<typename T>
// void stack<T>::push(const node<T> new_node) {
//   node<T>* a_node = new node<T>(new_node);
//   a_node -> next_node = first;
//   first = a_node;
//   assert(first->item == new_node.item);
//   assert(first == a_node);
//   ++n;
// }

// template<typename T>
// void stack<T>::erase() {
//   while(first != nullptr)
//     pop();
//   assert(n == 0);
//   assert(first == nullptr);
// }

#endif //STACK_H_INCLUDED

// Local Variables:
// mode: c++
// End:
