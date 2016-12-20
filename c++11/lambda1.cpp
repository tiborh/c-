#define __cplusplus 201103L // for c++11
//#define __cplusplus 199711L // for c++98 and c++03

#include <iostream>
#include <algorithm>  // e.g. split
//#include <cassert> // assert()
//#include <climits> // e.g. INT_MAX
//#include <cmath>
//#include <cstdio>
#include <cstdlib> // e.g. for srand(time(NULL)) and rand()
//#include <cstring> // e.g. for strlen
#include <ctime>   // for time operation
#include <deque>	       // double linked list
//#include <exception>
//#include <fstream> // file operations
#include <functional> // for lambda or bind
//#include <iomanip> // e.g. setw, setprecision, setfill, setbase
//#include <limits>  // e.g. numeric_limits<streamsize>::max()
//#include <list>
//#include <sstream> // stringstream
//#include <stack>  // for single-linked lists
//#include <string>
//#include <sys/types.h> // for stat
//#include <sys/stat.h> // for stat
#include <typeinfo> // for typeid
//#include <unistd.h>
//#include <vector>

using namespace std;

const int NUofELEMs = 10;
const int MAXELEM = 20;

template<typename T = int>
void print_list(deque<T> coll)
{
  for_each (coll.begin(), coll.end(), [](T elem){ cout << elem << ' '; });
  cout << '\n';
}

template<typename T>
void print_type(const char *label, T a)
{
  cout << "typeid of " << label << ": " << typeid(a).name() << '\n';
}

// alternative to lambda
class Pred
{
private:
  int x;
  int y;
public:
  Pred (int xx, int yy) : x(xx), y(yy) {
  }
  bool operator() (int i) const {
    return i > x && i < y;
  }
};

int main(int argc, char** argv)
{
  srand(time(NULL));
  deque<int> coll;
  for (int i = 0; i < NUofELEMs; ++i)
    coll.push_back(rand()%MAXELEM+1);
  print_list<>(coll);
 
  int x = 5;
  int y = 12;
  // in the original, pos was of type 'auto', rightfully so
  _Deque_iterator<int, const int&, const int*> pos = find_if (coll.cbegin(), coll.cend(), // range
		      [=](int i) { // search criterion
			return i > x && i < y;
		      });
  cout << "first elem >5 and <12: " << *pos << '\n';
  print_type("type of pos: ",pos);

  // you can use function object Pred
  pos = find_if (coll.begin(), coll.end(), // range
		 Pred(x,y)); // search criterion
  cout << "first elem >5 and <12: " << *pos << '\n';

  //or binders:
  //does not work:  error: ‘_1’ was not declared in this scope
  /*
  pos = find_if (coll.begin(), coll.end(), // range
		 bind(logical_and<bool>(), // search criterion
		      bind(greater<int>(),_1,x),
		      bind(less<int>(),_1,y)));
  */

  return 0;
}
