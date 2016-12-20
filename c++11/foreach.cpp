//#define __cplusplus 201103L // for c++11
//#define __cplusplus 199711L // for c++98 and c++03

#include <iostream>
//#include <algorithm>  // e.g. split
//#include <cassert> // assert()
//#include <climits> // e.g. INT_MAX
//#include <cmath>
//#include <cstdio>
#include <cstdlib> // e.g. for srand(time(NULL)) and rand()
//#include <cstring> // e.g. for strlen
//#include <ctime>   // for time operation
//#include <deque>	       // double linked list
//#include <exception>
//#include <fstream> // file operations
//#include <functional> // for lambda
#include <iomanip> // e.g. setw, setprecision, setfill, setbase
//#include <limits>  // e.g. numeric_limits<streamsize>::max()
//#include <list>
//#include <sstream> // stringstream
//#include <stack>  // for single-linked lists
//#include <string>
//#include <sys/types.h> // for stat
//#include <sys/stat.h> // for stat
//#include <typeinfo> // for typeid
//#include <unistd.h>
#include <vector>

using namespace std;

template <typename T>
void print_elems (const T& coll)
{
  for (const auto& elem : coll) 
      cout << elem << ' ';
  cout << '\n';
}

int main(int argc, char** argv)
{
  cout << "On the fly array:\n";
  // this is possible in C++11:
  for ( int i : { 2, 3, 5, 7, 9, 13, 17, 19 } )
      cout << i << ' ';
  cout << '\n';

  int ints[] = { 2, 3, 5, 7, 9, 13, 17, 19 };
  cout << "\nsame with regular array:\n";
  for (int i : ints)
      cout << i << ' ';
  cout << '\n';

  srand(time(NULL));
  vector<int> vints;
  for (int i = 0; i < 10; ++i)
    vints.push_back(rand()%20);

  cout << "\nsame for vector:\n";
  for( int i : vints )
      cout << i << ' ';
  cout << '\n';

  cout << "\nto multiply each elem by 3:\n";
  for( int &elem : vints)
    elem *= 3;
  print_elems(vints);

  cout << "\nmultiplication table:\n";
  int ints2[10],counter = 0;
  for (int &i : ints2)
      i = ++counter;
  for (int &i: ints2)
    {
      for (int j: ints2)
	cout << setw(3) << i*j << ' ';
      cout << '\n';
    }

  return 0;
}
