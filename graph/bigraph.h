#ifndef BIGRAPH_H_INCLUDED
#define BIGRAPH_H_INCLUDED

#include "graph.h"

class bigraph: public graph {
public:
  void add_route(const char* from, const char* to, double weight=1);
  double tread(const char*,const char*);
};

#endif //BIGRAPH_H_INCLUDED

// Local Variables:
// mode: c++
// End:
