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
#include <ctime>   // for time operations
//#include <exception>
#include <fstream> // file operations
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

void openmode_int()
{
  cout << "ios::app\t" << setw(2) << right << ios::app << endl;
  cout << "ios::ate\t" << setw(2) << right << ios::ate << endl;
  cout << "ios::binary\t" << setw(2) << right << ios::binary << endl;
  cout << "ios::in \t" << setw(2) << right << ios::in << endl;
  cout << "ios::out\t" << ios::out << endl;
  cout << "ios::trunc\t" << ios::trunc << endl;
}

int main()
{
  openmode_int();
  const char* fn = "ios_openmodes.dat";
  fstream fh;
  fh.open(fn,static_cast<ios::openmode>(21));
  if (fh.is_open())
    {
      time_t now = time(NULL);
      fh << ctime(&now);
      fh.close();
    }
  else
    {
      cout << "unable to open " << fn << endl;
      return 1;
    }

  return 0;
}
