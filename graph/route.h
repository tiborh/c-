#ifndef ROUTE_H_INCLUDED
#define ROUTE_H_INCLUDED

#include <cassert>
#include <iostream>
#include <ostream>
#include <string>

class point;

class route {
public:
  route(): from(0),to(0),weight(0),trodden(false) {}
  route(point* from_point, point* to_point, double route_weight = 1,bool troddenness = false) :
    from(from_point),
    to(to_point),
    weight(route_weight),
    trodden(troddenness)
  {
    assert(from_point != 0 && to_point != 0 && route_weight != 0);
  }
  const char* get_from_id() const;
  const char* get_to_id() const;
  double get_weight() const { return weight; }
  bool is_trodden() const { return trodden; }
  double tread() {
    assert(!trodden);	// rule: once only
    trodden = true;
    return(weight);
  }
  void untread() { trodden = false; }
  int operator==(const route& other) {
    if ((this->from == other.from) && (this->to == other.to))
      return 0;
    return 1;
  }
  friend class graph_walker;
  friend std::ostream& operator<<(std::ostream&,const route&);
private:
  point* from;
  point* to;
  double weight;
  bool trodden;
  point* get_to() const { return to; }
};

#endif //ROUTE_H_INCLUDED
