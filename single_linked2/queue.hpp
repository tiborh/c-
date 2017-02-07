#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "stack.hpp"

template<typename T>
class queue: public stack<T> {
public:
  queue(): stack<T>::stack(),last(nullptr) {};
  void push(const T);
  T pop();
protected:
  node<T> *last;
private:

};

template<typename T>
void queue<T>::push(const T payload) {
  node<T>* a_node = new node<T>(payload);
  a_node->next_node = nullptr;
  if (last != nullptr)
    last->next_node = a_node;
  last = a_node;
  if (stack<T>::first == nullptr)
    stack<T>::first = a_node;
  assert(last->item == payload);
  assert(last == a_node);
  ++stack<T>::n;
}

template<typename T>
T queue<T>::pop() {
  T outpayload = stack<T>::pop();
  if (stack<T>::first == nullptr)
    last = nullptr;
  return outpayload;
}

#endif //QUEUE_H_INCLUDED

// Local Variables:
// mode: c++
// End:
