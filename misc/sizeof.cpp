#include <iostream>
using namespace std;

int main()
{
  cout << "sizeof(bool) == " << sizeof(bool) << endl;
  cout << "sizeof(char) == " << sizeof(char) << endl;
  cout << "sizeof(short) == " << sizeof(short) << endl;
  cout << "sizeof(int) == " << sizeof(int) << endl;
  cout << "sizeof(long) == " << sizeof(long) << endl;
  cout << "sizeof(long long) == " << sizeof(long long) << endl;
  cout << "sizeof(float) == " << sizeof(float) << endl;
  cout << "sizeof(double) == " << sizeof(double) << endl;
  cout << "sizeof(long double) == " << sizeof(long double) << endl;
  enum bounds { lb = -1, ub = 511 };
  cout << "sizeof(bounds) == " << sizeof(bounds) << endl;
  enum suit { clubs, diamonds, hearts, spades };
  cout << "sizeof(suit) == " << sizeof(suit) << endl;
  return 0;
}
