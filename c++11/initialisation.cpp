//#define __cplusplus 201103L // for c++11
//#define __cplusplus 199711L // for c++98 and c++03

#include <iostream>
//#include <algorithm>  // e.g. split
//#include <cassert> // assert()
//#include <climits> // e.g. INT_MAX
//#include <cmath>
//#include <cstdio>
//#include <cstdlib> // e.g. for srand(time(NULL)) and rand()
//#include <cstring> // e.g. for strlen
//#include <ctime>   // for time operation
//#include <deque>	       // double linked list
//#include <exception>
//#include <fstream> // file operations
//#include <functional> // for lambda
#include <initializer_list>
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

int main(int argc, char** argv)
{
  int i;
  cout << "Uninitialised: " << i << (i == 0 ? " (lucky!)" : "") << '\n';
  int j{};			// standard initialisation, "= {}" is also possible
  int *iptr{};
  int k{5};
  cout << "k: " << k << '\n';
  //int k{5.3} would result in error: no narrowing is allowed.
  char l{100}; 			// not narrowing, so allowed
  cout << "l: " << l << " (" << static_cast<int>(l) << ")\n";
  cout << "initialised int: " << j << '\n';
  cout << "initialised pointer: " << iptr << (iptr == nullptr ? " (nullptr)" : "") << '\n';
  
  auto ls = [](initializer_list<int> vals){ 
    for(int i : vals)
      cout << i << ' ';
    cout << '\n';
    cout << "Type of vals: " << typeid(vals).name() << '\n';
  };
  ls({0,1,2,3,4,5,6,7,8,9});

  return 0;
}
