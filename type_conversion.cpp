#include <iostream>

#include <iostream>
#include <ostream>
#include <cstring>
#include <cassert>

using namespace std;

const int MAXLENGTH = 12;

struct alpha {
  int i;
  char ch[MAXLENGTH+1];
  operator int();
  operator char();
};

alpha::operator int() {
  assert(strlen(ch) > 0);
  int outnum = i;
  int length_str = strlen(ch);
  for (int j = 0; j < length_str && j < MAXLENGTH; ++j) {
    outnum += static_cast<int>(ch[j]);
  }
  return outnum;
}

alpha::operator char() {
  assert(strlen(ch) > 0);
  return ch[0];
}

ostream& operator<<(ostream& os, const alpha& other) {
  os << "i == " << other.i << ", ch == \"" << other.ch << "\"";
  return os;
}


using namespace std;

int main() {
  alpha a = {1,"alpha"};
  cout << "original: '" << a << "'\n";
  cout << "cast to int: " << static_cast<int>(a) << '\n';
  cout << "cast to char: " << static_cast<char>(a) << '\n';
  return 0;
}
