#include <iostream>
#include <iomanip>

using namespace std;

const int MAXSIZE = 128;
const int PRINTWIDTH = 3;
const int BREAKNUM = 8;
const char* COLSEP = "  ";

struct pr_char {
  pr_char(int i = 0) : c(i % MAXSIZE) {}
  void print() const { cout << setw(PRINTWIDTH) << rep[c]; }
private:
  int c;
  static const char* rep[MAXSIZE];
};

const char* pr_char::rep[MAXSIZE] = {
  "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "HT",
  "LF", "VT", "FF", "CR", "SO", "SI", "DLE", "DC1", "DC2", "DC3",
  "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS",
  "RS", "US", "SPC", "!", "\"", "#", "$", "%", "&", "'",
  "(", ")", "*", "+", ",", "-", ".", "/", "0", "1",
  "2", "3", "4", "5", "6", "7", "8", "9", ":", ";",
  "<", "=", ">", "?", "@", "A", "B", "C", "D", "E",
  "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
  "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y",
  "Z", "[", "\\", "]", "^", "_", "`", "a", "b", "c",
  "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
  "n", "o", "p", "q", "r", "s", "t", "u", "v", "w",
  "x", "y", "z", "{", "|", "}", "~", "DEL" };

int main() {
  pr_char c;

  for (int i = 0; i < MAXSIZE; ++i) {
    c = i;			// or: c = static_cast<pr_char>(i);
    cout << setw(PRINTWIDTH) << i << ": ";
    c.print();
    if (i < MAXSIZE - 1)
      cout << ",";
    if ((i+1) % BREAKNUM == 0)
      cout << "\n";
    else
      cout << COLSEP;
  }
  cout << endl;
  
  return 0;
}
