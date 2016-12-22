#include <iostream>

using namespace std;

char c;

class X {
public:
  char c;
  class Y {
  public:
    X foo(char e) { X t; ::c = t.X::c = c = e; return t; }
  private:
    char c;
  };
};

ostream& operator<<(ostream& out, const X& x) {
  out << x.c;
  return out;
}


int main() {
  X x = X();
  x.c = 'a';
  X::Y y = X::Y();
  cout << "x.c == " << x.c << endl;
  cout << "y.foo('e') == " << y.foo('e') << endl;
  
  return 0;
}
