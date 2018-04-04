#include <iostream>

using namespace std;

int incr_ptr(int* pa) {
  return ++(*pa);
}

int incr_ref(int& ra) {
  return ++ra;
}

int main() {

  // reference is syntax sugar
  int a = 12;
  int* pa = &a;
  int& ra = a;			// reference cannot be changed later
  // int& ra; // illegal

  cout << "a == " << a << endl;
  ++(*pa);
  cout << "a == " << a << endl;
  ++ra;
  cout << "a == " << a << endl;

  incr_ptr(&a);
  cout << "a == " << a << endl;
  incr_ref(a);
  cout << "a == " << a << endl;
  
  return 0;
}
