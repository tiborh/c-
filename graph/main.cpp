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
  point pb = point("B");
  cout << "pb: " << pb << '\n';
  cout << "adding routes to some other points\n";
  pa.add_route_to(&pb);
  point pc = point("C");
  pa.add_route_to(&pc,2);
  cout << "a: " << pa << '\n';

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
  cout << "Creating two more paths and adding them to path:\n";
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
  cout << "adding the rest of the routes\n";
  ga.add_route("A","B");
  ga.add_route("A","C",3);
  ga.add_route("C","A",2);
  cout << "ga:" << ga;
  return 0;
}
