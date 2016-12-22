#include <iostream>
#include <ostream>

using namespace std;

struct something {
  int a;
  mutable int b;
  something(int a, int b): a(a),b(b) {};
};

ostream& operator<<(ostream& os, something so) {
  os << "a: " << so.a << ", b: " << so.b;
  return os;
}

int main() {
  const something a = something(1,2);
  cout << "a: " << a << endl;
  cout << "Even if a is constant, b remains mutable.\n";
  a.b = 5;
  cout << "a: " << a << endl;
  //a.a = -5;			// would result in a compile-time error
  // a.a is a read-only object
  return 0;
}
