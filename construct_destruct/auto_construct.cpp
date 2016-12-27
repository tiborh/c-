#include <iostream>

using namespace std;

struct alpha {
  int i;
  char ch;
};

int main() {
  alpha* a = new alpha();
  cout << "values of default constructor:"
       << " a->i == " << a->i
       << ", a->ch == '" << a->ch << "'\n";
  cout << "another way: ... = {3,'c'}:";
  alpha b = {3,'c'};
  cout << " b.i == " << b.i
       << ", b.ch == '" << b.ch << "'\n";
  b = {4,'d'};
  cout << "the above can be used as a default \"set\" too:"
       << " b.i == " << b.i
       << ", b.ch == '" << b.ch << "'\n";
  return 0;
}
