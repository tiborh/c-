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

struct NullPointerException: public std::exception {
  virtual const char* what() const throw() {
    return "NULL item cannot be added.";
  }
};

template<typename T>
class Deque {
public:
  struct iterator;
  Deque():first(nullptr),last(nullptr),n(0) {}
  bool isEmpty() const { return n == 0; }
  int size() const { return n; }
  void addFirst(const Item<T>&);
  void addLast(const Item<T>&);
  void addFirst(const T&);
  void addLast(const T&);
  Item<T> removeFirst();
  Item<T> removeLast();
  T removeFirst(bool);
  T removeLast(bool);
  T viewFirst() const { return(first != nullptr ? first->id : T()); }
  T viewLast() const { return(last != nullptr ? last->id : T()); }
  iterator begin() { return iterator(first); }
  iterator end() { return iterator(); }
  template<typename T1> friend std::ostream& operator<<(std::ostream&, const Deque<T1>&);
protected:
  Item<T> *first,*last;
  int n;
private:

};

template<typename T>
struct Deque<T>::iterator {
  Item<T>* current;
  iterator():current(nullptr) {}
  iterator(Item<T>* other):current(other) {}
  Item<T>& operator*() { return *current; }
  bool operator==(const iterator& other) {
    if (current == nullptr && other.current == nullptr)
      return true;
    if (current == nullptr || other.current == nullptr)
      return false;
    return (current->id == other.current->id &&
	    current->prev_item == other.current->prev_item &&
	    current->next_item == other.current->next_item );
  }
  bool operator!=(const iterator& other) {
    return !(*this==other);
  }
  iterator& operator++() {
    if (current == nullptr) {
      std::cerr << "Iterator points at nullptr.\n";
      throw nomoreitems();
    }
    current = current->next_item;
    return *this;
  }
};

template<typename T>
void Deque<T>::addFirst(const Item<T>& payload) {
  Item<T> *a_node = new Item<T>(payload);
  a_node->next_item = first;
  if (first != nullptr)
    first->prev_item = a_node;
  first = a_node;
  if (last == nullptr)
    last = a_node;
  assert(first->id == payload.id);
  assert(first == a_node);
  assert(last != nullptr);
  ++n;
}

template<typename T>
void Deque<T>::addFirst(const T& payload) {
  Item<T>* a_node = new Item<T>(payload);
  addFirst(*a_node);
}

template<typename T>
void Deque<T>::addLast(const Item<T>& payload) {
  Item<T>* a_node = new Item<T>(payload);
  a_node->next_item = nullptr;
  if (last != nullptr) {
    last->next_item = a_node;
    a_node->prev_item = last;
  }
  last = a_node;
  if (first == nullptr)
    first = a_node;
  assert(last->id == payload.id);
  assert(last == a_node);
  ++n;
}

template<typename T>
void Deque<T>::addLast(const T& payload) {
  Item<T>* a_node = new Item<T>(payload);
  addLast(*a_node);
}

template<typename T>
Item<T> Deque<T>::removeFirst() {
  if (n == 0 || first == nullptr )
    throw nomoreitems();
  assert(last != nullptr);

  Item<T>* old_node = first;
  first = first->next_item;
  if (first == nullptr)
    last = nullptr;
  else
    first->prev_item = nullptr;
  --n;
  old_node->disconnect();
  return *old_node;
}

template<typename T>
T Deque<T>::removeFirst(bool payloadOnly) {
  if (payloadOnly == false) return T();
  Item<T> to_return = removeFirst();
  return to_return.id;
}

template<typename T>
Item<T> Deque<T>::removeLast() {
  if (n == 0 || last == nullptr )
    throw nomoreitems();
  assert(first != nullptr);

  Item<T>* old_node = last;
  last = last->prev_item;
  if (last == nullptr)
    first = nullptr;
  else
    last->next_item = nullptr;
  --n;
  old_node->disconnect();
  return *old_node;
}

template<typename T>
T Deque<T>::removeLast(bool payloadOnly) {
  if (payloadOnly == false) return T();
  Item<T> to_return = removeLast();
  return to_return.id;
}

template<typename T1>
std::ostream& operator<<(std::ostream& os, const Deque<T1>& st) {
  Item<T1>* ptr = st.first;
  //int n = st.size();
  //for(int i = 0; i < n; ++i) {
  while (ptr != nullptr) {
    os << '\t' << *ptr;
    ptr = ptr->next_item;
  }
  return os;
}

#endif //DEQUE_H_INCLUDED

// Local Variables:
// mode: c++
// End:
