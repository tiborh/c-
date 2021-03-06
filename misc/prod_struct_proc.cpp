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
#include <deque>	       // double linked list
//#include <exception>
#include <fstream> // file operations
//#include <functional> // for lambda
//#include <initializer_list> // for initializer_list<T>
//#include <iomanip> // e.g. setw, setprecision, setfill, setbase
//#include <limits>  // e.g. numeric_limits<streamsize>::max()
//#include <list>
#include <sstream> // stringstream
//#include <stack>  // for single-linked lists
#include <string>
//#include <sys/types.h> // for stat
//#include <sys/stat.h> // for stat
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

void print_line(vector<string> *aLine)
{
  while (!aLine->empty())
    {
      cout << "\t|" << aLine->back() << "|\n";
      aLine->pop_back();
    }
}

void print_lines(vector<vector<string>> lines)
{
  for (vector<string> aLine : lines)
    {
      for (string aCell : aLine)
	cout << aCell << " -> ";
      cout << '\n';
    }
}

map<string,string> get_head(string hline)
{
  map<string,string> headrow;
  deque<string> headq = parse_line(hline);
  while(!headq.empty())
    {
      headrow[headq->front()] = headq->front();
      headq->front_pop();
    }

  return headrow;
}

deque<string> parse_line(string a_line)
{
  stringstream iss(a_line);
  deque<string> aLine;
  do
    {
      string sub;
      getline(iss,sub,'\t');
      aLine->push_back(sub);
      //cout << '\t' << sub << '\n';
    } while(iss);
}

int main(int argc, char** argv)
{
  if (argc < 2)
    {
      cout << "Give filename to process.\n";
      return 1;
    }

  fstream fh;
  const char* fn = argv[1];
  const char* fm = "r";
  if (!open_file(fh,fn,fm))
    {
      cout << "File cannot be opened: " << argv[1] << '\n';
      return 2;
    }

  string a_line = {};
  dequer<map<string,string>> lines = {};
  map<string,string> aLine;
  deque<string> head;
  getline(fh,a_line);
  while(getline(fh,a_line))
    {
      //cout << a_line << '\n';
      aLine = parse_line(a_line);

      print_line(aLine);
      lines.push_back(*aLine);
    }
  fh.close();
  //print_lines(lines);

  return 0;
}
