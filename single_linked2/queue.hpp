#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "stack.hpp"

template<typename T>
class queue: public stack<T> {
public:
  queue(): stack<T>::stack() {};
  void push(const T);
  T pop();
protected:

private:

};

template<typename T>
void queue<T>::push(const T payload) {
  node<T>* a_node = new node<T>(payload);
  a_node->next_node = stack<T>::end_item;
  assert(stack<T>::last != nullptr);
  if (stack<T>::last != stack<T>::end_item)
    stack<T>::last->next_node = a_node;
  stack<T>::last = a_node;
  if (stack<T>::first == stack<T>::end_item)
    stack<T>::first = a_node;
  assert(stack<T>::last->item == payload);
  assert(stack<T>::last == a_node);
  assert(stack<T>::last->next_node == stack<T>::end_item);
  ++stack<T>::n;
}

template<typename T>
T queue<T>::pop() {
  T outpayload = stack<T>::pop();
  assert(stack<T>::first != nullptr);
  if (stack<T>::first == stack<T>::end_item)
    stack<T>::last = stack<T>::end_item;
  return outpayload;
}

#endif //QUEUE_H_INCLUDED

// Local Variables:
// mode: c++
// End:
