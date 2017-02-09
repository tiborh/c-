#include <iostream>
#include "main.hpp"


using namespace std;

int main(int argc, char** argv) {
  item_test();
  
  return 0;
}

void item_test() {
  cout << '\n';
  cout << "Simple item tests\n";
  cout << "=================\n";
  Item<string> a;
  assert(a.is_empty());
  assert(a.is_unconnected());
  assert(a.get_next() == nullptr);
  assert(a.get_prev() == nullptr);
  cout << "empty Item:\n" << a << '\n';
  a.set_id(string("zero"));
  assert(a.get_id() == string("zero"));
  cout << "giving id:\n" << a << '\n';

  string teststr("one");
  Item<string> b(teststr);
  assert(!b.is_empty());
  cout << "Item with id:\n" << b << '\n';
  assert(b.get_id() == teststr);
  a.connect_to(&b);
  assert(!b.is_unconnected());
  assert(!b.is_unconnected());
  assert(b.get_prev() == &a);
  assert(a.get_next() == &b);
  cout << "after connection:\n"
       << a << b << '\n';
  assert(a.is_connected_to(&b));
  
  Item<string> c(b);
  // what shall we do with the copy constructor?
  // problem: what happens to the node that is connected to the original?
  // Which of them is it going to be connected to?
  assert(b.get_id() == c.get_id());
  assert(b.is_empty() == c.is_empty());
  assert(b.get_prev() == c.get_prev());
  cout << "after clone construct:\n" << c << '\n';
  b.unconnect();
  assert(a.is_unconnected());
  assert(b.is_unconnected());
  b.connect(&a,&c);
  c.set_id(string("three"));
  cout << "id and connection modification:\n" << a << b << c << '\n';
  assert(a.is_first());
  assert(b.is_mid());
  assert(c.is_last());
  assert(a.is_connected_to(&c));
}
