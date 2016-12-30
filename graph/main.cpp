#include <iostream>

using namespace std;

#include "point.h"

int main() {
  cout << "\npoint test:\n";
  cout << "=============\n";
  point *a = new point("A");
  cout << "a: " << a << '\n';
  point *b = new point("B");
  cout << "b: " << b << '\n';
  a->add_route_to(b);
  return 0;
}
