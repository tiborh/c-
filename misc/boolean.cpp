#include <iostream>
using namespace std;

int main() {
  int a,b,c;
  bool is_a_largest;
  cout << "Give three numbers" << endl;
  cin >> a >> b >> c;
  is_a_largest = ((a >= b) && (a >= c));
  cout << "Is 'a' largest? " << (is_a_largest ? "true" : "false") << endl;
  return 0;
}
