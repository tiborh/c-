#include "graph_walker.h"

std::map<std::string,string_path> graph_walker::paths;

void graph_walker::walker_wrapper(graph maze,const char* starting_point) {
  init();
  map<string,string_path> paths = map<string,string_path>();
  string_path starting_path = string_path();
  starting_path.init(starting_point);
  walker(maze, starting_path, starting_point);
  for (map<string,string_path>::iterator it = paths.begin(); it != paths.end(); ++it)
    cout << it->first << ":\n" << it->second;
}

void graph_walker::walker(graph maze, string_path spath, const char* spoint) {
  point* starting_point = maze.find_point(spoint);
  assert(starting_point != 0);
  cout << "visiting point: " << starting_point->get_id() << '\n';
  assert(!starting_point->is_visited());
  starting_point->visit();
  for(std::map<std::string,route>::iterator it=starting_point->routes_out.begin();
      it != starting_point->routes_out.end(); ++it) {
      if (!it->second.is_trodden()) {
	  it->second.tread();
	  if (!it->second.get_to()->is_visited()) {
	      spath.add_route(&it->second);
	      // cout << "graph before recursion:\n";
	      // cout << maze;
	      cout << "path so far:\n";
	      cout << spath;
	      const char* next_point = it->second.get_to()->get_id();
	      walker(maze,spath,next_point);
	  }
      }
  }
  //if (spath.size() > 0) {
    //cout << "size of path: " << spath.size() << '\n';
    //cout << "path:\n";
    //cout << spath;
    //string key = string(spath.get_first_id());
    //key.append("_");
    //key.append(spath.get_last_id());
    //cout << "key: " << key << '\n';
    //paths[key] = spath;
  //}
}
