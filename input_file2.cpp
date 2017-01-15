#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// this reading method is more applicable for number lists.
// for string reading, see the iostudy directory
int main() {
  ifstream fn("iostudy/txt/frost_theRoadNotTaken.txt");
  istream_iterator<string> start(fn), end; // iterator init
  vector<string> data(start,end); // the lines of the file

  cout << "vector size: " << data.size() << '\n';
  cout << "start of iterator points at:\n'";
  cout << *start << "'\n";

  cout << "Now reading the whole vector (the poem loses its form):\n";
  // c++11 idiom:
  for(auto &a_str : data)	// reference declaration
    a_str = a_str + ' ';	// mutation of each element
  for(auto a_str : data)
    cout << a_str;
  cout << '\n';
  
  return 0;
}
