#include <iostream>

struct simplest {
  int i;
  simplest(int i = 0): i(i) {}
  simplest(const simplest& other) { // copy constructor
    i = other.i;
  }
};

using namespace std;

int main() {
  simplest a = simplest(3);
  cout << "a has been created with an integer.\n";
  cout << "a.i: " << a.i << endl;
  simplest b = simplest(a);
  cout << "b has been created with 'a' as a constructor.\n";
  cout << "b.i: " << b.i << endl;

  return 0;
}
