#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <utility>
#include <ostream>

class point {
 public:
  // constructors
  point();
  point(double,double);
  // getters
  double getx();
  double gety();
  std::pair<double,double> get();
  // setters
  void setx(double);
  void sety(double);
  // operators
  point operator+ (const point&);
 private:
  double x,y;
};
/* must be non-member: */
std::ostream& operator<< (std::ostream&, point);
#endif // POINT_H_INCLUDED
