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
      assert(points != 0);
    std::cout << "graph desttroy start ... \n";
    delete(points);
    std::cout << "graph destroy end.\n";
  }
  void add_point(const point& p1) { points->push_back(p1); } // copy constructor usage
  void add_route(const char* from, const char* to, double weight=1);
  int size() const { return points->size(); }
  void print_paths();
  path find_optimum_path(point,point);
  friend std::ostream& operator<<(std::ostream& os,const graph& in);
private:
  std::list<point>* points;
  point* find_point(const char*);
  void remove_point(point p1) { points->remove(p1); }
};

#endif //GRAPH_H_INCLUDED
