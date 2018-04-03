#include <iostream>
#include <iomanip>

using namespace std;

bool formula1(bool a, bool b, bool c) {
  return((a || b) && (!a || c));
}

bool formula2a(bool a, bool b, bool c) {
  return((a | b) & (~a | c));
}

bool formula2b(bool a, bool b, bool c) {
  return((a ^ b) & (~a | c));
}

int main() {
  bool p,q,r;
  p = q = r = false;
  bool bools[2] = {false,true};

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k) {
	p = bools[i]; q = bools[j]; r = bools[k];
	cout << setw(3) << left << " p: " 
	     << boolalpha << setw(6) << p << " q: " 
	     << setw(6) << q << " r: " << setw(6) << r 
	     << "\tformula1 result: " << setw(6) << formula1(p,q,r) 
	     << "\tformula2a result: " << setw(6) << formula2a(p,q,r)
	     << "\tformula2b result: " << setw(6) << formula2b(p,q,r) << '\n';
      }

  return 0;
}
