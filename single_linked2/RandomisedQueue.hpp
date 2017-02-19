#ifndef RANDOMISEDQUEUE_H_INCLUDED
#define RANDOMISEDQUEUE_H_INCLUDED

#include "stack.hpp"
#include <cstdlib>		// rand(),srand()
#include <ctime>

template<typename T>
class RandomisedQueue: public stack<T> {
public:
  // construct an empty randomized queue
  RandomisedQueue():stack<T>(),ptr(nullptr),prev_ptr(nullptr) { srand((unsigned)time(0)); };
  bool isEmpty() { return stack<T>::is_empty(); } // is the queue empty?
  void enqueue(const T item) { stack<T>::push(item); }           // add the item
  T dequeue();                    // remove and return a random item
  T sample();                     // return (but do not remove) a random item
protected:
  node<T>* set_ptr();
  T remove();		// remove the element ptr points at
  node<T> *ptr,*prev_ptr;
private:

};

template<typename T>
T RandomisedQueue<T>::dequeue() {
  if (stack<T>::is_empty())
    stack<T>::pop();
  if (1 == stack<T>::size())
    return stack<T>::pop();
  set_ptr();
  return remove();
}

template<typename T>
node<T>* RandomisedQueue<T>::set_ptr() {
  prev_ptr = stack<T>::first;
  ptr = stack<T>::first;
  int sample_index = rand() % stack<T>::size();
  //std::cout << "random num: " << sample_index;
  for (int i = 0; i < sample_index; ++i) {
    prev_ptr = ptr;
    ptr = ptr->next_node;
  }
  return ptr;
}

template<typename T>
T RandomisedQueue<T>::sample() {
  if (stack<T>::is_empty())
    stack<T>::view();
  return set_ptr()->item;
}

template<typename T>
T RandomisedQueue<T>::remove() {
  assert(!stack<T>::is_empty());
  assert(ptr != nullptr);
  assert(prev_ptr != nullptr);
  assert(ptr != stack<T>::end_item);
  if (ptr == stack<T>::first) {
    ptr = nullptr;
    prev_ptr = nullptr;
    return stack<T>::pop();
  }
  assert(prev_ptr != ptr);
  assert(prev_ptr->next_node == ptr);
  T to_return = ptr->item;
  prev_ptr->next_node = ptr->next_node;
  //std::cout << "ptr: " << *ptr << '\n';
  if (ptr == stack<T>::last)
    stack<T>::last = prev_ptr;
  delete(ptr);
  ptr = nullptr;
  prev_ptr = nullptr;
  --stack<T>::n;
  return to_return;
}

#endif //RANDOMISEDQUEUE_H_INCLUDED

// Local Variables:
// mode: c++
// End:
