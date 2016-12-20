#include <iostream>
#include <cmath>
using namespace std;

int f2c(int f)
{
  return int(ceil(((double(f) - 32.0) * 5 / 9) - 0.5));
}

int c2f(int c)
{
  return int(ceil((double(c) * 9 / 5 + 32.0) - 0.5));
}

int main()
{
  int temp = 0;
  char type = 0;

  cout << "Fahrenheit/Celsius converter.\n";
  cout << "Enter number followed by F or C\n";

  while (cin >> temp >> type)
    if ('f' == type || 'F' == type)
      cout << f2c(temp) << endl;
    else if ('c' == type || 'C' == type)
      cout << c2f(temp) << endl;
    else
      cout << "Examples: 21C, 100F, 0 c\n";

  return 0;
}
