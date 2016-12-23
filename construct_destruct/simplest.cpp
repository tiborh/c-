#include <iostream>

using namespace std;

struct simplest {
  int i;
  double d;
};

int main() {
  cout << "Simplest construction is with braces.\n";
  simplest a = {3, 3.33};
  cout << "a.i: " << a.i << ", a.d: " << a.d << endl;

  cout << "same can be done with anonymous structures too.\n";
  struct { char c; char ca[7]; } c = {'a',"alphas"};
  cout << "c.c: " << c.c << ", c.ca: " << c.ca << endl;
  
  return 0;
}
