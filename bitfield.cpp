#include <iostream>

using namespace std;

struct pcard {
  unsigned s : 2;
  unsigned p : 4;
};

int main() {
  pcard a = pcard();

  cout << "a.s: " << a.s << endl;
  cout << "a.p: " << a.p << endl;
  cout << "quite unclear what practical use this can come to.\n";
  
  return 0;
}
