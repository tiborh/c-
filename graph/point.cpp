#include "point.h"

#include <iostream>

void point::add_route_to(point* other) {
  route to_other = route(this,other);
  routes_out->push_back(to_other);
}

std::ostream& operator<<(std::ostream& os, const point*& pt) {
  os << pt->get_id() << ":\n";
  std::vector<route> myroutes = pt->get_routes();
  if (myroutes.size() == 0)
    std::cout << "\tNo routes from this point yet.\n";
  else
    for (unsigned int i = 0; i < myroutes.size(); ++i)
      os << '\t' << myroutes.at(i).where_to()->get_id() << '\n';
  return os;
}
