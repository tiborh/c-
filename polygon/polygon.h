#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED
#include <cassert>
#include <sstream>
#include <string>

using namespace std;

const int NCOORDS = 2;
const int MINPOINTS = 2;
const int MINLINES = 2;

class Polygon {
  int num_of_points;
  int num_of_lines;
  struct Point {
    Point(): x(0),y(0) {}
    Point(double x, double y): x(x), y(y) {}
    void set(Point p1) {
      x = p1.x;
      y = p1.y;
    }
    string print() {
      ostringstream os;
      os << "(" << x << ", " << y << ")";
      return os.str();
    }
    double x,y;
  };
  struct Line {
    Line() {}
    Line(Point a, Point b): a(a),b(b) {}
    void set(Point p1, Point p2) {
      a.set(p1);
      b.set(p2);
    }
    string print() {
      ostringstream os;
      os << "(" << a.print() << ", " << b.print() << ")";
      return os.str();
    }
    Point a,b;
  };

  Point *points;
  Line *lines;
public:
  Polygon(int, double[][NCOORDS]);
  ~Polygon() {delete[] points; delete[] lines;}
  void add_lines(int, int[][NCOORDS]);
  string get_points_str();
  string get_lines_str();
};

#endif //POLYGON_H_INCLUDED
