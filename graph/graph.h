#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <list>
#include <string>
#include <ostream>
#include <cassert>
#include "point.h"
#include "path.h"

class graph {
public:
  graph(): points(std::list<point>()){ assert(points.size() == 0); }
  graph(const graph&);
  ~graph() {}			// not needed as 'points' is not a pointer
  void add_point(const point& p1,
		 bool cp_visit = true,
		 bool cp_id = false,
		 const char * new_id = "copied");
  //void add_point(const char*);
  void add_route(const char* from, const char* to, double weight=1);
  void remove_route(const char* from, const char* to); // not yet needed, so not implemented
  void visit(const char*);
  double tread(const char*,const char*);
  bool is_graph_point(const char*); 
  int size() const { return points.size(); }
  void reset();
  friend std::ostream& operator<<(std::ostream& os,const graph& in);
  //friend class graph_walker;
protected:
  point* find_point(const char*);
  void remove_point(point p1) { points.remove(p1); }
  std::list<point> points;
};

#endif //GRAPH_H_INCLUDED

// Local Variables:
// mode: c++
// End:
