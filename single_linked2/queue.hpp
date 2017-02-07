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
  a_node->next_node = nullptr;
  if (stack<T>::last != nullptr)
    stack<T>::last->next_node = a_node;
  stack<T>::last = a_node;
  if (stack<T>::first == nullptr)
    stack<T>::first = a_node;
  assert(stack<T>::last->item == payload);
  assert(stack<T>::last == a_node);
  ++stack<T>::n;
}

template<typename T>
T queue<T>::pop() {
  T outpayload = stack<T>::pop();
  if (stack<T>::first == nullptr)
    stack<T>::last = nullptr;
  return outpayload;
}

#endif //QUEUE_H_INCLUDED

// Local Variables:
// mode: c++
// End:
