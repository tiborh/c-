#include "path.h"

path::path(const path& other) {
  routes = std::deque<route*>();
  for (std::deque<route*>::const_iterator it = other.routes.begin(); it != other.routes.end(); ++it)
    routes.push_back(*it);
  weight_sum = other.weight_sum;
}

std::ostream& operator<<(std::ostream& os, const path& pth) {
  for (std::deque<route*>::const_iterator it = pth.routes.begin(); it != pth.routes.end(); ++it)
    os << **it;
  os << "sum of weights: " << pth.weight_sum << '\n';
  return os;
}
