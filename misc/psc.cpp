#define __cplusplus 201103L // for c++11
//#define __cplusplus 199711L // for c++98 and c++03

#include <iostream>
//#include <algorithm>  // e.g. split
#include <cassert> // assert()
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
#include <map>
#include <sstream> // stringstream
//#include <stack>  // for single-linked lists
#include <string>
//#include <sys/types.h> // for stat
//#include <sys/stat.h> // for stat
#include <typeinfo> // for typeid
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

deque<string> parse_line(string a_line)
{
  stringstream iss(a_line);
  deque<string> aLine;
  while(iss)
    {
      string sub;
      getline(iss,sub,'\t');
      //if (sub != "")
	aLine.push_back(sub);
      //cout << '|' << sub;
    }
  //cout << "|\n";

  return aLine;
}

void add_line(deque<map<string,string>> &lines,deque<string> line,deque<string> head)
{
  assert(line.size() == head.size());
  map<string,string> aLine;
  deque<string>::iterator iline;
  deque<string>::iterator ihead;
  for(iline = line.begin(),ihead = head.begin();
      iline != line.end() && ihead != head.end(); 
      ++iline, ++ihead)
    aLine[*ihead] = *iline;
  lines.push_back(aLine);
}

void add_line(deque<map<string,string>> &lines,deque<string> line)
{
  add_line(lines,line,line);
}


void print_line(const deque<string> &aLine)
{
  for (string aStr : aLine)
    cout << '|' << aStr;
  cout << "|("<< aLine.size() << ")\n";
}

void print_lines(const deque<map<string,string>> &lines,deque<string> head)
{
  assert(lines.begin()->size() == head.size());

  //deque<map<string,string>>::iterator ilines; // ilines: iterates through lines
  //++ilines;
  //for(; ilines != lines.end(); ++ilines)
  //{
      //map<string,string>::iterator ialine = ilines->begin(); // ialine iterates through inside line
      //for (deque<string>::iterator ihead = head.begin();
      //   ihead != head.end() && ialine != ilines->end();
      //	   ++ihead, ++ialine)
      //	cout << *ihead << " -> ";// << (*ialine)[*ihead] << '\n';
  //}
  //  for (auto a_line : lines)
  //  for (auto an_elem : a_line)
  //    cout << an_elem << '\n';
      //cout << an_elem.first() << " -> " << an_elem.second() << '\n';
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
  deque<map<string,string>> lines = {};
  //map<string,string> aLine;
  deque<string> head;

  getline(fh,a_line);
  cout << a_line << '\n';
  head = parse_line(a_line);
  cout << "head size: " << head.size() << '\n';
  cout << head.back() << '\n';
  
  print_line(head);
  add_line(lines,head);

  deque<string> aLine;
  while(fh) {
    getline(fh,a_line);
    aLine = parse_line(a_line);
    print_line(aLine);
  }

  //print_line(aLine);
  //add_line(lines,aLine);
  //cout << "size of lines: " << lines.size() << '\n';
  //cout << "size of first line: " << lines.front().size() << '\n';
  //cout << "type of line: " << typeid(lines.front()).name() << '\n';
  //cout << "size of last line: " << lines.back().size() << '\n';
  //  print_lines(lines,head);

  fh.close();

  return 0;
}
