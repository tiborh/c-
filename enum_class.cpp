#include <iostream>
#include <ostream>

using namespace std;

enum class Colour { BLACK, WHITE, RED, GREEN, BLUE, YELLOW };
enum class Traffic { RED, AMBER, GREEN };

ostream& operator<<(ostream& os, Colour c) {
  switch (c) {
  case Colour::BLACK:
    os << "BLACK";
    break;
  case Colour::WHITE:
    os << "WHITE";
    break;
  case Colour::RED:
    os << "RED";
    break;
  case Colour::GREEN:
    os << "GREEN";
    break;
  case Colour::BLUE:
    os << "BLUE";
    break;
  case Colour::YELLOW:
    os << "YELLOW";
    break;
  default:
    os << "<undefined for output operator>";
  }

  return os;
}

ostream& operator<<(ostream& os, Traffic c) {
  switch (c) {
  case Traffic::AMBER:
    os << "AMBER";
    break;
  case Traffic::RED:
    os << "RED";
    break;
  case Traffic::GREEN:
    os << "GREEN";
    break;
  default:
    os << "<undefined for output operator>";
  }

  return os;
}

int main() {
  Colour my_col = Colour::GREEN;
  cout << "my colour: " << my_col << '\n';
  
  Traffic traf_col = Traffic::GREEN;
  cout << "a traffic colour: " << traf_col << '\n';

  return 0;
}
