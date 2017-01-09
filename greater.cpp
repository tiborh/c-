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
  friend ostream& operator<<(ostream& os, const rational& other);
private:
  long a,q;
  enum { BIG = 100 };
};

ostream& operator<<(ostream& os, const rational& other) {
  os << other.a << " / " << other.q;
  return os;
}

// if used this way, calls in main are ambiguous
// inline int greater(int i, int j) {
//   cout << "greater(int,int) has been called\n";
//   return ( i > j ? i : j );
// }
// inline double greater(double x, double y) {
//   cout << "greater(double,double) has been called\n";
//   return ( x > y ? x : y );
// }
// inline rational greater(rational w, rational z) {
//   cout << "greater(rational,rational) has been called\n";
//   return ( w > z ? w : z );
// }

template<class T>
T greater(const T& a, const T& b) {
  T result = a > b ? a : b;
  return result;
}

int main() {
  int i = 10, j = 5;
  float x = 7.0;
  double y = 14.5;
  rational w(10), z(3.5), zmax;

  // won't compile: ambiguous reference
  cout << "\ngreater(" << i << ", " << j << ") == " << greater<int>(i,j) << '\n';
  cout << "\ngreater(" << x << ", " << y << ") == " << greater<double>(x,y) << '\n';
  cout << "\ngreater(" << i << ", " << z << ") == " << greater<rational>(static_cast<rational>(i),z) << '\n';
  zmax = greater<rational>(w,z);
  cout << "\ngreater(" << w << ", " << z << ") == " << zmax << '\n';
  
  return 0;
}
