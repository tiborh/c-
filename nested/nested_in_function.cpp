#include <iostream>
#include <ostream>

using namespace std;

bool foo() {
  struct local {
    int a;
    double b;
  } x;
  x.a = 0;
  x.b = 0.0;
  return x.a == x.b;
}

int main() {
  cout << "nested class in a function cannot be accessed.\n" << !foo() << endl;
  return 0;
}
