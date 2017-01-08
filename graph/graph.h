#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <list>
#include <string>
#include <ostream>
#include <cassert>
#include "point.h"
#include "path.h"

class graph {
public:
  graph(): points(new std::list<point>()){ assert(points != 0); }
  graph(const graph&);
  ~graph() {
    assert(points != 0);
    delete(points);
  }
  void add_point(const point& p1,bool cp_visit = false);
  void add_route(const char* from, const char* to, double weight=1);
  void visit(const char*);
  double tread(const char*,const char*);
  int size() const { return points->size(); }
  friend std::ostream& operator<<(std::ostream& os,const graph& in);
private:
  std::list<point>* points;
  point* find_point(const char*);
  void remove_point(point p1) { points->remove(p1); }
};

#endif //GRAPH_H_INCLUDED
