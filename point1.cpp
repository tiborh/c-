#include <iostream>
#include <ostream>

using namespace std;

struct point {
  point(double a = 0.0, double b = 0.0): x(a),y(b) {}
  friend point operator+(const point& ,const point&);
  friend ostream& operator<<(ostream&, const point&);
private:
  double x,y;
};

point operator+(const point& p1, const point& p2) {
  return point(p1.x + p2.x, p1.y + p2.y);
}

ostream& operator<<(ostream& os, const point& p) {
  os << "(" << p.x << "," << p.y << ")";
  return os;
}

int main() {
  point a = point();
  double d0 = 3.3;
  point b = point(d0);
  point c = point(1.5,2.5);

  cout << "a: " << a << '\n';
  cout << "b: " << b << '\n';
  cout << "c: " << c << '\n';

  cout << "b + c: " << b + c << '\n';

  cout << "d0: " << d0 << '\n';
  cout << "d0 + c: " << d0 + c << '\n';
  // the friend function solution employs implicit conversion
  
  return 0;
}
