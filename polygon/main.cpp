#include <iostream>
#include "polygon.h"

int main() {
  int npoints = 3;
  double points[npoints][NCOORDS] = {{1,2},{3,4},{6,7}};
  int nlines = 3;
  int lines[nlines][NCOORDS] = {{0,1},{1,2},{2,0}};
  Polygon poly1 = Polygon(npoints,points);
  cout << "Points of poly1: " << poly1.get_points_str();
  poly1.add_lines(nlines,lines);
  cout << "Lines of poly1:\n" << poly1.get_lines_str();
  return 0;
}
