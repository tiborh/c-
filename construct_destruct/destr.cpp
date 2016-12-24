#include <iostream>

struct a {
  int* i;
  a(int a = 0, int b = 0) {
    i = new int[2];
    i[0] = a;
    i[1] = b;
  }
  ~a() {delete[] i;}
};

using namespace std;

int main() {
  a a1 = a(1,2);
  cout << "destructor to 'a' is needed because it has been constructed dynamically.\n";
  cout << "a1.i[0]: " << a1.i[0] << ", a1.i[1]: " << a1.i[1] << endl;
  
  return 0;
}
