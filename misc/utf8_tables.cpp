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
#include <iomanip> // e.g. setw, setprecision, setfill, setbase
//#include <limits>  // e.g. numeric_limits<streamsize>::max()
//#include <list>
//#include <sstream> // stringstream
//#include <string>
//#include <typeinfo> // for typeid
//#include <unistd.h>
//#include <vector>

using namespace std;

void heading()
{
  for (int i = 0; i < 0x10; ++i)
    cout << setfill('_') << setw(2) << hex << i << ' ';
  cout << '\n';

}

inline void first_col(int i)
{
  if (0 == i % 0x10)
    {
      if (i != 0) cout << '\n';
      cout << hex << i/0xf << "_ ";
    }
}

inline void first_colb(int i)
{
  if (0 == i % 0x10)
    cout << hex << i/0xf << "_ ";
}

void one_byte()
{
  cout << "   ";
  heading();

  for(int i = 0; i < 0x80; ++i)
    {
      first_col(i);

      if (i < 0x21 || i > 0x7e)
	cout << setfill('0') << setw(2) << hex << i << ' ';
      else
	cout << setfill(' ') << setw(2) << static_cast<unsigned char>(i) << ' ';

    }
  cout << '\n';
}

void two_bytes()
{
  cout << "   ";
  cout << "   ";
  heading();
  for (int i = 0xc0; i <= 0xdf; ++i)
    {
      for (int j = 0x80; j <= 0xbf; ++j)
	{
	  if (j % 0x10 == 0)
	    {
	      if (!(j == 0x80 && i == 0xc0))
		cout << '\n';
	      cout << hex << i << ' ';
	    }
	  first_colb(j);
	  if (i < 0xc2 || (i < 0xc3 && j < 0xa1))
	    cout << setfill(' ') << setw(2) << j << ' ';	    
	  else
	    cout << setfill(' ') << setw(2) 
		 << static_cast<unsigned char>(i) 
		 << static_cast<unsigned char>(j) << ' ';
	}
    }
  cout << '\n';
}

void three_bytes()
{
  cout << "   ";
  cout << "   ";
  cout << "   ";
  heading();
  for (int i = 0xe0; i <= 0xef; ++i)
      for (int j = 0x80; j <= 0xbf; ++j)
	for (int k = 0x80; k <= 0xbf; ++k)
	{
	  if (k % 0x10 == 0)
	    {
	      if (!(j == 0x80 && k == 0x80 && i == 0xc0))
		cout << '\n';
	      cout << hex << i << ' ' << j << ' ';
	    }
	  first_colb(k);
	  cout << setfill(' ') 
	       << setw(2) 
	       << static_cast<unsigned char>(i) 
	       << static_cast<unsigned char>(j) 
	       << static_cast<unsigned char>(k) << ' ';
	}
  cout << '\n';
}

void four_bytes()
{
  cout << "   ";
  cout << "   ";
  cout << "   ";
  cout << "   ";
  heading();
  for (int i = 0xf0; i <= 0xf7; ++i)
      for (int j = 0x80; j <= 0xbf; ++j)
	for (int k = 0x80; k <= 0xbf; ++k)
	  for (int m = 0x80; m <= 0xbf; ++m)
	    {
	      if (m % 0x10 == 0)
		{
		  if (!(j == 0x80 && k == 0x80 && m == 0x80 && i == 0xf0))
		    cout << '\n';
		  cout << hex << i << ' ' << j << ' ' << k << ' ';
		}
	      first_colb(m);
	      cout << setfill(' ') 
		   << setw(2) 
		   << static_cast<unsigned char>(i) 
		   << static_cast<unsigned char>(j) 
		   << static_cast<unsigned char>(k) 
		   << static_cast<unsigned char>(m) 
		   << ' ';
	    }
  cout << '\n';
}


int main(int argc, char** argv)
{
  one_byte();
  two_bytes();
  three_bytes();
  four_bytes();
  
  return 0;
}
