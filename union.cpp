#include <iostream>

using namespace std;

union int_dbl {			// overlaid values
  int i;
  double x;
} n = {0};

int main() {
  cout << "starting with 0 initialisation.\n";
  cout << "\ti: " << n.i << endl;
  cout << "\tx: " << n.x << endl;

  n.i = 3;
  cout << "i set to three\n";
  cout << "\ti: " << n.i << endl;
  cout << "\tx: " << n.x << endl;	// gibberish

  n.x = 3.3;
  cout << "x set to 3.3\n";
  cout << "\ti: " << n.i << endl;	// gibberish
  cout << "\tx: " << n.x << endl;

  
  return 0;
}
