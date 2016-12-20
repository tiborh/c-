#include <iostream>
#include <iomanip> // for draw_square
#include <cmath> // for draw_square
#include <cstring> // for strlen
#include <fstream> // for main
//#include <exception>
//#include <cstdlib> // for exit codes
#include <sstream>
#include <deque>
#include "file_checks.h"
#include "open_file.h"

using namespace std;

void draw_squre(int n,fstream& fh)
{
    int counter = 0;
    int rowstart = 0;
    for (int i = 0; i < n; ++i)
    {
        counter = rowstart;
        for (int j = 0; j < n; ++j)
        {
            fh << setw(static_cast<int>(log10(n)+2)) << counter;
            if (j < n/2)
                counter++;
            else if (j >= n/2)
                counter--;
        }
        fh << endl;
        if (i < n/2)
            rowstart++;
        else if (i >= n/2)
            rowstart--;
    }
}

int get_file_size(const char* fn)
{
    fstream fh;
    open_file(fh,fn,"re");
    int filesize = static_cast<int>(fh.tellg()) + 1;
    fh.close();

    return filesize;
}

//to check open/access errors
bool file_open(ofstream& fh, const char* fn)
{
    fh.open(fn);

    if (!fh.is_open())
    {
        bool file_exists = f_exists(fn);
        bool file_is_good = f_is_good(fn);
        cerr << "Unable to open file '" << fn << "'\n";
        clog << "Basic file information:\n";
        clog << "\tFile is " << (file_is_good ? "" : "not ") << "good.\n";
        if (!file_is_good)
        {
            clog << "\t\tFile " << (file_exists ? "exists" : "does not exist") << ".\n";
            if (file_exists)
            {
                clog << "\t\tFile read access is " << (f_read_access(fn) ? "" : "not ") << "good.\n";
                clog << "\t\tFile write access is " << (f_write_access(fn) ? "" : "not ") << "good.\n";
                clog << "\t\tFile execute access is " << (f_execute_access(fn) ? "" : "not ") << "good.\n";
                clog << "Further file statistics:\n";
                f_stat(fn);
            } else
            {
                cerr << "Check if you have write access to target directory.\n";
                char cCurrentPath[FILENAME_MAX];
                getcwd(cCurrentPath, sizeof(cCurrentPath));
                clog << "\tWrite access to " << cCurrentPath << " is " << (f_write_access(cCurrentPath) ? "" : "not ") << "good.\n";
            }
        } else
            cerr << "No useful data has been found about the file.\n";
        return false;
    }
    return true;
}

char* get_file_content(const char* fn)
{
    fstream fh;
    int fs = get_file_size(fn);
    if (fs > 0)
    {
        open_file(fh,fn,"r");
        if (fh.is_open())
        {
            char* filecontent = new char[fs+1];
            char read_char = 0;
            for (int i = 0; i < fs; i++)
            {
                fh.read(&read_char,sizeof(char));
                filecontent[i] = read_char;
            }
            filecontent[fs] = '\0';
            return filecontent;
            fh.close();
        } else
        {
            cout << "File is not open: " << fn << '\n';
            return NULL;
        }

    }
    return NULL;
}

void print_file_by_byte(const char* fn)
{
    fstream fh;
    int fs = get_file_size(fn);
    if (fs > 0)
    {
        open_file(fh,fn,"r");
        if (fh.is_open())
        {
            char read_char = 0;
            for (int i = 0; i < fs; i++)
            {
                fh.read(&read_char,sizeof(char));
                cout << setw(2) << setfill('0') << hex << static_cast<short>(read_char) << ' ';
            }
            cout << '\n';
            fh.close();
        } else
            cout << "File is not open: " << fn << '\n';


    } else
        cout << "File is empty.\n";
}

