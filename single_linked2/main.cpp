#include <iostream>
#include "main.hpp"
#include <limits>

using namespace std;

int main(int argc, char** argv) {
  node_test();
  simple_stack_test();
  simple_queue_test();
  input_test(argc,argv);
  
  return 0;
}

void input_test(int argc, char** argv) {
  cout << '\n';
  cout << "Command line args test\n";
  cout << "======================\n";
  if (argc == 1) {
    cout << "No command line args.\n(looking for input on stdin)\n";
    vector<string> inwords;
    do {
      string inword;
      cin >> inword;
      // cout << "input read: " << inword << " (length: " << inword.size() << ")\n";
      if (inword.size() > 0)
	inwords.push_back(inword);
    } while (!cin.eof());
    cout << "\n<<<Input test with stack (stdin):>>>\n";
    list_maker<stack<string>>(inwords);
    cout << "\n<<<Input test with queue (stdin):>>>\n";
    list_maker<queue<string>>(inwords);
  } else {
    cout << "\n<<<Input test with stack (argv):>>>\n";
    list_maker<stack<string>>(argc,argv);
    cout << "\n<<<Input test with queue (argv):>>>\n";
    list_maker<queue<string>>(argc,argv);
  }
}

template<typename T1>
void list_maker(vector<string> argv) {
  T1 ts;
  int length = argv.size();
  for (int i = 0; i < length; ++i) {
    string inval(argv[i]);
    if (inval == "----")
      ts.pop();
    else
      ts.push(inval);
  }
  std::cout << ts << '\n';
}

template<typename T1>
void list_maker(int argc, char** argv) {
  T1 ts;
  for (int i = 1; i < argc; ++i) {
    string inval(argv[i]);
    if (inval == "----")
      ts.pop();
    else
      ts.push(inval);
  }
  std::cout << ts << '\n';
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

void simple_queue_test() {
  cout << '\n';
  cout << "Simple queue tests\n";
  cout << "==================\n";
  queue<string> a;
  a.push("one");
  assert(a.size() == 1);
  cout << "one member:\n" << a << '\n';
  a.push("two");
  a.push("three");
  assert(a.size() == 3);
  assert(a.view() == string("one"));
  cout << "three members:\n" << a << '\n';
  string popped = a.pop();
  assert(popped == string("one"));
  cout << "pop one: " <<  popped << '\n';
  assert(a.size() == 2);
  assert(a.view() == string("two"));
  cout << "two members:\n" << a << '\n';
}
