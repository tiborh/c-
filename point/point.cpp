#include "point.h"

// constructors
point::point(double x, double y) : x(x), y(y) {}
point::point() : x(0.0),y(0.0) {}
  
// getters
double point::getx() {return x;}
double point::gety() {return y;}
std::pair<double,double> point::get() { return std::pair<double,double>(x,y); }

//setters
void point::setx(double v) { x = v; }
void point::sety(double v) { y = v; }

//operators
point point::operator+ (const point& other) {
  const point sum = {x + other.x, y + other.y};
  return sum;
}
std::ostream& operator<< (std::ostream& out, point p) {
  out << "(" << p.getx() << ", " << p.gety() << ")";
  return out;
}

