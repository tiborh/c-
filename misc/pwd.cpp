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
//#include <typeinfo> // for typeid
#include <unistd.h>
//#include <vector>

using namespace std;

char* pwd(char* thepwd,int pwdlen)
{
  return getcwd(thepwd,pwdlen);
}

char* pwd()
{
  return get_current_dir_name();
}

int main(int argc, char** argv)
{
  cout << pwd() << '\n';
  const int maxlen = 1024;
  char* thepwd = new char[maxlen+1];
  pwd(thepwd,maxlen);
  cout << thepwd << '\n';

  return 0;
}
