//Ira Pohl 
//Copyright 2016
//Supplementary example on overloading operator
#include<iostream>
#include<cstdint>

using namespace std;

typedef enum days{
  SUNDAY = 1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
    } days;

// convert to int
// ostream& operator<<(ostream& out, const days& d) {
//   out << static_cast<int>(d);
//   return out;
// }

// if not defined, integers are used
ostream& operator<<(ostream& out, const days& d) {
  switch(d) {
  case SUNDAY:
    out << "SUNDAY";
    break;
  case MONDAY:
    out << "MONDAY";
    break;
  case TUESDAY:
    out << "TUESDAY";
    break;
  case WEDNESDAY:
    out << "WEDNESDAY";
    break;
  case THURSDAY:
    out << "THURSDAY";
    break;
  case FRIDAY:
    out << "FRIDAY";
    break;
  case SATURDAY:
    out << "SATURDAY";
    break;
  default:
    out << "UNKNOWN";
  }
  return out;
}

inline days operator++(days& d){ //PREFIX OPERATOR
  d = static_cast<days>((static_cast<int>(d) + 1) % 7);
  return d;
}

days operator++(days& d, int) { //POSTFIX OPERATOR
  days temp = d;  
  d = static_cast<days>((static_cast<int>(d) + 1) % 7);  
  return temp;
}

int main()
{
  days today{days::MONDAY};
  cout << "Demonstrate enum type" << endl;
  cout << "Starting with " << today << endl;
  cout << "Pre-incremented to " << ++today << endl;
  cout << "Post-incremented so it is still " << today++ << endl;
  cout << "Post-incremented to " << today << endl;
  return 0;
}
