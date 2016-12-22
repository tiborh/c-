#include <iostream>
#include <ostream>

using namespace std;

// by default, members are public
struct Point {
  double x,y;
  void swap();
};

void Point::swap() {
  double temp = this->x;
  this->x = this->y;
  this->y = temp;
}

ostream& operator<<(ostream& out, const Point& aPoint) {
  out << "(" << aPoint.x << ", " << aPoint.y << ")";
  return out;
}

int main() {
  Point p, *pt = &p;
  p.x = 1.0;
  p.y = 2.0;

  cout << "The created point: " << p << endl;

  cout << "Changing value through a pointer: ";
  pt->x = 3.4;
  pt->y = 5.2;
  cout << *pt << endl;

  cout << "Changing value through dereferenced pointer: ";
  (*pt).x = 2.5;
  (*pt).y = 3.4;
  cout << *pt << endl;

  cout << "Swapping point coordinates: ";
  pt->swap();
  cout << *pt << endl;

  cout << "Using an anonymous structure: ";
  struct {
    int a,b,c;
  } triples[3] = {{1,2,3},
		  {4,5,6},
		  {7,8,9}};

  cout << triples[0].a << ", " << triples[0].b << ", " << triples[0].c << endl;

  
  return 0;
}
