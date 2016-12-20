#include <iostream>
#include <cmath>
using namespace std;

int f2c(int f)
{
  return int(ceil(((double(f) - 32.0) * 5 / 9) - 0.5));
}

int main()
{
  int f = 0;
  cout << "Fahrenheit to Celsius converter.\n";
  while (cin >> f)
    cout << f2c(f) << endl;

  return 0;
}
