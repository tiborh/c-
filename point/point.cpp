#include "point.h"

// constructors
point::point(const double& x, const double& y) : x(x), y(y) {}
  
// getters
double point::getx() const {return x;}
double point::gety() const {return y;}
std::pair<double,double> point::get() const {
  return std::pair<double,double>(x,y);
}

//setters
void point::setx(const double& v) { x = v; }
void point::sety(const double& v) { y = v; }

//operators
point point::operator+ (const point& other) {
  const point sum = {x + other.x, y + other.y};
  return sum;
}
std::ostream& operator<< (std::ostream& out, point p) {
  out << "(" << p.getx() << ", " << p.gety() << ")";
  return out;
}

