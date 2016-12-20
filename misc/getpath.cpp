#define __cplusplus 201103L // for c++11
//#define __cplusplus 199711L // for c++98 and c++03

#include <iostream>
//#include <algorithm>  // e.g. split
//#include <cassert> // assert()
//#include <climits> // e.g. INT_MAX
//#include <cmath>
//#include <cstdio>
//#include <cstdlib> // e.g. for srand(time(NULL)) and rand()
#include <cstring> // e.g. for strlen
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
//#include <unistd.h>
//#include <vector>

using namespace std;

char* getpath(char* argv0)
{
  char *curr_pos,*prev_pos;
  unsigned char sc = '/';
  char* thepwd = new char[1024];
  strcpy(thepwd,argv0);

  cout << "Work in progress. Not there yet.\n";

  if (NULL != (curr_pos = static_cast<char *>(memchr(thepwd,sc,strlen(argv0)))))
    do
      {
	cout << "pos of " << sc << " in argv0: " << curr_pos << '\n';
	prev_pos = curr_pos;
	if (NULL == curr_pos)
	  cout << "No more " << sc << ".\n";
	else
	  cout << "pos of " << sc << " in argv0: " << curr_pos << '\n';
      } while (NULL != (curr_pos = static_cast<char *>(memchr(curr_pos+1,sc,strlen(curr_pos-1)))));

  *prev_pos = '\0';

  return thepwd;
}

int main(int argc, char** argv)
{
  cout << "Result of getpath(argv[0]): '" << getpath(argv[0]) << "'\n";

  return 0;
}
