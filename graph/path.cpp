#include "path.h"

std::ostream& operator<<(std::ostream& os, const path& pth) {
  for (std::deque<route*>::iterator it = pth.routes->begin(); it != pth.routes->end(); ++it)
    os << **it;
  os << "sum of weights: " << pth.weight_sum;
  return os;
}
