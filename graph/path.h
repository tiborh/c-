#ifndef PATH_H_INCLUDED
#define PATH_H_INCLUDED

#include <deque>
#include <cassert>
#include "point.h"

class path {
public:
  path(): routes(new std::deque<route*>()),weight_sum(0) {}
  ~path() {
    std::cout << "\npath destroy start ... ";
    delete(routes);
    std::cout << " path destroy end.\n";
  }
  void add_route(route* rt) {
    routes->push_back(rt);
    weight_sum += rt->get_weight();
  }
  //std::deque<std::pair<point*,double>> get_path() const { return *points; }
  double get_weight_sum() const { return weight_sum; }
  void check_integrity();	// to see if one finishes, where the next starts
  friend std::ostream& operator<<(std::ostream&, const path&);
private:
  std::deque<route*>* routes;
  double weight_sum;
};

#endif //PATH_H_INCLUDED

