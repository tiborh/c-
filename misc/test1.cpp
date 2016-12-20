#include <iostream>
using namespace std;

int main()
{
  cout << "Program to find area of a trapezium\n";

  int a,b,h;
  float area;

  cout << "Enter lengths of parallel sides a and b, and height: ";
  cin >> a >> b >> h;

  area = (h/2)*(a+b);

  cout << "The area is " << area;

  return 0;
}
