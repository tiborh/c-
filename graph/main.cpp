#include <iostream>
#include <set>
#include "main.h"

using namespace std;
//#include "graph_walker.h"

int main(int argc, char** argv) {
  set<string> args = set<string>();
  for(int i = 0; i < argc; ++i)
    args.insert(string(argv[i]));
  if (args.find(string("point")) != args.end())
      point_demo();
  if (args.find(string("route")) != args.end())
    route_demo();
  if (args.find(string("path")) != args.end())
    path_demo();
  if (args.find(string("graph")) != args.end()) {
    graph ga = graph_demo();
    graph_copy_demo(ga);
  }
  if (args.find(string("bigraph")) != args.end())
    bigraph_demo();
  return 0;
}

void point_demo() {
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
  cout << "creating E from A with new name:\n";
  point pe = point(pa,false,false,"E");
  cout << pe << '\n';
  assert(strcmp(pe.get_id(),"E") == 0);
}

void route_demo() {
  point pa = point("A");
  point pb = point("B");
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
}

void path_demo() { 
  point pa = point("A");
  point pb = point("B");
  point pc = point("C");
  point pd = point(pa,true,false,"D");
  cout << "\npath demo:\n";
  cout << "=============\n";
  cout << "Creating three routes and adding them to path:\n";
  route rab = route(&pa,&pb);
  route rbc = route(&pb,&pc,2);
  route rca = route(&pc,&pa,3);  
  path ptha = path();
  ptha.add_route(&rab);
  ptha.add_route(&rbc);
  ptha.add_route(&rca);
  cout << ptha << '\n';
  cout << "creating a path B from path A:\n";
  path pthb = path(ptha);
  cout << pthb;
  assert(ptha.size() == pthb.size());
  assert(ptha.get_weight_sum() == pthb.get_weight_sum());
  cout << "adding a route to path B:\n";
  route rdb = route(&pd,&pb,2);
  pthb.add_route(&rdb);
  cout << pthb;
  cout << "checking if path A has changed too:\n";
  cout << ptha;
  assert(ptha.size()+1 == pthb.size());
  assert(ptha.get_weight_sum()+rdb.get_weight() == pthb.get_weight_sum());
}

graph graph_demo() {
  point pa = point("A");
  point pb = point("B");
  point pc = point("C");
  point pd = point(pa,true,false,"D");
  cout << "\nGraph demo:\n";
  cout << "=============\n";
  graph ga = graph();
  cout << "adding A, the copy construct does not copy routes:\n";
  ga.add_point(pa,false,true);
  cout << "ga:" << ga;
  cout << "adding the remaining two points:\n";
  ga.add_point(pb,false,true);
  ga.add_point(pc,false,true);
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
  ga.add_point(pd,true,false,"D");
  cout << ga;

  return ga;
}

void graph_copy_demo(const graph &ga) {
  cout << "\nGraph copy demo:\n";
  cout << "==================\n";
  graph gb = graph(ga);
  cout << "graph b (gb) created from graph a (ga):\n";
  cout << gb;
  cout << "adding routes to point D:\n";
  gb.add_route("D","B");
  gb.add_route("C","D");
  cout << gb;
  cout << "resetting graph B:\n";
  gb.reset();
  cout << gb;
}

void bigraph_demo() {
  point pa = point("A");
  point pb = point("B");
  point pc = point("C");
  cout << "\nBiGraph demo:\n";
  cout << "=============\n";
  bigraph bga = bigraph();
  cout << "adding the three points:\n";
  bga.add_point(pa,false,true);
  bga.add_point(pb,false,true);
  bga.add_point(pc,false,true);
  cout << "bga:" << bga;
  cout << "adding the routes:\n";
  bga.add_route("B","C",2);
  bga.add_route("C","A",3);
  cout << "bga:" << bga;
  cout << "tread test:\n";
  bga.tread("A","C");
  cout << "bga:" << bga;
}
