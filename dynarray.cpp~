#include <iostream>

using namespace std;

int main() {
  int* anInt = new int(4);

  cout << "an integer: " << *anInt << endl;
  cout << "its address: " << anInt << endl;

  cout << "delete(theInt)" << endl;
  delete(anInt);

  cout << "an integer: " << *anInt << endl; // no error, but value is zero
  cout << "its address: " << anInt << endl; // address is the same
  
  return 0;
}
