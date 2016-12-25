#include <iostream>
#include "dbl_vect.h"

using namespace std;

int main() {
  dbl_vect a = dbl_vect(5);
  cout << "'a' after creation: " << a << endl;
  a[0] = 1;
  a.at(1) = 2;
  cout << "'a' after two assignments: " << a << endl;
  dbl_vect b = dbl_vect(a);
  cout << "'b' after its creation from 'a': " << b << endl;
  b[2] = 3;
  b[3] = 4;
  b[4] = 5;
  cout << "'b' after three assignments: " << b << endl;
  cout << "Checking if 'a' is independent of b: " << a << endl;
  assert(a.get(3) == 0);
  
  return 0;
}
