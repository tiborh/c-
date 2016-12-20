#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<string> tv;
  tv.push_back("春");
  tv.push_back("夏");
  tv.push_back("秋");
  tv.push_back("冬");

  //vector<string>::iterator tvi = tv.end();
  cout << *tv.begin() << endl;
  cout << *(tv.end()-1) << endl;
  return 0;
}
