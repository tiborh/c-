#include <iostream>
#include <cmath>

using namespace std;

struct point
{
    float x,y;
};

struct triangle
{
    point p[3];
};

void read_point(point &p)
{
    cout << "Reading point (x y): ";
    cin >> p.x >> p.y;
}

void read_triangle(triangle &t)
{
    cout << "Reading points of the triangle:\n";
    read_point(t.p[0]);
    read_point(t.p[1]);
    read_point(t.p[2]);
}

float area(triangle t)
{
    return 0.5*abs((t.p[1].x - t.p[0].x) * (t.p[2].y - t.p[0].y)-
                   (t.p[2].x - t.p[0].x) * (t.p[1].y - t.p[0].y));
}

void print_point(point p)
{
    cout << "Point: (" << p.x << "," << p.y << ")";
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lattice_points(point a, point b)
{
    return gcd(abs(b.x-a.x),abs(b.y-a.y));
}

int main()
{

    triangle t;
    read_triangle(t);
    cout << "Area of the triangle: " << area(t) << endl;

    cout << "gcd(20,16): " << gcd(20,16) << endl;

    cout << "lattice points of p0 to p1: " << lattice_points(t.p[0],t.p[1]) << endl;
    cout << "lattice points of p1 to p2: " << lattice_points(t.p[1],t.p[2]) << endl;
    cout << "lattice points of p2 to p0: " << lattice_points(t.p[2],t.p[0]) << endl;

    point p1,p2;
    read_point(p1);
    read_point(p2);
    cout << "lattice points of p1 to p2: " << lattice_points(p1,p2) << endl;

    return 0;
}
