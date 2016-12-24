#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <utility>
#include <ostream>

class point {
 public:
  // constructors
  point(const double& x = 0.0, const double& y = 0.0);
  // getters
  double getx() const;
  double gety() const;
  std::pair<double,double> get() const;
  // setters
  void setx(const double&);
  void sety(const double&);
  // operators
  point operator+ (const point&);
 private:
  double x,y;
};
/* must be non-member: */
std::ostream& operator<< (std::ostream&, point);
#endif // POINT_H_INCLUDED
