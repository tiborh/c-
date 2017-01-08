#include <iostream>

using namespace std;

#include "point.h"
#include "graph.h"
#include "path.h"

int main() {
  cout << "\npoint demo:\n";
  cout << "=============\n";
  point pa = point("A");
  cout << "pa: " << pa << '\n';
  cout << "visiting A:\n";
  pa.visit();
  assert(pa.is_visited());
  cout << "pa: " << pa << '\n';
  point pb = point("B");
  cout << "pb: " << pb << '\n';
  cout << "adding routes to some other points\n";
  pa.add_route_to(&pb);
  point pc = point("C");
  pa.add_route_to(&pc,2);
  cout << "pa: " << pa << '\n';
  cout << "creating D from A (and adding route to B):\n";
  point pd = point(pa,true);
  assert(pd.is_visited());
  cout << "pd: " << pd << '\n';
  pd.add_route_to(&pb,2);

  cout << "\nroute demo:\n";
  cout << "=============\n";
  route rab = route(&pa,&pb);
  cout << "Route from A to B: " << rab;
  cout << "treadnig the road: ";
  rab.tread();
  cout << rab;
  cout << "untreadnig the road: ";
  rab.untread();
  cout << rab;

  cout << "\npath demo:\n";
  cout << "=============\n";
  cout << "Creating two more routes and adding them to path:\n";
  route rbc = route(&pb,&pc,2);
  route rca = route(&pc,&pa,3);  
  path ptha = path();
  ptha.add_route(&rab);
  ptha.add_route(&rbc);
  ptha.add_route(&rca);
  cout << ptha << '\n';
  
  cout << "\nGraph demo:\n";
  cout << "=============\n";
  graph ga = graph();
  cout << "adding A, the copy construct does not copy routes:\n";
  ga.add_point(pa);
  cout << "ga:" << ga;
  cout << "adding the remaining two points:\n";
  ga.add_point(pb);
  ga.add_point(pc);
  cout << "ga:" << ga;
  cout << "adding a route from B to C\n";
  ga.add_route("B","C",2);
  cout << "ga:" << ga;
  cout << "treading the new route\n";
  ga.tread("B","C");
  cout << "ga:" << ga;
  cout << "adding the rest of the routes\n";
  ga.add_route("A","B");
  ga.add_route("A","C",3);
  ga.add_route("C","A",2);
  cout << "ga:" << ga;
  cout << "visiting A:\n";
  ga.visit("A");
  cout << ga;
  cout << "Adding D:";
  ga.add_point(pd,true);
  cout << ga;

  cout << "\nGraph copy demo:\n";
  cout << "==================\n";
  graph gb = graph(ga);
  cout << "graph b (gb) created from graph a (ga):\n";
  cout << gb;
  return 0;
}
