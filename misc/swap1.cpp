#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;		// This is the price of generic: you cannot use "using namespace std"

template<class T>		// generic, using template
inline void swap(T& a, T& b)
{
  T temp = a;
  a = b;
  b = temp;
}

template<class T>
inline void print_numbers(T a, T b, string msg)
{
  cout << msg << ": " << a << " " << b << endl;
} 

int main() {

  int a,b;
  a = b = 0;
  cout << "Give me two numbers: ";
  cin >> a >> b;
  print_numbers(a,b,"numbers read in");
  swap(a,b);
  print_numbers(a,b,"numbers after swap");

  double c,d;
  c = d = 0.0;
  cout << "Give me two floats: ";
  cin >> c >> d;
  print_numbers(c,d,"numbers read in");
  swap(c,d);
  print_numbers(c,d,"numbers after swap");

  return 0;
}
