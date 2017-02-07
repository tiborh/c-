#include <iostream>
#include "main.hpp"

using namespace std;

int main(int argc, char** argv) {
  node_test();
  simple_stack_test();
  input_test(argc,argv);
  
  return 0;
}

void input_test(int argc, char** argv) {
  cout << '\n';
  cout << "Command line args test\n";
  cout << "======================\n";
  if (argc == 1)
    cout << "No command line args.\n";
  else {
    stack<string> ts;
    for (int i = 1; i < argc; ++i) {
      string inval(argv[i]);
      if (inval == "----")
	ts.pop();
      else
	ts.push(inval);
    }
    std::cout << ts << '\n';
  }
}

void node_test() {
  cout << '\n';
  cout << "Simple node tests\n";
  cout << "=================\n";
  node<string> a;
  assert(a.next_node == nullptr);
  cout << "empty node: " << a << '\n';
  string teststr("one");
  node<string> b(teststr);
  cout << "node with item: " << b << '\n';
  assert(b.item == teststr);
  b.next_node = &a;
  assert(b.next_node == &a);
  cout << "after connection attempt: " << b << '\n';
  node<string> c(b);
  assert(b.item == c.item);
  assert(b.empty == c.empty);
  assert(b.next_node == c.next_node);
  cout << "after clone construct: " << c << '\n';
  c.next_node = &b;
  cout << "modified next: " << c << '\n';
}

void simple_stack_test() {
  cout << '\n';
  cout << "Simple stack tests\n";
  cout << "==================\n";
  stack<string> a;
  assert(a.size() == 0);
  assert(a.is_empty());
  cout << "empty: " << a << '\n';
  // node<string> na(string("first"));
  // a.push(na);
  // cout << "attempting push with '" << na << "'\n";
  a.push(string("一"));
  assert(a.size() == 1);
  cout << "one item:\n" << a << '\n';
  string second("二");
  cout << "attempting construct with '" << second << "'\n";
  a.push(second);
  assert(a.size() == 2);
  cout << "two items:\n" << a << '\n';
  cout << "testing view(): " << a.view() << '\n';
  assert(a.view() == second);
  string nd = a.pop();
  assert(nd == second);
  string first = a.pop();
  cout << "Drawing one more 'pop' than items on stack.\n";
  try {
    a.pop();
  } catch(nomoreitems& e) {
    cerr << "Error with pop()\n";
    cerr << e.what() << endl;
  } catch(std::exception e) {
    cerr << "Unexpected error:\n";
    cerr << e.what() << endl;
  }
  assert(a.size() == 0);
}
