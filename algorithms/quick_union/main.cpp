#include <iostream>

#include "main.hpp"
#include "quick_union.hpp"

using namespace std;

int main() {
  cout << "\nQuick union test\n";
  cout << "==================\n";
  size_construct_test<quick_union>(10);
  quick_union c = filename_construct_test<quick_union>("graph_generate_10.txt");  
  assert(!c.is_connected(4,9));
  c.connect(4,9);
  assert(c.is_connected(8,9));
  cout << "4 to 9: " << c << '\n';

  return 0;
}

template<class T>
void size_construct_test(unsigned int a_size) {
  cout << "\nFirst test: size constructor\n";
  cout << "----------------------------\n";
  cout << "create and print:\n";
  T a(a_size);
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
  cout << "3 to 8: " << a << '\n';
  assert(a.is_connected(3,4));
  assert(a.is_connected(4,8));
  a.connect(6,5);
  cout << "6 to 5: " << a << '\n';
  a.connect(9,4);
  cout << "9 to 4: " << a << '\n';
  assert(a.is_connected(3,4));
  assert(a.is_connected(4,8));
  assert(a.is_connected(3,9));
  assert(a.is_connected(8,9));
  a.connect(2,1);
  cout << "2 to 1: " << a << '\n';
  a.connect(2,7);
  cout << "2 to 7: " << a << '\n';
  a.connect(0,5);
  cout << "0 to 5: " << a << '\n';
  assert(!a.is_connected(0,7));
  cout << a << '\n';
  cout << "Connecting two subgraphs.\n";
  a.connect(0,1);
  cout << "0 to 1: " << a << '\n';
  assert(a.is_connected(0,7));
  cout << a << '\n';
}

template<class T>
T filename_construct_test(const char* fn1) {
  cout << "\nSecond test: filename constructor\n";
  cout << "---------------------------------\n";
  cout << "create and print:\n";
  T b(fn1);
  cout << '\t' << b << '\n';
  return b;
}
