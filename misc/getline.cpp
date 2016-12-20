#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void echo(string inputstr)
{
  if (inputstr.length() > 0)
    cout << '|' << inputstr << '|' << endl;
}

int main()
{
  cout << "Reading until comma (Ctrl+D to finish): ";
  string inputString = "";
  string procString = "";
  stringstream iss;

  while (getline(cin,inputString,','))
    {
      iss << inputString;
      while (iss.rdbuf()->in_avail() > 0)
	{
	  iss >> procString;
	  echo(procString);
	  procString = "";
	}
      iss.clear();
    }

  return 0;
}
