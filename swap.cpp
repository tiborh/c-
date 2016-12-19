#include <iostream>

using namespace std;

int main(void) {
  int i,j;
  cout << "Give me two integers: ";
  cin >> i >> j;
  cout << "i: " << i << ", j: " << j << endl;
  swap(i,j);
  cout << "i: " << i << ", j: " << j << endl;
  
  double k,l;
  cout << "\nGive me two doubles: ";
  cin >> k >> l;
  cout << "k: " << k << ", l: " << l << endl;
  swap(k,l);
  cout << "k: " << k << ", l: " << l << endl;

  return(0);
}

inline void swap(int& i, int& j) {
  int temp = i;
  i = j;
  j = temp;
}

inline void swap(double& i, double& j) {
  double temp = i;
  i = j;
  j = temp;
}
