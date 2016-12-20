#include <iostream>
#include "point.h"

using namespace std;

int main() {
  cout << "Counstruct without parameters." << endl;
  point a = point();
  cout << "A point has been created." << endl;
  cout << "Gets x: " << a.getx() << endl; 
  cout << "Sets x to 12." << endl;
  a.setx(12);
  cout << "Gets x: " << a.getx() << endl;
  cout << "Sets y to 3." << endl;
  a.sety(3);
  cout << "Gets y: " << a.gety() << endl;
  cout << "Construct with parameters." << endl;
  point b = point(1.2,2.0);
  cout << "Gets: " << b.getx() << endl;
  // the long way:
  cout << "Get both: (" << get<0>(b.get()) << ", " << get<1>(b.get()) << ")" << endl;
  // the short way after the implementation of operator<<
  cout << "Sum of two points: " << a+b << endl;
  //create in another way:
  point c = {3.4,4.3};
  cout << "Point three: " << c << endl;
  return 0;
}
