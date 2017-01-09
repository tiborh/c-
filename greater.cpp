#include <iostream>
#include <ostream>

using namespace std;

struct rational {
  rational(int n = 0) : a(n),q(1) { cout << "rational, constructor 1\n"; }
  rational(int i, int j) : a(i),q(j) { cout << "rational, constructor 2\n"; }
  rational(double r) : a(r*BIG),q(BIG) { cout << "rational, constructor 3\n"; }
  operator double() {
    cout << "rational, type cast to double\n";
    return static_cast<double>(a)/q;
  }
  friend bool operator>(rational w, rational z);
  friend ostream& operator<<(ostream& os, const rational& other);
private:
  long a,q;
  enum { BIG = 100 };
};

bool operator>(rational w, rational z) { 
   return (static_cast<double>(w.a) / w.q > static_cast<double>(z.a) / z.q); 
}

ostream& operator<<(ostream& os, const rational& other) {
  os << other.a << " / " << other.q;
  return os;
}

inline int greater_than(int i, int j) {
  cout << "greater_than(int,int) has been called\n";
  return ( i > j ? i : j );
}
inline double greater_than(double x, double y) {
  cout << "greater_than(double,double) has been called\n";
  return ( x > y ? x : y );
}
inline rational greater_than(rational w, rational z) {
  cout << "greater_than(rational,rational) has been called\n";
  return ( w > z ? w : z );
}

// alternatively:
// template<class T>
// T greater_than(const T& a, const T& b) {
//   return a > b ? a : b;
// }

int main() {
  int i = 10, j = 5;
  float x = 7.0;
  double y = 14.5;
  rational w(10), z(3.5), zmax;

  // for template:
  // cout << "\ngreater_than(" << i << ", " << j << ") == " << greater_than<int>(i,j) << '\n';
  // cout << "\ngreater_than(" << x << ", " << y << ") == " << greater_than<double>(x,y) << '\n';
  // cout << "\ngreater_than(" << i << ", " << z << ") == " << greater_than<rational>(static_cast<rational>(i),z) << '\n';
  // zmax = greater_than<rational>(w,z);
  // cout << "\ngreater_than(" << w << ", " << z << ") == " << zmax << '\n';

  cout << "\ngreater_than(" << i << ", " << j << ") == " << greater_than(i,j) << '\n';
  cout << "\ngreater_than(" << x << ", " << y << ") == " << greater_than(x,y) << '\n';
  cout << "\ngreater_than(" << i << ", " << z << ") == " << greater_than(static_cast<rational>(i),z) << '\n';
  zmax = greater_than(w,z);
  cout << "\ngreater_than(" << w << ", " << z << ") == " << zmax << '\n';
  
  return 0;
}