char* get_file_content_backwards(const char* fn)
{
    fstream fh;
    int fs = get_file_size(fn);
    if (fs > 0)
    {
        open_file(fh,fn,"r");
        if (fh.is_open())
        {
            char* filecontent = new char[fs+1];
            char read_char = 0;
            for (int i = fs; i > -1; i--) //while(fh) is also possible
            {
                fh.get(read_char);
                filecontent[i] = read_char;
            }
            filecontent[fs] = '\0';
            return filecontent;
            fh.close();
        } else
            return NULL;
    }
    return NULL;
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

string read_from_rear_simple(const char* fn)
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
    unsigned char prev_char = 0;
    stringstream s;

    while(filepos > 0)
    {
      filepos--;
      fh.seekg(filepos);
      check_flags(fh);
      prev_char = this_char;
      this_char = read_next(fh);
      if (0xc3 == this_char || 0xc5 == this_char)
	{
	  s << this_char << prev_char;
	  this_char = 0;
	}
      else
	s << prev_char;
    }

    fh.close();
    s << this_char << '\n';

    return s.str();
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
  unsigned char* ch_arr = new unsigned char[6]; //queue is max 5 (+ 1 for \0)
  unsigned char* ch_uni = new unsigned char[5]; //utf8 is max 4 (+ 1 for \0)

  //cout << "queue received: ";
  //printq(dq);
  //cout << '\n';

  int i = 0;
  for (; i < nuu; ++i)
    {
      ch_uni[i] = dq.back();
      dq.pop_back();
    }
  //ch_uni[i] = '\0';
  int j = 0;
  for(; !dq.empty(); ++j)
    {
      ch_arr[j] = dq.front();
      dq.pop_front();
    }
  //ch_arr[j] = '\0';
  int k = 0;
  for (; k < i; ++k,++j)
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
      //check_flags(fh);
      //prev_chars.push_back(this_char);

      //cout << "this_char: " << this_char << " stream: " << s.str() << '\n';
      //cout << "this_char: " << hex << static_cast<int>(this_char) << '\n';
      //cout << "prev_chars: ";
      //printq(prev_chars);
      //cout << '\n';

      this_char = read_next(fh);
      if (0x0 <= this_char && this_char < 0x80)
	  s << this_char;
      else if (0x80 <= this_char && this_char <= 0xbf)
        {
            //clog << "part of multi byte\n";
            prev_chars.push_back(this_char);
        }
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
    while(!prev_chars.empty())
      {
        s << prev_chars.front();
        prev_chars.pop_front();
      }

    fh.close();
    s << this_char << '\n';
    if (!prev_chars.empty())
      cerr << "Some leftover in queue!\n";

    return s.str();
}

int append_to_file(const char* fn, const char* str_to_add)
{
    fstream fh;
    int returned_val = 0;

    if (!open_file(fh,fn,"wa"))
    {
      cout << "Cannot open file: " << fn << '\n';
      return 1;
    }

    fh.write(str_to_add,strlen(str_to_add)*sizeof(char));
    returned_val = check_flags(fh);
    if (16 != returned_val)
        cout << "Problem with appending to " << fn << '\n';

    fh.close();

    return returned_val;
}

int main()
{
    const char* fn = "sample.txt";
    fstream fh;
    if (open_file(fh,fn,"w"))
    {
        draw_squre(51,fh);
        fh.close();
    }

    fn = "wandrers_nachtlied.txt";
    if (open_file(fh,fn,"r"))
    {
        char *fc = get_file_content(fn);
        cout << "The file content:\n";
        cout << fc << endl;
        fh.close();
    }

    if (open_file(fh,fn,"r"))
    {
        char *fc = get_file_content_backwards(fn);
        cout << "The file content backwards:\n";
        cout << fc << endl;
        fh.close();
    }

    string fc = read_from_rear(fn);
    cout << "\nThe file content backwards (improved):\n";
    if (!fc.empty())
        cout << fc << endl;
    else
        cout << "Nothing was returned.\n";

    fn = "sample.txt";
    cout << "\nAppend test:\n";
    int append_check = append_to_file(fn,"Árvíztűrő tükörfúrógép.\n");
    if (16 != append_check)
    {
        cout << "Unsuccessful append: " << append_check << '\n';
        return 1;
    }
    cout << get_file_content(fn) << '\n';
    cout << read_from_rear(fn);

    fn = "konnichiwa.txt"; //problem text: 1. three bytes long, 2. fist byte is not Cx but Ex
    cout << "\nTest Japanese text:\n";
    cout << get_file_content(fn) << '\n';
    cout << read_from_rear(fn);

    print_file_by_byte(fn);
    return 0;
}
