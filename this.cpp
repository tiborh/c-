#include <iostream>

using namespace std;

struct something {
  something* address() { return this; }
};

int main() {
  something a = something();
  cout << "Address of a: " << a.address() << endl;
  return 0;
}
