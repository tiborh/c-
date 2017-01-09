#ifndef STRING_PATH_H_INCLUDED
#define STRING_PATH_H_INCLUDED

#include <deque>
#include <cassert>
#include "point.h"

class string_path {
public:
  string_path(): points(std::deque<std::string>()),weight_sum(0) {}
  string_path(const string_path& other);
  // ~string_path() {
  //   //std::cout << "\nstring_path destroy start ... ";
  //   delete(points);
  //   //std::cout << " string_path destroy end.\n";
  // }
  void add_route(route* rt) {
    points.push_back(std::string(rt->get_to_id()));
    weight_sum += rt->get_weight();
  }
  void init(const char* first_point) { points.push_back(std::string(first_point)); }
  //std::deque<std::pair<point*,double>> get_string_path() const { return *points; }
  double get_weight_sum() const { return weight_sum; }
  int size() const { return points.size(); }
  const char* get_first_id() const { return points.front().c_str(); }
  const char* get_last_id() const { return points.back().c_str(); }
  //void check_integrity();	// to see if one finishes, where the next starts
  friend std::ostream& operator<<(std::ostream&, const string_path&);
private:
  std::deque<std::string> points;
  double weight_sum;
};

#endif //STRING_PATH_H_INCLUDED

