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
//#include <string>
//#include <typeinfo> // for typeid
//#include <unistd.h>
//#include <vector>

using namespace std;

unsigned int ustrlen(unsigned char* inchars)
{
  unsigned int length = 0;
  
  while(*(inchars+length++) != '\0');

  return length-1;
}

unsigned char* sign2unsign (char* instr)
{
  unsigned char* outstr = new unsigned char[strlen(instr)+1];

  for(unsigned int i = 0; i <= strlen(instr); ++i)
    *(outstr+i) = static_cast<unsigned int>(*(instr+i));
  
  return outstr;
}

void print_bytes(unsigned char* inchars)
{
  cout << "string: " << inchars << '\n';
  cout << "\tstrlen: " << ustrlen(inchars) << '\n';
  cout << '\t';
  for (unsigned int i = 0; i < ustrlen(inchars); ++i)
    cout << hex << static_cast<unsigned short>(inchars[i]) << ' ';
  cout << '\n';

}

int main(int argc, char** argv)
{
  
  if (argc > 1)
    for (int i = 1; i < argc; ++i)
      print_bytes(sign2unsign(argv[i]));
  else
  {
    unsigned char test_strs[9][5] = {"a", "á", "é", "ä", "Ü", "ö", "ő", "春", "へ"};
    for (int i = 0; i < 9; ++i)
      print_bytes(test_strs[i]);
    cout << "\nTip: you can test strings as command line arguments too.\n";
  }

  return 0;
}
