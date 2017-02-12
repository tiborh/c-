#include <iostream>
#include "main.hpp"

using namespace std;

int main(int argc, char** argv) {
  item_test();
  simple_stack_test();
  simple_queue_test();
  remove_last_test();
  iterator_test<Deque<string>>();
  corner_case_tests();
  return 0;
}

void corner_case_tests() {
  cout << '\n';
  cout << "Corner Case Tests\n";
  cout << "=================\n";
  cout << "\n";
  Deque<string> a;
  assert(a.size() == 0);
  cout << "Empty Deque tests:\n";
  cout << "------------------\n";
  try {
    a.removeFirst("removeFirst() on empty Deque:\n");
  } catch(nomoreitems& e) {
    cerr << "Error with removeFirst()\n";
    cerr << e.what() << endl;
  } catch(std::exception e) {
    cerr << "Unexpected error:\n";
    cerr << e.what() << endl;
  }
  cout << "Checking the same with 'viewFirst'.\n";
  cout << '"' << a.viewFirst() << "\"\n";
  cout << "removeLast() on empty Deque:\n";
  try {
    a.removeLast();
  } catch(nomoreitems& e) {
    cerr << "Error with removeLast()\n";
    cerr << e.what() << endl;
  } catch(std::exception e) {
    cerr << "Unexpected error:\n";
    cerr << e.what() << endl;
  }
  cout << "Checking the same with 'viewLast'.\n";
  cout << '"' << a.viewLast() << "\"\n";

  cout << "Adding null element:\n";
  cout << "--------------------\n";
  cout << "First, using empty Item() constructor.\n";
  a.addFirst(Item<string>());
  a.addFirst(Item<string>());
  cout << "size: " << a.size() << '\n';
  cout << "printing the Deque:\n" << a << '\n';
  cout << "Then null pointer attempt:\n";
  try {
    a.addLast((Item<string>)nullptr);
  } catch(std::logic_error e) {
    cerr << "logic error has been caught:\n";
    cerr << e.what() << endl;
    cout << "(the application of string inside the Deque catches the error)\n";
  }
  cout << "Code cannot handle nullptr cast as object.\n";
  // No preventive measure has been found against the following:
  // cout << "trying the same with c-style string:\n";
  // cout << "------------------------------------\n";
  // Deque<const char*> b;
  // b.addLast("one");
  // b.addLast("two");
  // cout << b << '\n';
  // b.addLast((const char*)nullptr);
  // cout << "size: " << a.size() << '\n';
  // cout << b << '\n';
  cout << "Handling remove() in iterator is not a problem in C++\n";

  cout << "Handling overruning iterator.\n";
  a.removeFirst();
  a.removeFirst();
  assert(a.size() == 0);
  a.addFirst(string("alpha"));
  cout << a << '\n';
  Deque<string>::iterator it = a.begin();
  assert((*it).id == string("alpha"));
  ++it;
  // the following does not catch exception as implementation has changed:
  // now ++ never goes beyond end_element.
  if (it != a.end())
    cout << *it;
  try {
    ++it;
  } catch(nomoreitems& e) {
    cerr << "Error with ++it\n";
    cerr << e.what() << endl;
  } 
}

void remove_last_test() {
  cout << '\n';
  cout << "Remove Last Test\n";
  cout << "================\n";
  Deque<string> a;
  const int NUM_OF_COLS = 6;
  const char* cols[NUM_OF_COLS] = {"黒","白","赤","青","黄","緑"};
  cout << "Adding colours with addFirst()\n";
  for (int i = 0; i < NUM_OF_COLS; ++i)
    a.addFirst(string(cols[i]));
  cout << "The colours:\n" << a << '\n';
  int size_of_a = a.size();
  cout << "popping items with removeLast():\n";
  for (int i = 0; i < size_of_a; ++i)
    cout << "popped item: " << a.removeLast();
  cout << "removeLast() on empty Deque:\n";
  try {
    a.removeLast();
  } catch(nomoreitems& e) {
    cerr << "Error with removeLast()\n";
    cerr << e.what() << endl;
  } catch(std::exception e) {
    cerr << "Unexpected error:\n";
    cerr << e.what() << endl;
  }
}

