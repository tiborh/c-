#include "point.h"

#include <iostream>

void point::add_route_to(point* other,double route_weight, bool troddenness) {
  route to_other = route(this,other,route_weight,troddenness);
  routes_out[std::string(other->id)] = to_other;
}

void point::unvisit() {
  visited = false;
  for (std::map<std::string,route>::iterator it=routes_out.begin(); it != routes_out.end(); ++it)
    it->second.untread();
}

std::ostream& operator<<(std::ostream& os, const point& pt) {
  os << "\n\tPoint ID: " << pt.id;
  os << " (" << (pt.visited ? "visited" : "unvisited" ) << ")\n";
  if (pt.routes_out.size() == 0)
    std::cout << "\tNo routes from this point yet.\n";
  else {
    os << "\tRoutes: ";
    for (std::map<std::string,route>::iterator it = pt.get_routes().begin();
	 it != pt.get_routes().end(); ++it)
      os << it->second << '\n';
    // for (unsigned int i = 0; i < pt.routes_out.size(); ++i)
    //   os << pt.get_routes().at(i) << '\n';
  }
  return os;
}
