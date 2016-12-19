#include <iostream>

using namespace std;

int main(void) {
  int i,j;
  cout << "Give me two integers: ";
  cin >> i >> j;
  cout << "i: " << i << ", j: " << j << endl;
  swap<int>(i,j);
  cout << "i: " << i << ", j: " << j << endl;
  
  double k,l;
  cout << "\nGive me two doubles: ";
  cin >> k >> l;
  cout << "k: " << k << ", l: " << l << endl;
  swap<double>(k,l);
  cout << "k: " << k << ", l: " << l << endl;
  
  return(0);
}

template<class T>
inline void swap(T& i, T& j) {
  T temp = i;
  i = j;
  j = temp;
}
