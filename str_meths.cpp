#include <iostream>
#include <vector>		// for most common array substitute
#include <string>		// for c++ string
#include <fstream>		// for file operations

using namespace std;

int main(int argc, char** argv) {
  string a = "old val";
  string b = "the new val";

  cout << "assign:\n";
  cout << "\told value:\n\t\t" << a << endl;
  cout << "\tsource to new val:\n\t\t" << b << endl;
  a.assign(b,4,7);
  cout << "\tnew value:\n\t\t" << a << endl;

  cout << "compare:\n";
  cout << "\ta to b:\n\t\t" << a.compare(b) << endl;
  cout << "\ta to a:\n\t\t" << a.compare(a) << endl;
  cout << "\tb to a:\n\t\t" << b.compare(a) << endl;

  cout << "find:\n";
  cout << "\t'val' in a or b:\n\t\t" << a.find("val") << endl;

  cout << "append:\n";
  a.append(b);
  cout << "\tb to a:\n\t\t" << a << endl;
  
  cout << "insert:\n";
  cout << "\t" << a.insert(a.find("the")," & ") << endl;

  cout << "erase (and then insert):\n";
  a.erase(0,4);
  cout << "\t" << a.insert(0,"the old ") << endl;

  cout << "replace:\n";
  cout << "\t" << a.replace(a.find("&"),1,"and") << endl;
  
  return 0;
}
