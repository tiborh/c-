#include "point.h"

#include <iostream>

void point::add_route_to(point* other,double route_weight) {
  route to_other = route(this,other,route_weight);
  routes_out->push_back(to_other);
}

std::ostream& operator<<(std::ostream& os, const point& pt) {
  os << "\n\tPoint ID: " << pt.id << "\n";
  if (pt.routes_out->size() == 0)
    std::cout << "\tNo routes from this point yet.\n";
  else {
    os << "\tRoutes: ";
    for (std::list<route>::iterator it=pt.routes_out->begin(); it != pt.routes_out->end(); ++it)
      os << *it << '\n';
  }
  return os;
}
