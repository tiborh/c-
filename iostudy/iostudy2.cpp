#include <iostream>
#include <iomanip>

using namespace std;

// pi to 21 places
const long double pi = 3.14159265358979323846L;
inline long double area(long double rad){
  return (pi * rad * rad);
}

int main() {
  long double r;
  cout << "\nEnter radius: ";
  cin >> r;
  cout << "\nArea is " << setw(20) << area(r);
  cout << "\nArea is " << setw(20)
       << setprecision(10) << area(r);
  cout << "\nArea is " << area(r);
  cout << "\nArea is " << setprecision(20)
       << area(r) << endl;
  cout << setfill('*');
  cout << setprecision(4) << setw(20) << r << endl;
}
