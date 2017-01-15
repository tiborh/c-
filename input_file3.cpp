#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>		// sort
#include <cctype>		// isalnum,isupper,tolower

using namespace std;

int main() {
  ifstream fn("iostudy/txt/frost_theRoadNotTaken.txt");
  istream_iterator<string> start(fn), end; // iterator init
  vector<string> data(start,end); // the lines of the file

  for (string &a_word : data) {
    if (!isalnum(a_word.back()))
      a_word.pop_back();
    if (isupper(a_word.front()))
      a_word.front() = tolower(a_word.front());
  }
  
  sort(data.begin(),data.end()); // need be random access iterators
  for (string a_word : data)
    cout << a_word << '\n';
  
  return 0;
}
