#include "graph.h"
//#include <iomanip>

graph::graph(const graph& other) {
  //std::cout << "inside the graph copy constructor\n";
  points = new std::list<point>();
  //std::cout << "empty list has been created\n";
  for (std::list<point>::iterator it = other.points->begin(); it != other.points->end(); ++it) {
    //std::cout << "copying: " << it->get_id();
    add_point(*it,true);
  }
  std::list<point>::iterator it_other = other.points->begin();
  std::list<point>::iterator it_this = points->begin();
  for (;it_other != other.points->end() && it_this != points->end();++it_other,++it_this) {
    assert(it_this->visited == it_other->visited);
    for(std::map<std::string,route>::iterator it=it_other->routes_out.begin();
	it != it_other->routes_out.end(); ++it) {
      it_this->add_route_to(this->find_point(it->first.c_str()),
			    it->second.get_weight(),it->second.is_trodden());
    }
  }
}

void graph::add_point(const point& p1,bool cp_visit) {
  point new_point = point(p1,cp_visit);
  points->push_back(new_point);
  if (cp_visit) {
    points->back().visited = new_point.visited;
    assert(points->back().visited == new_point.visited);
  }
}

point* graph::find_point(const char* id) {
  for (std::list<point>::iterator it=points->begin(); it != points->end(); ++it) {
    if (0 == strcmp(it->get_id(),id))
      return &*it;
  }
  return 0;
}

void graph::visit(const char* p1name) {
  point* p1 = find_point(p1name);
  assert(p1 != 0);
  p1->visit();
}

double graph::tread(const char* p1name,const char* p2name) {
  point* p1 = find_point(p1name);
  assert(p1 != 0);
  point* p2 = find_point(p2name);
  assert(p2 != 0);
  assert(p1->routes_out.find(std::string(p2->id)) != p1->routes_out.end());
  return p1->routes_out[std::string(p2->id)].tread();
}

void graph::add_route(const char* from, const char* to, double weight) {
  point* from_pt = find_point(from);
  assert(from_pt != 0);
  point* to_pt = find_point(to);
  assert(to_pt != 0);
  from_pt->add_route_to(to_pt,weight);
}

std::ostream& operator<<(std::ostream& os,const graph& in) {
  for (std::list<point>::iterator it=in.points->begin(); it != in.points->end(); ++it) {
    os << *it << '\n';
  }
  return os;
}
