#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>		// transform
#include <cctype>		// isalnum,isupper,tolower

template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
                   flip_pair<A,B>);
    return dst;
}

using namespace std;

// this reading method is more applicable for number lists.
// for string reading, see the iostudy directory
int main() {
  ifstream fn("iostudy/txt/frost_theRoadNotTaken.txt");
  istream_iterator<string> start(fn), end; // iterator init
  vector<string> data(start,end); // the lines of the file

  map<string,int> word_freq = map<string,int>();
  for(string a_str : data) {
    if (!isalnum(a_str.back()))
      a_str.pop_back();
    if (isupper(a_str.front()))
      a_str.front() = tolower(a_str.front());
    auto it = word_freq.find(a_str);
    if (it == word_freq.end())
      word_freq[a_str] = 1;
    else
      it->second++;
  }

  // for(auto it = word_freq.begin(); it != word_freq.end(); ++it)
  //   cout << it->first << ": " << it->second << '\n';

  multimap<int,string> freq_word = flip_map(word_freq);
  for(auto rit = freq_word.rbegin(); rit != freq_word.rend(); ++rit)
    cout << rit->first << ": " << rit->second << '\n';
  
  return 0;
}
