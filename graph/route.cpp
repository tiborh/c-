#include "route.h"
#include "point.h"

std::ostream& operator<<(std::ostream& os,const route& in) {
  os << "\n\t\tfrom: " << in.from->get_id() << '\n';
  os << "\t\tto: " << in.to->get_id() << '\n';
  os << "\t\tweight: " << in.weight << '\n';
  os << "\t\ttrodden? " << std::boolalpha << in.trodden << '\n';
  return os;
}
