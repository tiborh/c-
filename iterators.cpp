#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> a;
  auto it = a.begin();
  //cout << *it << '\n';	 // segmentation fault is the normal behaviour
  cout << &it << '\n';
  ++it;
  cout << &it << '\n';
  ++it;
  cout << &it << '\n';

  a.push_back(3);
  it = a.begin();
  cout << *it << '\n';
  ++it;
  // zero after this
  cout << *it << '\n';
  ++it;
  cout << *it << '\n';
    
  return 0;
}
