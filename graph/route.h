#ifndef ROUTE_H_INCLUDED
#define ROUTE_H_INCLUDED

#include <cassert>
#include <iostream>
#include <ostream>

class point;			// route may be better off as a subclass of point

class route {
public:
  route(point* from_point, point* to_point, double route_weight = 1) :
    from(from_point),
    to(to_point),
    weight(route_weight),
    trodden(false)
  {
    assert(from_point != 0 && to_point != 0 && route_weight != 0);
  }
  //~route() { std::cout << "\n\t\troute destruction\n"; } // comment out to avoid "double free or corruption"
  point* get_origin() const { return from; }
  point* get_destination() const { return to; }
  double get_weight() const { return weight; }
  bool is_trodden() const { return trodden; }
  void tread() {
    assert(!trodden);	// rule: once only
    trodden = true;
  }
  void reset() { trodden = false; }
  int operator==(const route& other) {
    if ((this->from == other.from) && (this->to == other.to))
      return 0;
    return 1;
  }
  friend std::ostream& operator<<(std::ostream&,const route&);
private:
  point* from;
  point* to;
  double weight;
  bool trodden;
};

#endif //ROUTE_H_INCLUDED