template<typename T1>
void iterator_test() {
  cout << '\n';
  cout << "Iterator tests\n";
  cout << "==============\n";
  T1 tl;
  for(int i = 0; i < NUM_OF_DAYS; ++i)
    tl.addFirst(THE_DAYS[i]);
  cout << "The days loaded:\n" << tl << '\n';
  cout << "Iterating through them:\n\t";
  for (typename T1::iterator it = tl.begin(); it != tl.end(); ++it)
    cout << (*it).id << ", ";
  cout << '\n';
  cout << "Same with queue-like behavour:\n\t";
  T1 t2;
  for(int i = 0; i < NUM_OF_DAYS; ++i)
    t2.addLast(THE_DAYS[i]);
  for (typename T1::iterator it = t2.begin(); it != t2.end(); ++it)
    cout << (*it).id << ", ";
  cout << "\n";
}

void simple_queue_test() {
  cout << '\n';
  cout << "Simple queue tests\n";
  cout << "==================\n";
  Deque<string> a;
  assert(a.isEmpty());
  a.addLast("one");
  assert(!a.isEmpty());
  assert(a.size() == 1);
  cout << "one member:\n" << a << '\n';
  a.addLast("two");
  a.addLast("three");
  assert(a.size() == 3);
  assert(a.viewFirst() == string("one"));
  cout << "three members:\n" << a << '\n';
  string popped = a.removeFirst(true);
  assert(popped == string("one"));
  cout << "pop one: " <<  popped << '\n';
  assert(a.size() == 2);
  assert(a.viewFirst() == string("two"));
  cout << "two members:\n" << a << '\n';
}

void simple_stack_test() {
  cout << '\n';
  cout << "Simple stack tests\n";
  cout << "==================\n";
  Deque<string> a;
  assert(a.size() == 0);
  assert(a.isEmpty());
  cout << "empty: " << a << '\n';
  // node<string> na(string("first"));
  // a.push(na);
  // cout << "attempting push with '" << na << "'\n";
  a.addFirst(string("一"));
  assert(a.size() == 1);
  cout << "one item:\n" << a << '\n';
  string second("二");
  cout << "attempting construct with '" << second << "'\n";
  a.addFirst(second);
  assert(a.size() == 2);
  cout << "two items:\n" << a << '\n';
  cout << "testing view(): " << a.viewFirst() << '\n';
  assert(a.viewFirst() == second);
  string nd = a.removeFirst(true);
  assert(nd == second);
  string first = a.removeFirst(true);
}

void item_test() {
  cout << '\n';
  cout << "Simple item tests\n";
  cout << "=================\n";
  Item<string> a;
  assert(a.next_item == nullptr);
  assert(a.prev_item == nullptr);
  cout << "empty Item:\n" << a << '\n';
  a.id = string("zero");
  assert(a.id == string("zero"));
  cout << "giving id:\n" << a << '\n';
  assert(a.is_disconnected());

  string teststr("one");
  Item<string> b(teststr);
  cout << "Item with id:\n" << b << '\n';
  assert(b.id == teststr);
  a.next_item = &b;
  b.prev_item = &a;
  assert(b.prev_item == &a);
  assert(a.next_item == &b);
  cout << "after connection:\n"
       << a << b << '\n';
  assert(a.is_first());
  assert(b.is_last());
  
  Item<string> c(b);
  // what shall we do with the copy constructor?
  // problem: what happens to the node that is connected to the original?
  // Which of them is it going to be connected to?
  cout << "after copy construct from b:\n" << c << '\n';
  c.id = string("two");
  b.next_item = &c;
  c.prev_item = &b;
  cout << "id and connection modification:\n" << a << b << c << '\n';
  assert(b.is_mid());
  assert(c.is_last());
  assert(!a.is_disconnected());
  assert(!b.is_disconnected());
  assert(!c.is_disconnected());

  cout << "item as pointer:\n";
  Item<string>* d = new Item<string>();
  cout << d << '\n';
  cout << *d;
  
  // so far, no cure has been found against the following:
  // cout << "Null item.\n";
  // Item<const char*> d = (Item<const char*>)nullptr;
  // cout << "Nullptr item: \"" << d << "\"\n";
}
