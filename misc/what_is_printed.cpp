#include <iostream>
using namespace std;

int main()
{
  char c = 'A';
  int i = 3, j = 1, k = -2, m = 0;
  bool p = false, q = true;

  cout << '\'' << c << "' has integer value " << int(c)
       << " and '!" << c << "' is " << !c << endl;
  cout << "i == " << i << ", !i == " << !i 
        << ", !!i == " << !!i << endl;
  cout << "m == " << m << ", !m == " << !m << endl;
  cout << "p == " << p << ", !" << q << " == " << !q << endl;
  cout << "!(i + j) || m == " << (!(i + j) || m) << endl;
  cout << "p == " << p << ", q == " << q << ", j == " << j << endl;
  cout << "q || (j / m) == " << (q || (j / m)) << endl;
  cout << "(j / m) || q == " << ((j / m) || q) << endl; // floating point exception
  
  return 0;
}
