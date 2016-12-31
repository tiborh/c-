#include "graph.h"

std::ostream& operator<<(std::ostream& os,const graph& in) {
  for (std::list<point>::iterator it=in.points->begin(); it != in.points->end(); ++it) {
    os << *it << '\n';
  }
  return os;
}
