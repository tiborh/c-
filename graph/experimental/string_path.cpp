#include "string_path.h"

string_path::string_path(const string_path& other) {
  points = std::deque<std::string>();
  for (std::deque<std::string>::const_iterator it = other.points.begin(); it != other.points.end(); ++it)
    points.push_back(*it);
  weight_sum = other.weight_sum;
}

std::ostream& operator<<(std::ostream& os, const string_path& pth) {
  for (std::deque<std::string>::const_iterator it = pth.points.begin(); it != pth.points.end(); ++it)
    os << '\t' << *it << '\n';
  os << "sum of weights: " << pth.weight_sum << '\n';
  return os;
}
