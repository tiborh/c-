#define __cplusplus 201103L // for c++11
//#define __cplusplus 199711L // for c++98 and c++03

#include <iostream>
//#include <algorithm>  // e.g. split
#include <cassert> // assert()
//#include <climits> // e.g. INT_MAX
//#include <cmath>
#include <cstdio>		// for remove()
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
#include <string>
//#include <typeinfo> // for typeid
//#include <unistd.h>
#include <vector>

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
    case 'a': fmode_int += ios::app; break;
    case 't': fmode_int += ios::trunc; break; // unusable for fstream
    case 'e': fmode_int += ios::ate; break; // unusable for fstream
    case 'b': fmode_int += ios::binary; break;
    default:
      cerr << "Unknown fileopen mode:" << fm << "Exiting...\n";
      return false;
    }
  
  //cout << ">>>fopen mode (int): " << fmode_int << endl;
  //to do: valid fmode combinations must be checked later!
  fmode = static_cast<ios::openmode>(fmode_int);
  fh.open(fn,fmode);
  if (fh.is_open())
    return true;
  else
    return false;
}

//to do: make a version that returns with number of lines read (better for testing purposes
bool f_read_test(const char* fn)
{
  fstream fh;
  if (open_file(fh,fn,"r"))
    {
      cout << fn << " is open for reading.\n";
      string f_line = "";
      cout << "Content read:\n";
      while(getline(fh,f_line))
	cout << f_line << endl;
      cout << "EOF\n";
      fh.close();
      return true;
    }
  else
    {
      cout << fn << " cannot be opened for reading.\n";
      return false;
    }
}

bool f_read_test2(const char* fn)
{
  fstream fh;
  if (open_file(fh,fn,"re"))
    {
      cout << fn << " is open for reading (from back).\n";
      streampos curr_pos = fh.tellp();
      char char_read = 0;
      const int read_size = sizeof(char);
      cout << "read size: " << read_size << endl;
      //cout << "Position when opened: " << curr_pos << endl;
      cout << "Content read:\n";
      while(static_cast<streampos>(-1) < curr_pos)
	{
	  cout << "pos(" << fh.tellg() << "), ";
	  fh.get(char_read);
	  //cout << char_read;
	  curr_pos -= static_cast<streampos>(1);
	  fh.seekg(curr_pos); //does not work
	}
      cout << "BOF\n";
      fh.close();
      return true;
    }
  else
    {
      cout << fn << " cannot be opened for reading.\n";
      return false;
    }
}


bool f_write_test(const char *fn)
{
  fstream fh;
  if (open_file(fh,fn,"w"))
    {
      cout << fn << " is open for writing.\n";
      fh << fn << '\n';
      fh.close();
      return true;
    }
  else
    {
      cout << fn << " cannot be opened for writing.\n";
      return false;
    }
}

bool f_append_test(const char *fn)
{
  fstream fh;
  if (open_file(fh,fn,"wa"))
    {
      cout << fn << " is open for append.\n";
      fh << fn << '\n';
      fh.close();
      return true;
    }
  else
    {
      cout << fn << " cannot be opened for append.\n";
      return false;
    }
}

bool f_trunc_test(const char *fn)
{
  ofstream fh; // does not work with fstream. Cannot open the file.
  fh.open(fn, ios_base::trunc);
  if (fh.is_open())
  //if (open_file(fh,fn,'t'))
    {
      cout << fn << " is open for truncate.\n";
      fh << fn << '\n';
      fh.close();
      return true;
    }
  else
    {
      cout << fn << " cannot be opened for truncate.\n";
      return false;
    }
}

bool f_end_test(const char *fn)
{
  fstream fh;
  const char* teststr = "ios_base::ate test\n";
  if (open_file(fh,fn,"wae"))  // e does not really have any sense here.
    {
      cout << fn << " is open from back.\n";
      fh << teststr;
      fh.close();
      return true;
    }
  else
    {
      cout << fn << " cannot be opened from back.\n";
      return false;
    }
}

bool f_bin_test(const char *fn)
{

  fstream fh;
  if (open_file(fh,fn,"wb"))
    {
      char teststr[] = "Test for binary.123\n";
      cout << fn << " is open for binary operation.\n";
      fh.write(teststr,sizeof(teststr));
      fh.close();
      return true;
    }
  else
    {
      cout << fn << " cannot be opened for binary operation.\n";
      return false;
    }
}

bool f_delete(const char* fn)
{
  if (remove(fn) != 0)
    {
      perror("Error deleting file");
      return false;
    }
  else
    {
      puts("File successfully deleted");
      return true;
    }
}

int main()
{
  const char* fn = "test.dat";

  //read/write test
  assert(f_read_test(fn) == false);
  assert(f_write_test(fn) == true);
  assert(f_read_test(fn) == true);
  assert(f_delete(fn) == true);
  assert(f_read_test(fn) == false);
  puts("");

  //append test
  assert(f_append_test(fn) == true);
  assert(f_append_test(fn) == true);
  assert(f_read_test(fn) == true);
  assert(f_delete(fn) == true);
  assert(f_read_test(fn) == false);
  puts("");

  //truncate test
  assert(f_trunc_test(fn) == true);
  assert(f_write_test(fn) == true);
  assert(f_trunc_test(fn) == true);
  assert(f_read_test(fn) == true);
  assert(f_delete(fn) == true);
  assert(f_read_test(fn) == false);
  puts("");

  //ate/end_open test
  assert(f_write_test(fn) == true);
  assert(f_end_test(fn) == true);		// overwrites file
  assert(f_read_test(fn) == true);
  assert(f_read_test2(fn) == true); // reads nothing because end is opened
  assert(f_delete(fn) == true);
  assert(f_read_test(fn) == false);
  puts("");

  //binary test
  assert(f_bin_test(fn) == true);		// txt format is used.
  assert(f_read_test(fn) == true);
  assert(f_delete(fn) == true);
  assert(f_read_test(fn) == false);
 
  return 0;
}
