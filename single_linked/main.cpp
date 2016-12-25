#include <iostream>
#include "slist.h"

using namespace std;

int main() {
  slist a = slist();
  cout << "empty list created: " << a << endl;
  slist b = slist('a');		// segmentation fault. check linking
  //cout << "one created with a char: " << b << endl; // bug: lots of x's
  return 0;
}
