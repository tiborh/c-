#include <iostream>
#include <ostream>

using namespace std;

// by default, members are public
struct Point {
  Point() : x(0),y(0) {};
  Point(double x, double y) : x(x),y(y) {};
  Point operator+ (const Point&);
  void set(double x, double y) {this->x = x; this->y = y;};
  double getx() { return x; }
  double gety() { return y; }
  void swap();
private:
  double x,y;
};

Point Point::operator+ (const Point& other) {
  const Point sum = {this->x + other.x, this->y + other.y};
  return sum;
}

void Point::swap() {
  double temp = this->x;
  this->x = this->y;
  this->y = temp;
}

ostream& operator<<(ostream& out, Point aPoint) {
  out << "(" << aPoint.getx() << ", " << aPoint.gety() << ")";
  return out;
}

int main() {
  Point a = Point();
  Point b = Point(1.2,2.4);

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;

  a.set(4.5,7.8);
  cout << "a (after 'set'): " << a << endl;
  
  Point c = a + b;
  cout << "a + b: " << c << endl;
  
  return 0;
}
