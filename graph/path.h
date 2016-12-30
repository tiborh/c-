#ifndef PATH_H_INCLUDED
#define PATH_H_INCLUDED

#include <forward_list>
#include <cassert>
#include "point.h"

class path {
public:
  path(point* first_point): points(new std::forward_list<std::pair<point*,double>>()),
			    weight_sum(0)
  {
    points->push_front(std::pair<point*,double>(first_point,0));
    assert(points!=0);
  }
  ~path() { delete(points); }
  void add_point(point* next_point,double route_weight) {
    points->push_front(std::pair<point*,double>(next_point,route_weight));
    weight_sum += route_weight;
  }
  std::forward_list<std::pair<point*,double>> get_path() const { return *points; }
  double get_weight_sum() const { return weight_sum; }
private:
  std::forward_list<std::pair<point*,double>>* points;
  double weight_sum;
};

#endif //PATH_H_INCLUDED

