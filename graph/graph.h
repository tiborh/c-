#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <set>
#include <ostream>
#include "point.h"
#include "path.h"

class graph {
public:
  int add_point(point);
  int add_point(char*);
  bool remove_point(char*);
  bool remove_point(point);
  int size() const { return points->size(); }
  path find_optimum_path(point,point);
private:
  std::set<point>* points;
};

#endif //GRAPH_H_INCLUDED
