#include "slist_elem.h"

std::ostream& operator<<(std::ostream& os, const slist_elem& se) {
  os << "'" << se.get_c() << "', with next elem at: " << se.get_na() << " (" << &se << ")";
  return os;
}
