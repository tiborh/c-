#define __cplusplus 201103L // for c++11
//#define __cplusplus 199711L // for c++98 and c++03

#include <iostream>
//#include <algorithm>  // e.g. split
//#include <cassert> // assert()
//#include <climits> // e.g. INT_MAX
//#include <cmath>
//#include <cstdio>
//#include <cstdlib> // e.g. for srand(time(NULL)) and rand()
//#include <cstring> // e.g. for strlen
//#include <ctime>   // for time operations
//#include <exception>
//#include <fstream> // file operations
//#include <functional> // for lambda
#include <iomanip> // e.g. setw, setprecision, setfill, setbase
//#include <limits>  // e.g. numeric_limits<streamsize>::max()
//#include <list>
//#include <sstream> // stringstream
//#include <string>
//#include <typeinfo> // for typeid
//#include <unistd.h>
//#include <vector>


using namespace std;

int main(int argc, char** argv)
{
  int ints[] = {0xf, 0x1f, 0x2f, 0x3f, 0x4f, 0x5f};
  
  for (int i = 0; i < 5; ++i)
    {
      int num = ints[i];
      num = num >> 4;
      num = num << 4;
      num = ints[i]-num;
      cout << "0x" << setfill('0') << setw(2) << hex << ints[i] << "->" << "0x" << hex << num << '\n';
    }

  return 0;
}
