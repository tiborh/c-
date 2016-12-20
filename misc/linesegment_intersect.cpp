#include <cstdio>
#include <cassert>
#include <string>
#include <sstream>
#include <iostream>
//#include <cmath>

using namespace std;

class Point {
public:
 int x,y; 
};

class LineSeg {
public:
    Point p1,p2;
};
//----- Classes end here

//-----Add new functions here(if any)-----


//-----New functions end here-----

/* Question: You need to write the function SegIntersect which takes two line segments as input and returns true if the two line segments
             intersect each other and false if not .You may write any additional helper functions you want in the specified region only.
             Do not change the signature of the functions or classes already given.  
    LineSeg l1 : First line segment with its end-points given
    LineSeg l2 : Second line segment with its end-points given
*/

const int TS = 9;		// Test Size, number of parameters

int min(int n1, int n2)
{
	if (n1 < n2)
		return n1;
	else
		return n2;
}

int max (int n1, int n2)
{
	if (n1 > n2)
		return n1;
	else
		return n2;
}

int abs(int x)
{
    if(x<0) return -x;
    else return x;
}

double abs(double x)
{
    if(x<0) return -x;
    else return x;
}

bool SegIntersect(class LineSeg l1,class LineSeg l2) {
    // write your code below this line
  int x1 = l1.p1.x;
  int x2 = l1.p2.x;
  int x3 = l2.p1.x;
  int x4 = l2.p2.x;
  int y1 = l1.p1.y;
  int y2 = l1.p2.y;
  int y3 = l2.p1.y;
  int y4 = l2.p2.y;
  double m1,m2,b1,b2;

  // if there are any common endpoints
  if ((x1==x3 && y1==y3) || (x1==x4 && y1==y4) ||
      (x2==x3 && y2==y3) || (x2==x4 && y2==y4))
    return true;

  // vertical space between
  if ((min(y1,y2) > max(y3,y4)) || (min(y3,y4) > max(y1,y2)))
    return false;
  if ((min(y3,y4) > max(y1,y2)) || (min(y1,y2) > max(y3,y4)))
    return false;
  // horizontal space between
  if ((min(x1,x2) > max(x3,x4)) || (min(x3,x4) > max(x1,x2)))
    return false;
  if ((min(x3,x4) > max(x1,x2)) || (min(x1,x2) > max(x3,x4)))
    return false;

  // one is vertical, the other starts on same x, y overlaps
  if ((max(x1,x2) == min(x3,x4)) && (min(x1,x2) == max(x1,x2)) &&
      (max(y1,y2) >= min(y3,y4)))
    return true;
  if ((max(x3,x4) == min(x1,x2)) && (min(x3,x4) == max(x3,x4)) &&
      (max(y3,y4) >= min(y1,y2)))
    return true;
  // one endpoint on same x,but the first one is not vertical
  if ((max(x1,x2) == min(x3,x4)) && (min(x1,x2) < max(x1,x2)))
    return false;
  if ((max(x3,x4) == min(x1,x2)) && (min(x3,x4) < max(x3,x4)))
    return false;

  // same for horizontal setup
  if ((max(y1,y2) == min(y3,y4)) && (min(y1,y2) == max(y1,y2)) &&
      (max(x1,x2) >= min(x3,x4)))
    return true;
  if ((max(y3,y4) == min(y1,y2)) && (min(y3,y4) == max(y3,y4)) &&
      (max(x3,x4) >= min(x1,x2)))
    return true;
  if ((max(y1,y2) == min(y3,y4)) && (min(y1,y2) < max(y1,y2)))
    return false;
  if ((max(y3,y4) == min(y1,y2)) && (min(y3,y4) < max(y3,y4)))
    return false;
    
  if (x1 == x2) {
    return !(x3 == x4 && x1 != x3);
  } else if (x3 == x4) {
    return true;
  } else {
    // Both lines are not parallel to the y-axis
    //printf("x1: %d, y1: %d\n",x1,y1);
    //printf("x2: %d, y2: %d\n",x2,y2);
    //printf("x3: %d, y3: %d\n",x3,y3);
    //printf("x4: %d, y4: %d\n",x4,y4);
    // The slant of the line
    //m1 = (y1-y2)/(x1-x2);
    //m2 = (y3-y4)/(x3-x4);
    m1 = (y2-y1)/(x2-x1);
    m2 = (y4-y3)/(x4-x3);
    // The vertical distance from 0,0
    b1 = y1 - x1*m1;
    b2 = y3 - x3*m2;
    // overlapping segments
    if ((m1 == m2) && (abs(b1-b2) < 0.0001) &&
	( (min(x1,x2) >= min(x3,x4)) ||  (min(x3,x4) >= min(x1,x2)) )
	) return true;

    if ( ( (y1 >= m2 * x1 + b2) && (y2 <= m2 * x2 + b2) ) || ( (y1 <= m2 * x1 + b2) && (y2 >= m2 * x2 + b2) ))
      {
	double xi,yi; 		// intersection coordinates
	xi = (b2 - b1) / (m1 - m2);
	//yi = (m1 * b2 - m2 * b1) / (m1 - m2);
	yi = m1 * (b2 - b1) / (m1 - m2) + b1;
	//printf("xi: %lf, yi: %lf\n",xi,yi);
	//printf("m1: %lf, m2: %lf, b1: %lf, b2: %lf\n",m1,m2,b1,b2);
	if ( (xi >= min(x3,x4)) && (xi <= max(x3,x4)) && (yi >= min(y3,y4) && (yi <= max(y3,y4))) )
	  return true;
	else
	  return false;
      }
    else
      return false;
    //printf("m1: %lf, m2: %lf\n",m1,m2);
    return m1 != m2;
  }
}

