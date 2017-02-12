#ifndef RANDOMISEDQUEUE_H_INCLUDED
#define RANDOMISEDQUEUE_H_INCLUDED

#include "stack.hpp"
#include <random>
#include <ctime>

template<typename T>
class RandomisedQueue: public stack<T> {
public:
  struct iterator; // remove the nth element from the stack
  // construct an empty randomized queue
  RandomisedQueue(): stack<T>::stack() {};
  bool isEmpty() { return stack<T>::n == 0; } // is the queue empty?
  int size() {  return stack<T>::n; }          // return the number of items on the queue
  void enqueue(T item);           // add the item
  T dequeue();                    // remove and return a random item
  T sample();                     // return (but do not remove) a random item
protected:
  T remove(int);		// remove the element at place in the argument
private:

};

template<typename T>
void RandomisedQueue<T>::enqueue(const T payload) {

}

template<typename T>
T RandomisedQueue<T>::dequeue() {

  return T();
}

template<typename T>
T RandomisedQueue<T>::sample() {

  return T();
}

template<typename T>
T RandomisedQueue<T>::remove(int m) {

  return T();
}

#endif //RANDOMISEDQUEUE_H_INCLUDED

// Local Variables:
// mode: c++
// End:
