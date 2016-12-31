#include <iostream>

using namespace std;

#include "point.h"
#include "graph.h"

int main() {
  cout << "\npoint test:\n";
  cout << "=============\n";
  point pa = point("A");
  cout << "pa: " << pa << '\n';
  point pb = point("B");
  cout << "pb: " << pb << '\n';
  cout << "adding routes to some other points\n";
  pa.add_route_to(&pb);
  point pc = point("C");
  pa.add_route_to(&pc,2);
  cout << "a: " << pa << '\n';

  cout << "\nGraph test:\n";
  cout << "=============\n";
  graph ga = graph();
  cout << "adding A, which already has routes:\n";
  ga.add_point(pa);
  cout << "ga:" << ga;
  cout << "adding the remaining two points:\n";
  ga.add_point(pb);
  ga.add_point(pc);
  cout << "ga:" << ga;
  cout << "adding a route from B to C\n";
  pc.add_route_to(&pb);
  cout << "ga:" << ga;
  // cout << "self-referential B\n";
  // pb.add_route_to(&pb);
  // cout << "ga:" << ga;
  return 0;
}
