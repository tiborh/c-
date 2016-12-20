#define __cplusplus 201103L // for c++11
//#define __cplusplus 199711L // for c++98 and c++03
//#define NDEBUG //if assert is not to be used

#include <iostream>
#include <cassert>

using namespace std;

int main()
{
  assert(1 + 1 == 3);
  cout << "EOF\n";

  return 0;
}
