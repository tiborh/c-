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
//#include <iomanip> // e.g. setw, setprecision, setfill, setbase
//#include <limits>  // e.g. numeric_limits<streamsize>::max()
//#include <list>
//#include <sstream> // stringstream
//#include <string>
//#include <typeinfo> // for typeid
#include <unistd.h> // for getcwd
//#include <vector>


using namespace std;

int main()
{
  char cCurrentPath[FILENAME_MAX];
  cout << getcwd(cCurrentPath, sizeof(cCurrentPath)) << endl;

  return 0;
}
