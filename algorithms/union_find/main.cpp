#include <iostream>

#include "main.hpp"
#include "quick_find.hpp"
#include "quick_union.hpp"
#include "quick_union_lazy.hpp"
#include "quick_union_shorter.hpp"
#include "quick_union_compress.hpp"

using namespace std;

int main() {
  cout << "\nQuick find test\n";
  cout << "===============\n";
  size_construct_test<quick_find>(10);
  quick_find b = filename_construct_test<quick_find>("graph_generate_5.txt");
  assert(b.is_connected(0,2));
  assert(!b.is_connected(2,3));

  cout << "\nQuick union test\n";
  cout << "==================\n";
  size_construct_test<quick_union>(10);
  quick_union c = filename_construct_test<quick_union>("graph_generate_10.txt");  
  assert(!c.is_connected(4,9));
  c.connect(4,9);
  assert(c.is_connected(8,9));
  cout << "4 to 9: " << c << '\n';

  cout << "\nTest of lazy quick union\n";
  cout << "==========================\n";
  size_construct_test<quick_union_lazy>(10);
  quick_union_lazy d = filename_construct_test<quick_union_lazy>("graph_generate_10.txt");  
  assert(!d.is_connected(4,9));
  d.connect(4,9);
  assert(d.is_connected(8,9));
  cout << "4 to 9: " << d << '\n';

  cout << "\nTest of shorter connect quick union\n";
  cout << "=====================================\n";
  size_construct_test<quick_union_shorter>(10);
  quick_union_shorter e = filename_construct_test<quick_union_shorter>("graph_generate_10.txt");  
  assert(!e.is_connected(4,9));
  e.connect(4,9);
  assert(e.is_connected(8,9));
  cout << "4 to 9: " << e << '\n';

  cout << "\nTest of shorter, compressing connect quick union\n";
  cout << "==================================================\n";
  size_construct_test<quick_union_compress>(10);
  quick_union_compress f = filename_construct_test<quick_union_compress>("graph_generate_10.txt");  
  assert(!f.is_connected(1,9));
  f.connect(1,9);
  assert(f.is_connected(1,9));
  cout << "1 to 9: " << f << '\n';
  
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
  cout << b << '\n';
  return b;
}
