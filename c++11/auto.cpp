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
#include <vector>


using namespace std;

int main(int argc, char** argv)
{
  //auto i; would be invalid, no way to deduce the type

  srand(time(NULL));
  vector<int> vints;
  for (int i = 0; i < 10; ++i)
    vints.push_back(rand()%20);
  //vector<int>::interator would be otherwise
  for (auto vintsi = vints.begin(); vintsi != vints.end(); ++vintsi)
    cout << *vintsi << ' ';
  cout << '\n';

  auto isEven = [] (int x) -> bool {
    clog << "(" << x << ") ";
    return(x % 2 == 0);
  };
  cout << "Even-ness of a random number: ";
  cout.flush();
  cout << boolalpha << isEven(rand()) << '\n';
  cout << "type of isEven: " << typeid(isEven).name() << '\n';

  return 0;
}
