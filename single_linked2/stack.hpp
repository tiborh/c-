#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <cassert>
#include <iostream>
#include <ostream>
#include <exception>
#include "node.hpp"

struct nomoreitems: public std::exception {
  virtual const char* what() const throw() {
    return "No items in the list.";
  }
};

//template<typename T> class stack;
//template<typename T> std::ostream& operator<<(std::ostream&, const stack<T>&);

template<typename T>
class stack {
public:
  struct iterator;
  stack();
  ~stack();
  void push(const T);
  //void push(const node<T>);
  T pop();
  T view() const;
  //void erase();
  int size() const { return n; }
  bool is_empty() const { return first == end_item; }
  iterator begin() { return iterator(first); }
  iterator end() { return iterator(end_item); }
  template<typename T1> friend std::ostream& operator<<(std::ostream&, const stack<T1>&);
protected:
  node<T> *first,*last,*end_item;
  int n;
private:
};

template<typename T>
stack<T>::~stack()  {
  while(first != nullptr) {
    node<T> *old_first = first;
    first = first->next_node;
    if (old_first != nullptr) {
      //std::cout << "destroying: " << *old_first;
      delete(old_first);
      --n;
    }
  }
}

template<typename T>
stack<T>::stack():n(0) {
  end_item = new node<T>();
  first = end_item;
  last = end_item;
}

template<typename T>
struct stack<T>::iterator {
  node<T>* current;
  iterator():current(nullptr) {}
  iterator(node<T>* other):current(other) {}
  node<T>& operator*() { return *current; }
  bool operator==(const iterator& other) {
    if (current == nullptr && other.current == nullptr)
      return true;
    if (current == nullptr || other.current == nullptr)
      return false;
    return (current->item == other.current->item &&
	    current->next_node == other.current->next_node);
  }
  bool operator!=(const iterator& other) {
    return !(*this==other);
  }
  iterator& operator++() {
    if (current == nullptr) {
      std::cerr << "Iterator points at nullptr.\n";
      throw nomoreitems();
    }
    if (current->next_node == nullptr)
      return *this;
    current = current->next_node;
    return *this;
  }
};

template<typename T>
T stack<T>::view() const {
  assert(first != nullptr);
  if (n == 0 || first == end_item)
    throw nomoreitems();
  
  return first->item;
}

template<typename T>
void stack<T>::push(const T payload) {
  node<T>* a_node = new node<T>(payload);
  a_node->next_node = first;
  first = a_node;
  assert(last!=nullptr);
  if (last == end_item)
    last = a_node;
  assert(first->item == payload);
  assert(first == a_node);
  assert(last != nullptr);
  assert(last->next_node == end_item);
  ++n;
}

template<typename T>
T stack<T>::pop() {
  assert(first != nullptr);
  if (n == 0 || first == end_item )
    throw nomoreitems();
  assert(last != nullptr);

  T to_return = first->item;
  node<T>* old_node = first;
  first = first->next_node;
  assert(first != nullptr);
  if (first == end_item)
    last = end_item;
  delete(old_node);
  --n;
  return to_return;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const stack<T>& st) {
  node<T>* ptr = st.first;
  //int n = st.size();
  //for(int i = 0; i < n; ++i) {
  while (ptr != st.end_item) {
    os << '\t' << *ptr << '\n';
    ptr = ptr->next_node;
  }
  return os;
}

#endif //STACK_H_INCLUDED

// Local Variables:
// mode: c++
// End:
