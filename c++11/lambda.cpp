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
#include <functional> // for lambda
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

function<int(int,int)> returnLambda ();

template<typename T>
void print_type(const char *label, T a)
{
  cout << "typeid of " << label << ": " << typeid(a).name() << '\n';
}

int main(int argc, char** argv)
{
  // the simplest one, prints nothing
  auto L0 = [] {
    cout << "hello lambda" << '\n';
  };
  auto L1 = [] {
    cout << "another lambda" << '\n';
  };

  // now it runs
  [] {
    cout << "hello lambda" << '\n';
  }();

  //and now this one too:
  L0();
  //what type are they?
  print_type("L0",L0);
  print_type("L1",L1);

  // one syntax:
  [] {};

  // the other syntax:
  [] () {};

  auto L2 = [] (const char* s) {
    cout << s << '\n';
  };

  L2("hello lambda");

  // return type of lambda:
  auto N0 = [] {
    return 42;
  }();

  print_type("N0",N0);

  // specifying the type:
  auto N1 = [] () -> double
    {
      return 42;
    }();				// surprisingly, this one is also needed

  print_type("N1",N1);

  int a = 1;
  int b = 3;
  // if [=] was used here to access a and b, later changes in their values would not be reflected inside L_print
  // with [&], it would not be the case; see also L0.cpp for reference
  auto L_print = [] (const char* label, int a, int b)
    {
      cout << label << ": a == " << a << "; b = " << b << '\n';
    }; 				// here, a second () is not needed

  L_print("Before lambda",a,b);

  [=] {
    //a and b are readonly, so cannot be changed
    L_print("In first lambda",a,b);
  }();

  [&] {
    a += b;
    b += a;
    L_print("In second lambda",a,b);
  }();

  L_print("After second lambda",a,b);

  ++a;

  [=,&b] {
    //a += b;readonly!
    b += a;
    L_print("In third lambda",a,b);
  }();

  L_print("After third lambda",a,b);

  [=] () mutable {
    a += b;
    b += a;
    L_print("In fourth lambda",a,b);
  }();

  L_print("After fourth lambda",a,b);

  auto lf = returnLambda();
  cout << "returnLambda(): " << lf(6,7) << '\n';
  print_type("lf",lf);

  return 0;
}

// to help with return type:
function<int(int,int)> returnLambda ()
{
  return [] (int x, int y) {
    return x*y;
  };
}
