#ifndef RANDOMISEDQUEUE_H_INCLUDED
#define RANDOMISEDQUEUE_H_INCLUDED

#include <iostream>
#include <ostream>
#include <array>
#include <stack>
#include <cassert>
#include <cstdlib>
#include <ctime>

const unsigned int DEFAULT_SIZE = 4;    // start with this size
const unsigned int INCREASE_FACTOR = 2; // make INCREASE_FACTOR times big, when outgrown
const double DECREASE_THRESHOLD = 0.25; // cut size when this full

template<typename T>
class RandomisedQueue {
public:
  struct Iterator;
  RandomisedQueue():items(new T*[DEFAULT_SIZE]),n(0),ptr(0),items_size(DEFAULT_SIZE) { srand(clock()); }   // construct an empty randomized queue
  bool isEmpty() {  return n == 0; } // is the queue empty?
  unsigned int size() { return n; }           // return the number of items on the queue
  void enqueue(T item);        // add the item
  T dequeue();                 // remove and return a random item
  T sample() const;                  // return (but do not remove) a random item
  template<typename T2> friend std::ostream& operator<<(std::ostream&, const RandomisedQueue<T2>&);
protected:
private:
  T* items;
  std::stack<unsigned int> freed_places;
  unsigned int n,ptr,items_size;
  unsigned int get_index() const;
  void double_items();
};

template<typename T>
void RandomisedQueue<T>::double_items() {
  //array<T*,items.size()> *old_items = items;
  T* new_items[INCREASE_FACTOR*items.size()];
  for (unsigned int i = 0; i < current_size; ++i)
    new_items->[i] = items->[i];
  items = new_items;
  delete(new_items);
}

template<typename T>
void RandomisedQueue<T>::enqueue(T item) {
  if (ptr >= items->size())
    double_items();
  T *new_item = new T(item);
  if (freed_places.empty()) {
      items->[ptr] = new_item;
      ++ptr;
  } else {
    unsigned reused = freed_places.top();
    freed_places.pop();
    items->[reused] = new_item;
  }
  ++n;
}

template<typename T>
unsigned RandomisedQueue<T>::get_index() const {
  assert(n > 0);
  unsigned int index = 0;
  unsigned rand_range = ptr;
  do {
    index = rand() % rand_range;
    //std::cout << '\t' << items->[index] << '\n';
  }while(items->[index] == nullptr);
  return index;
}

template<typename T>
T RandomisedQueue<T>::dequeue() {
  assert(n > 0);
  unsigned index = get_index();
  //std::cout << "\t\tindex received (in dequeue): " << index << '\n';
  T return_item = *items->[index];
  free(items->[index]);
  items->[index] = nullptr;
  --n;
  freed_places.push(index);
  return return_item;
}

template<typename T>
T RandomisedQueue<T>::sample() const {
  assert(n > 0);
  unsigned int index = 0;
  do {
    index = rand() % n;
  }while(items->[index] == nullptr);
  return(*items->[index]);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const RandomisedQueue<T>& st) {
  for (unsigned int i = 0; i < st.ptr; ++i) {
    //std::cout << "\t\tindex (in operator<<): " << i << '\n';
    if (st.items->[i] != nullptr)
      os << '\t' << i << ": " << st.items->[i] << " -> " << *st.items->[i] << '\n';
  }
  return os;
}

#endif //RANDOMISEDQUEUE_H_INCLUDED

// Local Variables:
// mode: c++
// End:
