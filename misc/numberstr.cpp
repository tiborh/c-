#include <iostream>
#include <iomanip>
#include <sstream>

// based on:
// http://codecrap.com/content/67/

using namespace std;

int multiplyBy10(int number)
{
    stringstream str;
    str << number << '0';
    str >> number;
    return number;
}

int main()
{
  for (int i = 0; i < 11; i++)
    cout << setw(3) << right << i << setw(4) << multiplyBy10(i) << endl;

  return 0;
}
