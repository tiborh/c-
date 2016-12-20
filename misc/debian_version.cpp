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
#include <fstream> // file operations
//#include <functional> // for lambda
//#include <iomanip> // e.g. setw, setprecision, setfill, setbase
//#include <limits>  // e.g. numeric_limits<streamsize>::max()
//#include <list>
//#include <sstream> // stringstream
#include <string>
//#include <typeinfo> // for typeid
//#include <unistd.h>
//#include <vector>


using namespace std;

int main()
{
  ifstream fh;
  const char *fn = "/etc/debian_version";
  fh.open(fn);
  if (fh.is_open())
    {
      string version;
      getline(fh,version);
      cout << "Debian version: " << version << '\n';
      fh.close();
    }
  else
    {
      cout << "Not found: " << fn << '\n';
      return 1;
    }

  return 0;
}
