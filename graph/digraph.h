#ifndef DIGRAPH_H_INCLUDED
#define DIGRAPH_H_INCLUDED

#include "graph.h"

class digraph: public graph {
public:
  void add_route(const char* from, const char* to, double weight=1);
  double tread(const char*,const char*);
};

#endif //DIGRAPH_H_INCLUDED

// Local Variables:
// mode: c++
// End:
