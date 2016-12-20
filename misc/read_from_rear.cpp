#define __cplusplus 201103L // for c++11

#include <iostream>
#include <cstring> // e.g. for strlen
#include <deque>	       // double linked list
#include <fstream> // file operations
#include <iomanip> // e.g. setw, setprecision, setfill, setbase
#include <sstream> // stringstream

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
    case 'e': fmode_int += ios::ate; break; // use it with r (if used with write, it overwrites file)
    case 'b': fmode_int += ios::binary; break; // use it with r or w
    default:
      cerr << "Unknown fileopen mode:" << fm << "Exiting...\n";
      return false;
    }

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

template<typename T>
void printq(const deque<T>& aq, const char charsep = ' ')
{
  typename deque<T>::const_iterator aqit;
  if (aq.empty())
    cout << "<empty>";
  else
    for(aqit = aq.begin(); aqit != aq.end(); ++aqit)
      cout << *aqit << ((aq.end() != aqit+1) ? charsep : '\0');
}

unsigned char* empty_q(deque<unsigned char> &dq, int nuu)
{
  unsigned char* ch_arr = new unsigned char[5]; //queue is max 4 (+ 1 for \0)
  unsigned char* ch_uni = new unsigned char[4]; //utf8 is max 4

  int i = 0;
  for (; i < nuu; ++i)
    {
      ch_uni[i] = dq.back();
      dq.pop_back();
    }

  int j = 0;
  /*
  for(; !dq.empty(); ++j)	// currently, this is not used
    {
      ch_arr[j] = dq.front();
      dq.pop_front();
    }
  */
  if (!dq.empty())
    cerr << "queue should be empty at this point.\n";

  int k = 0;
  for (; k < i; ++j,++k)
    {
      ch_arr[j] = ch_uni[k];
    }
  ch_arr[k] = '\0';

  delete [] ch_uni;

  return ch_arr;
}

string read_from_rear(const char* fn)
{
    fstream fh;

    if (!open_file(fh,fn,"re"))
    {
      cout << "Cannot open file: " << fn << '\n';
      return "";
    }

    int filepos = static_cast<int>(fh.tellg());

    if (0 == filepos)
    {
      cout << "File " << fn << " is empty.\n";
      return "";
    }

    unsigned char this_char = 0;
    deque<unsigned char> prev_chars;
    stringstream s;

    while(filepos > 0)
    {
      filepos--;
      fh.seekg(filepos);

      this_char = read_next(fh);
      if (0x0 <= this_char && this_char < 0x80) // regular ascii
	  s << this_char;
      else if (0x80 <= this_char && this_char <= 0xbf) // part of multi-byte character
	  prev_chars.push_back(this_char);
      else if (0xc0 <= this_char && this_char <= 0xdf)
	{
	  //clog << "first of two-byte\n";
	  prev_chars.push_back(this_char);
	  s << empty_q(prev_chars,2);
	  this_char = '\0';
	}
      else if (0xe0 <= this_char && this_char <= 0xef)
	{
	  //clog << "first of three-byte\n";
	  prev_chars.push_back(this_char);
	  s << empty_q(prev_chars,3);
	  this_char = '\0';
	}
      else if (0xf0 <= this_char && this_char <= 0xf7)
	{
	  //clog << "first of four-byte\n";
	  prev_chars.push_back(this_char);
	  s << empty_q(prev_chars,4);
	  this_char = '\0';
	}
      else
	{
	  cerr << "\nUnaccounted for char!\n";
	}
    }

    if (!prev_chars.empty())
      {
	cerr << "\nQueue should be empty by now.\n";
      }

    fh.close();
    s << '\n';
    if (!prev_chars.empty())
      cerr << "Some leftover in queue!\n";

    return s.str();
}

int main(int argc, char** argv)
{
  cout << read_from_rear("wandrers_nachtlied.txt");
  cout << read_from_rear("konnichiwa.txt");
  cout << read_from_rear("test_hun.txt");
  cout << read_from_rear("utf8_4byte.txt");

  return 0;
}
