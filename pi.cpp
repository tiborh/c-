#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  cout << setprecision(16) << 4*atan(1) << endl;
  //after that precision, the value deviates
  return 0;
}
