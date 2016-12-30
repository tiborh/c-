#ifndef ROUTE_H_INCLUDED
#define ROUTE_H_INCLUDED

#include <cassert>

class point;

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
  point* where_to() const { return to; }
  double get_weight() const { return weight; }
  bool is_trodden() const { return trodden; }
  void tread() {
    assert(!trodden);	// rule: once only
    trodden = true;
  }
  void reset() { trodden = false; }
private:
  point* from;
  point* to;
  double weight;
  bool trodden;
};

#endif //ROUTE_H_INCLUDED
