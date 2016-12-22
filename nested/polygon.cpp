#include <iostream>
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
  Polygon(int npoints, double coords[][NCOORDS]) {
    assert(npoints > MINPOINTS);
    points = new Point[npoints];
    num_of_points = npoints;
    for (int i = 0; i < npoints; ++i)
      points[i].set(Point(coords[i][0],coords[i][1]));
  }
  void add_lines(int nlines, int cons[][NCOORDS]) {
    assert(nlines > MINLINES);
    lines = new Line[nlines];
    num_of_lines = nlines;
    for (int i = 0; i < nlines; ++i)
      lines[i].set(points[cons[i][0]],points[cons[i][1]]);
  }
  string getPointsStr() {
    ostringstream os;
    for (int i = 0; i < num_of_points; ++i) {
      os << i << ": " << points[i].print();
      if (i < num_of_points-1)
	os << ", ";
    }
    os << '\n';
    return os.str();
  }
  string getLinesStr() {
    ostringstream os;
    for (int i = 0; i < num_of_lines; ++i) {
      os << "\t" << i << ": " << lines[i].print();
      if (i < num_of_lines-1)
	os << ",";
      os << '\n';
    }
    return os.str();
  }
};

int main() {
  int npoints = 3;
  double points[npoints][NCOORDS] = {{1,2},{3,4},{6,7}};
  int nlines = 3;
  int lines[nlines][NCOORDS] = {{0,1},{1,2},{2,0}};
  Polygon poly1 = Polygon(npoints,points);
  cout << "Points of poly1: " << poly1.getPointsStr();
  poly1.add_lines(nlines,lines);
  cout << "Lines of poly1:\n" << poly1.getLinesStr();
  return 0;
}
