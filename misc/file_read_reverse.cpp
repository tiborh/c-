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
#include <iomanip> // e.g. setw, setprecision, setfill, setbase
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
      return false;
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

int check_flags(const fstream& fh)
{
  int status = 0;
  //cout << "file is:\n";
  if (fh.good())
      status+=16;
  if (fh.bad())
      status+=2;
  if (fh.fail())
      status+=4;
  if (fh.eof())
      status+=8;
  if (0 == status)
      status = -1;

  return status;
}

unsigned char read_next(fstream& fh)
{
  char read_char = 0;
  fh.read(&read_char,sizeof(char));

  if (check_flags(fh) != 16)
    {
      fh.clear();
      check_flags(fh);
    }
  return static_cast<unsigned char>(read_char);
}

void read_from_rear(fstream& fh, int filepos)
{
  unsigned char this_char = 0;
  unsigned char prev_char = 0;

  while(filepos > 0)
    {
      filepos--;
      fh.seekg(filepos);
      check_flags(fh);
      prev_char = this_char;
      this_char = read_next(fh);
      if (0xc3 == this_char)
	{
	  cout << this_char << prev_char;
	  this_char = 0;
	}
      else
	cout << prev_char;
    }
  cout << this_char << '\n';
}

int main(int argc, char** argv)
{
  const char* fn = "file_read.txt";
  fstream fh;

  if (!open_file(fh,fn,"re"))
    {
      cout << "Cannot open file: " << fn << '\n';
      return 1;
    }

  int filepos = static_cast<int>(fh.tellg());

  if (0 == filepos)
    {
      cout << "File " << fn << " is empty.\n";
      return 1;
    }
  else
    {
      read_from_rear(fh,filepos);
    }

  fh.close();

  return 0;
}
