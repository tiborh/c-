#include <iostream>

using namespace std;

struct a {
  const int i;
  a(int i=0): i(i) {}
};

int main() {
  cout << "const params can only be initialised with constructor initialisers\n";
  a a1 = a();
  a a2 = a(1);
  cout << "a1.i: " << a1.i << endl;
  cout << "a2.i: " << a2.i << endl;
  
  return 0;
}
