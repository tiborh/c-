#include <iostream>
using namespace std;

inline void swap(int& a, int& b) // call by reference
{
  int temp = a;
  a = b;
  b = temp;
}

inline void swap(double& a, double& b) // no need for different name (overloading)
{
  double temp = a;
  a = b;
  b = temp;
}

inline void print_numbers(int a, int b, string msg)
{
  cout << msg << ": " << a << " " << b << endl;
} 

inline void print_numbers(double a, double b, string msg)
{
  cout << msg << ": " << a << " " << b << endl;
} 


int main() {

  int a,b;
  a = b = 0;
  cout << "Give me two numbers: ";
  cin >> a;
  cin >> b;
  print_numbers(a,b,"numbers read in");
  swap(a,b);
  print_numbers(a,b,"numbers after swap");

  double c,d;
  c = d = 0.0;
  cout << "Give me two floats: ";
  cin >> c;
  cin >> d;
  print_numbers(c,d,"numbers read in");
  swap(c,d);
  print_numbers(c,d,"numbers after swap");

  return 0;
}
