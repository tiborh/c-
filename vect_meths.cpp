#include <iostream>
#include <vector>		// for most common array substitute
#include <string>		// for c++ string
#include <fstream>		// for file operations

using namespace std;

vector<int> fill_arr(int n, int maxnum=100) {
  int ra[n] = {0};
  srand(clock());
  for(int i = 0; i < n; ++i)
    ra[i] = rand() % maxnum + 1;
  vector<int> va;
  va.insert(va.begin(),ra,ra+n);
  return va;
}

vector<int> fill_vect(int n, int maxnum=100) {
  vector<int> a(0);
  srand(clock());
  for(int i = 0; i < n; ++i)
    a.push_back(rand() % maxnum + 1);
  return a;
}

string vect_str(vector<int> in) {
  string out = "";
  for(vector<int>::iterator it = in.begin(); it != in.end(); ++it)
    out.append(to_string(*it).append(" "));

  return out;
}

int main(int argc, char** argv) {
  const int SIZE = 10;
  
  vector<int> va(0);		// start with zero length
  cout << "empty:\n\t" << va.empty() << endl;

  cout << "fill up:\n";
  va = fill_arr(SIZE);
  cout << "\t" << vect_str(va) << endl;
  cout << "empty:\n\t" << va.empty() << endl;

  cout << "fill up:\n";
  va = fill_vect(SIZE);
  cout << "\t" << vect_str(va) << endl;

  cout << "back:\n";
  cout << "\t" << va.back() << endl;

  va.pop_back();
  cout << "after pop_back:\n\t" << vect_str(va) << endl;

  cout << "front:\n";
  cout << "\t" << va.front() << endl;

  va.erase(va.begin());
  cout << "after front erase:\n\t" << vect_str(va) << endl;

  
  
  return 0;
}
