#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

const int MAXLEN = 1024;

void resetstr(char*& instr) {
  if (instr != 0)
    delete(instr);
  instr = new char[MAXLEN + 1];
  instr[0] = 0;
}

int main() {
  cout << "Reading a single char: ";
  char ch1 = 0;
  cin.get(ch1);
  // Ignore to the end of line
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
  cout << "read in: " << ch1 << '\n';
  char* s1 = new char[MAXLEN + 1];
  resetstr(s1);
  cout << "reading in with get: ";
  cin.get(s1,MAXLEN);		// third argument is default '\n'
  cout << "read in: '" << s1 << "' (" << cin.gcount() << ")\n"; // with space and all
  resetstr(s1);
  cout << "reset str: '" << s1 << "'\n";
  cout << "better use EOF for end of input <CTRL+D>, possibly twice: ";
  cin.getline(s1,MAXLEN,EOF);
  cout << "read in: '" << s1 << "'\n";
  cin.clear();
  resetstr(s1);
  cout << "same with cin.read: ";
  cin.read(s1,10);		       // file end is accepted, but failbit is set
  if (cin.fail()) {
    cout << "premature EOF has been met\n";
    cin.clear();
  }
  cout << "read in: '" << s1 << "'\n"; // line end is not settable
  resetstr(s1);
  cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
  cout << "use two words, space separated (space at the end too):\n";
  cin.getline(s1,MAXLEN,' ');
  char* s2 = new char[MAXLEN + 1];
  cin.getline(s2,MAXLEN,' ');
  cout << "word 1: '" << s1 << "'\n";
  cout << "word 2: '" << s2 << "'\n";
  resetstr(s1);
  resetstr(s2);
  
  return 0;
}
