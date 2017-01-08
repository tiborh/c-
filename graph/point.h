#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <list>
#include <map>
#include <string>
#include <cassert>
#include <ostream>
#include <cstring>
#include "route.h"

class point {
public:
  point(const char* point_id,bool visitedness = false) : id(point_id),
							 //routes_out(std::map<std::string,route>()),
							 visited(visitedness)
  {}
  point(const point& other,bool copy_visitedness = false): id(other.id),
							   //routes_out(std::map<std::string,route>()),
							   visited(copy_visitedness ? other.visited : false)
  {}
  ~point() {
    //std::cout << "\n\t" << id  << ": point destroy start ... ";
    routes_out.clear();
    //std::cout << "\n\tpoint destroy end.\n";
  }
  const char* get_id() const { return id; }
  void add_route_to(point*,double route_weight=1,bool troddenness = false);
  void remove_route_to(point* p_dest) { routes_out.erase(std::string(p_dest->id)); }
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
  friend class graph;
private:
  const char* id;
  std::map<std::string,route> routes_out;
  bool visited;
  std::map<std::string,route> get_routes() const { return routes_out; }
};

#endif //POINT_H_INCLUDED
