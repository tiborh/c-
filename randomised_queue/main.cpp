#include <iostream>
#include "main.hpp"

using namespace std;

int main() {
  simple_queue_test();
  //queue_test_with_empty_slots();
  return 0;
}

void simple_queue_test() {
  cout << '\n';
  cout << "Simple queue test\n";
  cout << "=================\n";
  const unsigned int NU = 5;
  cout << "creation, filling up, and print:\n";
  RandomisedQueue<string> a;
  array<string,NU> items = {"一","二","三","四","五"};
  for(unsigned int i = 0; i < NU; ++i)
    a.enqueue(items[i]);
  cout << a;
  cout << "sample() test:\n";
  for (unsigned i = 0; i < 15; ++i)
    cout << '\t' << a.sample() << '\n';
  cout << "dequeue() test:\n";
  for (unsigned int i = 0; i < NU; ++i) {
    string gotten = a.dequeue();
    assert(a.size() == NU - (i+1));
    cout << "got back: " << gotten << '\n';
    cout << "remaining queue:\n";
    cout << a;
  }
  cout << "refill old items into freed slots:\n";
  for(unsigned int i = 0; i < NU; ++i)
    a.enqueue(items[i]);
  cout << a;
}
