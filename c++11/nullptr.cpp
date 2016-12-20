//#define __cplusplus 201103L // for c++11
//#define __cplusplus 199711L // for c++98 and c++03

#include <iostream>
//#include <algorithm>  // e.g. split
//#include <cassert> // assert()
//#include <climits> // e.g. INT_MAX
//#include <cmath>
//#include <cstdio>
//#include <cstdlib> // e.g. for srand(time(NULL)) and rand()
//#include <cstring> // e.g. for strlen
//#include <ctime>   // for time operation
//#include <deque>	       // double linked list
//#include <exception>
//#include <fstream> // file operations
//#include <functional> // for lambda
//#include <iomanip> // e.g. setw, setprecision, setfill, setbase
//#include <limits>  // e.g. numeric_limits<streamsize>::max()
//#include <list>
//#include <sstream> // stringstream
//#include <stack>  // for single-linked lists
//#include <string>
//#include <sys/types.h> // for stat
//#include <sys/stat.h> // for stat
//#include <typeinfo> // for typeid
//#include <unistd.h>
//#include <vector>

using namespace std;

void f(int i)
{
  cout << "f(int) was called\n";
}

void f(void *ptr)
{
  cout << "f(void *) was called\n";
}

int main(int argc, char** argv)
{
  f(0);        // calls f(int)
  f(NULL);     // calls f(int) if NULL is 0, ambiguous otherwise
  //warning: passing NULL to non-pointer argument 1 of ‘void f(int)’ [-Wconversion-null]
  f(nullptr);  // calls f(void*)

  return 0;
}
