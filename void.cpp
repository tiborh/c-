#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

int foo(int upper_limit) {
  srand((unsigned)time(0)); 
  return (rand()%upper_limit)+1;   
}

int main(void) {
  int i = 12;
  int* pt_i = &i;
  void *gp = pt_i;
  cout << "original value: " << i << endl;
  cout << "pointer to value: " << pt_i << endl;
  cout << "dereferenced: " << *pt_i << endl;
  cout << "generic pointer pointing at the same: " << gp << endl;
  //cout << "Same atempt at the generic pointer fails: " << *gp << endl;
  cout << "Same atempt at the generic pointer fails with \"‘void*’ is not a pointer-to-object type\"\n";
  cout << "generated random number: " << foo(100) << endl;
  cout << "Casting away the return value: static_cast<void>(foo(k))\n";
  static_cast<void>(foo(10));	// attempt to save result will meet this message:
  // error: void value not ignored as it ought to be
}
