#include <iostream>
#include <ostream>
#include <cstring>

using namespace std;

const int MAXLENGTH = 12;

struct alpha {
  int i;
  char ch[MAXLENGTH+1];
  void set_ch(const char*&);
};

void alpha::set_ch(const char*& in) {
  strncpy(ch,in,MAXLENGTH);
}

ostream& operator<<(ostream& os, const alpha& other) {
  os << "i == " << other.i << ", ch == \"" << other.ch << "\"";
  return os;
}

int main() {
  alpha* a = new alpha();
  cout << "values of default constructor:" << a << '\n';
  cout << "another way: ... = {3,\"alpha\"}:";
  alpha b = {3,"alpha"};
  cout << b << '\n';
  b = {4,{'b','e','t','a'}};
  cout << "for the default \"operator=\": ... = {4,{'b','e','t','a'}}: "
       << "\n\t" << b << '\n';
  alpha* c = new alpha(b);
  cout << "default copy constructor used to create 'c' from 'b'\n";
  cout << "c: " << *c << '\n';
  cout << "to check their independence, c is changed:\n";
  c->i = 5;
  const char* in_str = "gamma";
  c->set_ch(in_str);
  cout << "c: " << *c << '\n';
  cout << "b: " << b << '\n';
  return 0;
}
