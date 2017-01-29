#include <iostream>

#include "union_find.hpp"

using namespace std;

int main() {
  cout << "First test: size constructor\n";
  cout << "============================\n";
  cout << "create and print:\n";
  unsigned int a_size = 10;
  union_find a(a_size);
  assert(a.size() == a_size);
  cout << a << "\n";
  assert(!a.is_connected(4,3));
  cout << "is 4 and 3 connected? " << boolalpha << a.is_connected(4,3) << '\n';
  cout << "connect and try again: ";
  a.connect(4,3);
  assert(a.is_connected(4,3));
  cout << a.is_connected(4,3) << '\n';
  cout << a << '\n';
  cout << "Connecting some more points:\n";
  a.connect(3,8);
  assert(a.is_connected(3,4));
  assert(a.is_connected(4,8));
  a.connect(6,5);
  a.connect(9,4);
  assert(a.is_connected(3,4));
  assert(a.is_connected(4,8));
  assert(a.is_connected(3,9));
  assert(a.is_connected(8,9));
  a.connect(2,1);
  a.connect(2,7);
  a.connect(0,5);
  assert(!a.is_connected(0,7));
  cout << a << '\n';
  cout << "Connecting two subgraphs.\n";
  a.connect(0,1);
  assert(a.is_connected(0,7));
  cout << a << '\n';

  cout << "Second test: filename constructor\n";
  cout << "=================================\n";
  cout << "create and print:\n";
  const char* fn1 = "graph_generate_5.txt";
  union_find b(fn1);
  assert(b.is_connected(0,2));
  assert(!b.is_connected(2,3));
  cout << b << '\n';
  return 0;
}
