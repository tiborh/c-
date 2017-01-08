#include "route.h"
#include "point.h"

const char* route::get_from_id() const {
  std::string idstr(from->get_id());
  return idstr.c_str();
}

const char* route::get_to_id() const {
  std::string idstr(to->get_id());
  return idstr.c_str();
}

std::ostream& operator<<(std::ostream& os,const route& in) {
  os << "\n\t\tfrom: " << in.from->get_id() << '\n';
  os << "\t\tto: " << in.to->get_id() << '\n';
  os << "\t\tweight: " << in.weight << '\n';
  os << "\t\ttrodden? " << std::boolalpha << in.trodden << '\n';
  return os;
}
