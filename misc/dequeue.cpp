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
#include <deque>	       // double linked list
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

template<typename T>
void printq(const deque<T> &aq, const char charsep = ' ')
{
  typename deque<T>::const_iterator aqit;
  if (aq.empty())
    cout << "<empty>";
  else
    for(aqit = aq.begin(); aqit != aq.end(); ++aqit)
      cout << *aqit << ((aq.end() != aqit+1) ? charsep : '\0');
}

template<typename T>
void testq_p(const deque<T> &tq)
{
  cout << "testq: ";
  printq(tq,' ');
  cout << '\n';  
}

template<typename T>
void qanal(const deque<T> &tq)
{
  if (tq.empty())
    cout << "Empty queue\n";
  cout << "Size: " << tq.size() << '\n';
}

int main(int argc, char** argv)
{
  deque<int> testq;

  qanal(testq);
  testq_p(testq);
  testq.push_back(0);
  testq_p(testq);
  for (int i = 1; i < 11; ++i)
    {
      if (0 == i % 2)
	testq.push_back(i);
      else
	testq.push_front(i);
    }
  testq_p(testq);

  return 0;
}
