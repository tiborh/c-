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
//#include <ctime>   // for time operations
//#include <exception>
#include <fstream> // file operations
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

bool open_file(fstream& fh, const char* fn, const char* fm)
{
  ios::openmode fmode;
  int fmode_int = 0;

  for(unsigned int i = 0; i < strlen(fm); i++)
  switch(fm[i])
    {
    case 'r': fmode_int += ios::in; break;
    case 'w': fmode_int += ios::out; break;
    case 'a': fmode_int += ios::app; break; // use it with write
    case 't': fmode_int += ios::trunc; break; // use it with write
    case 'e': fmode_int += ios::ate; break; // use it with r or w
    case 'b': fmode_int += ios::binary; break; // use it with r or w
    default:
      cerr << "Unknown fileopen mode:" << fm << "Exiting...\n";
      return false; // not necessary, warning or exception could be better
    }

  //cout << ">>>fopen mode (int): " << fmode_int << endl;
  //to do: valid fmode combinations should be checked!
  fmode = static_cast<ios::openmode>(fmode_int);
  fh.open(fn,fmode);
  if (fh.is_open())
    return true;
  else
    return false;
}

int get_file_size(const char* fn)
{
    fstream fh;
    if (!open_file(fh,fn,"re"))
      {
	cerr << "File cannot be opened:" << "\n";
	throw("Cannot be opened error has been thrown.\n");
      }
    int filesize = static_cast<int>(fh.tellg());
    fh.close();

    return filesize;
}

int main(int argc, char** argv)
{
  int file_size = {};
  if (argc > 1)
    {
      try {
	file_size = get_file_size(argv[1]);
      }
      catch (const char* msg)
	{
	  cerr << msg;
	  return 2;
	}
    }
  else
    {
      cout << "Filename needs to be provided.\n";
      return 1;
    }

  cout << "File size: " << file_size << '\n';

  return 0;
}
