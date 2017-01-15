#include <iostream>
#include <ostream>

using namespace std;

enum Colour { BLACK, WHITE, RED, GREEN, BLUE, YELLOW };

ostream& operator<<(ostream& os, Colour c) {
  switch (c) {
  case BLACK:
    os << "BLACK";
    break;
  case WHITE:
    os << "WHITE";
    break;
  case RED:
    os << "RED";
    break;
  case GREEN:
    os << "GREEN";
    break;
  case BLUE:
    os << "BLUE";
    break;
  default:
    os << "<undefined for output operator>";
  }

  return os;
}


int main() {
  Colour my_col = BLUE;
  cout << "my colour: " << my_col << '\n';
  Colour a_col = YELLOW;
  cout << "another colour: " << a_col << '\n';

  return 0;
}
