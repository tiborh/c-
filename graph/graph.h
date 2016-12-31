#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <list>
#include <ostream>
#include <cassert>
#include "point.h"
#include "path.h"

class graph {
public:
  graph(): points(new std::list<point>()){ assert(points != 0); }
  ~graph() {
    std::cout << "graph desttroy start ... \n";
    delete(points);
    std::cout << "graph destroy end.\n";
  }
  void add_point(point& p1) { points->push_back(p1); }
  void remove_point(point p1) { points->remove(p1); }
  int size() const { return points->size(); }
  path find_optimum_path(point,point);
  void self_check(); 		// this method can check of all "routes_to" points are included
  friend std::ostream& operator<<(std::ostream& os,const graph& in);
private:
  std::list<point>* points;
};



#endif //GRAPH_H_INCLUDED
