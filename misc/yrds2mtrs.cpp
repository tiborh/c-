#include <iostream>
#include <sstream>
#include <string>
using namespace std;

inline double str2dbl(string const& s)
{
  istringstream i(s);
  double x;
  if (!(i >> x))
    throw "Cannot convert to double: \"" + s + "\"\n";
  return x;
}

int main(int argc, char** argv) {
  double yards = 0.0;
  if (argc > 1)
    try
      {
        yards = str2dbl(argv[1]);
      }
    catch (string exception)
      {
        cerr << exception;
        return 1;
      }
  else
    cin >> yards;
  const double yard2meter = 0.9144;
  double meters = yards * yard2meter;
  cout << meters << endl;

  return 0;
}
