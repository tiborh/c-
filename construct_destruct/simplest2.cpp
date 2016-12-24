#include <iostream>

using namespace std;

struct simplest {
  int i;
  simplest(int i = 0): i(i) {}
};

struct simplest2 {
  int i;
  explicit simplest2(int i = 0): i(i) {}
};


int main() {
  cout << "Even simpler than \"simplest\" is direct assignment.\n";
  simplest a;
  cout << "a.i: " << a.i << endl;
  a = 1;
  cout << "a.i: " << a.i << endl;
  // equivalent to:
  cout << "A little more explicit is cast and assign:\n";
  a = static_cast<simplest>(2);
  cout << "a.i: " << a.i << endl;

  simplest2 b;
  //b = 3;			// results in error
  // several errors, but only the second helps:
  // no known conversion for argument...
  b = static_cast<simplest2>(3); // same error
  cout << "b.i: " << b.i << endl;
  
  return 0;
}
