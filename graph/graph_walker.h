#ifndef GRAPH_WALKER_H_INCLUDED
#define GRAPH_WALKER_H_INCLUDED

#include <iostream>
#include <string>
#include "point.h"
#include "graph.h"
#include "string_path.h"
#include "route.h"

using namespace std;

class graph_walker {
public:
  static void init() { paths = std::map<std::string,string_path>(); }
  static void walker_wrapper(graph,const char*);
private:
  static std::map<std::string,string_path> paths;
  static void walker(graph, string_path, const char*);
};

#endif //GRAPH_WALKER_H_INCLUDED