string pointToStr(Point p1)
{
  ostringstream outstream;
  outstream << "(" << p1.x << "," << p1.y << ")";
  return outstream.str();
}

string lineSegToStr(LineSeg ls1)
{
  ostringstream outstream;
  outstream << "(" << pointToStr(ls1.p1) << "-" << pointToStr(ls1.p2) << ")";
  return outstream.str();
}

void interSectTest(int tc[9])
{
  Point a,b,c,d;
  a.x = tc[0];
  a.y = tc[1];
  b.x = tc[2];
  b.y = tc[3];
  c.x = tc[4];
  c.y = tc[5];
  d.x = tc[6];
  d.y = tc[7];
  LineSeg ab,cd;
  ab.p1 = a;
  ab.p2 = b;
  cd.p1 = c;
  cd.p2 = d;
  bool er = tc[8];
  cout << lineSegToStr(ab) << "\tintersects?\t" << lineSegToStr(cd) << "\t";
  
  if (SegIntersect(ab,cd) != er || SegIntersect(cd,ab) != er)
    {
      cout << "NOK (Should be " << er << ".)";
    }
  else
    {
      cout << "OK  (They";
      if (er == 0)
	cout << " do not";
      cout << " intersect.)";
    }
  cout << endl;

  if ((SegIntersect(ab,cd) != er) != (SegIntersect(cd,ab) != er))
    cout << "Reverse order brings different result.\n";

}

int main()
{
  const int TCS = 18;		// Number of Test Cases
  int testInput[TCS][TS] = {{1,2,3,4,3,4,5,6,1},
			    {1,2,3,4,4,5,6,7,0},
			    {2,5,3,2,1,2,3,4,1},
			    {2,5,3,2,3,4,5,6,0},
			    {2,1,4,3,1,2,3,4,0}, // 5
			    {2,1,4,3,2,5,3,2,1},
			    {2,0,0,2,0,0,0,2,1},
			    {0,0,0,2,0,3,0,5,0},
			    {-1,0,3,0,0,1,0,3,0},
			    {0,0,0,2,0,1,0,3,1}, // 10
			    {6,5,11,10,7,6,9,8,1},
			    {6,5,11,10,10,9,13,12,1},
			    {5,5,7,3,3,4,5,6,0},
			    {11,1,17,5,15,4,13,13,0},
  			    {11,1,17,5,15,3,13,13,1}, // 15
			    {11,7,15,9,13,3,17,10,0},
			    {11,1,9,7,19,14,1,5,0},
			    {19,7,15,9,17,8,14,16,0}};

  for (int i = 0; i < TCS; ++i)
    interSectTest(testInput[i]);

  /*
  
  // x1: 7, y1: 1 x2: 19, y2: 9 x3: 13, y3: 5 x4: 16, y4: 7
  */
  
  return 0;
}
