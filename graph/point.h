#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <list>
#include <cassert>
#include <ostream>
#include <cstring>
#include "route.h"

class point {
public:
  point(const char* point_id) : id(point_id),
				routes_out(new std::list<route>()),
				visited(false)
  {}
  point(const point& other): id(other.id),
			     routes_out(new std::list<route>()),
			     visited(false)
  {}
  ~point() {
    std::cout << "\n\t" << id  << ": point destroy start ... ";
    delete(routes_out);
    std::cout << "\n\tpoint destroy end.\n";
  }
  const char* get_id() const { return id; }
  std::list<route> get_routes() const { return *routes_out; }
  void add_route_to(point*,double route_weight=1);
  void remove_route_to(point* p_dest) { routes_out->remove(route(this,p_dest)); }
  point next_route_out();
  bool reset_route_iterator();
  bool is_visited() { return visited; }
  void visit() {
    assert(!visited);
    visited = true;
  }
  void unvisit();
  
  int operator==(const point& other) {
    return strcmp(this->id,other.id);
  }
  friend std::ostream& operator<<(std::ostream&,const point&);
private:
  const char* id;
  std::list<route>* routes_out;
  std::list<route>::iterator routes_it; /* make a lock, and lock can initiate iterator, and lift block from use of "routing methods". */
  bool visited;
};

#endif //POINT_H_INCLUDED
