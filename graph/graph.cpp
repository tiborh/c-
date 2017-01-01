#include "graph.h"

point* graph::find_point(const char* id) {
  for (std::list<point>::iterator it=points->begin(); it != points->end(); ++it) {
    if (0 == strcmp(it->get_id(),id))
      return &*it;
  }
  return 0;
}

void graph::add_route(const char* from, const char* to, double weight) {
  point* from_pt = find_point(from);
  assert(from_pt != 0);
  point* to_pt = find_point(to);
  assert(to_pt != 0);
  from_pt->add_route_to(to_pt,weight);
}

std::ostream& operator<<(std::ostream& os,const graph& in) {
  for (std::list<point>::iterator it=in.points->begin(); it != in.points->end(); ++it) {
    os << *it << '\n';
  }
  return os;
}
