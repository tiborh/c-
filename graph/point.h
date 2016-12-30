#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <vector>
#include <cassert>
#include <ostream>
#include "route.h"

class point {
public:
  point(const char* point_id) : id(point_id),
				routes_out(new std::vector<route>()),
				visited(false)
  {}
  ~point() { delete(routes_out); }
  const char* get_id() const { return id; }
  std::vector<route> get_routes() const { return *routes_out; }
  void add_route_to(point*);
  bool remove_route_to(point*);
  point* next_route_out();
  bool reset_route_iterator();
  void visit() {
    assert(!visited);
    visited = true;
  }
private:
  const char* id;
  std::vector<route>* routes_out;
  bool visited;
};

std::ostream& operator<<(std::ostream&,const point*&);

#endif //POINT_H_INCLUDED
