#include "bigraph.h"

void bigraph::add_route(const char* from, const char* to, double weight) {
  graph::add_route(from, to, weight);
  graph::add_route(to, from, weight);
}

double bigraph::tread(const char* p1name,const char* p2name) {
  graph::tread(p1name,p2name);
  return graph::tread(p2name,p1name);
}
