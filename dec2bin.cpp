#include <iostream>
#include <stack>		// for the collection of numbers
#include <sstream>		// stringstream
#include <cassert>

using namespace std;

int main(int argc, char** argv) {
  assert(argc > 1);
  stringstream ss;
  ss << argv[1];
  int inputnum = 0;
  ss >> inputnum;
  assert(inputnum > 0);

  stack<int> intstack;

  while(inputnum > 0) {
    intstack.push(inputnum % 2);
    inputnum = inputnum / 2;
  }

  while(!intstack.empty()) {
    cout << intstack.top();
    intstack.pop();
  }

  cout << '\n';
  
  return 0;
}
