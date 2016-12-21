#include <iostream>

using namespace std;

int main() {
  int n = 12;
  int& nn = n;

  cout << "Checking equality of n and its alias: " << (nn == n) << endl;
  nn = 2;
  cout << "n after alias has been modified: " << n << endl;
}
