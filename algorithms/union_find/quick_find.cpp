#include "quick_find.hpp"
#include <iostream>

quick_find::quick_find(unsigned int s) {
  points = new std::vector<unsigned int>(s);
  init();
}

quick_find::quick_find(const char* fn) {
  std::vector<std::vector<unsigned int>> the_data = read_file(fn);
  assert(the_data.size() > 1);
  assert(the_data.at(0).at(0) == the_data.at(0).at(1));
  points = new std::vector<unsigned int>(the_data.at(0).at(0));
  init();
  the_data.erase(the_data.begin());

  for (auto it = the_data.begin(); it != the_data.end(); ++it) {
    assert(it->size() == 2);
    std::cout << "Connecting: " << it->at(0) << " to " << it->at(1) << "\n";
    connect(it->at(0),it->at(1));
  }
}

void quick_find::init() {
  unsigned int the_size = points->size();
  for (unsigned int i = 0; i < the_size; ++i)
    points->at(i) = i;
}
  
void quick_find::connect(unsigned int a, unsigned int b) {
  if (a == b) return;		// they are the same
  if (points->at(a) == points->at(b)) return; // already connected
  assert(a < points->size() && b < points->size());
  unsigned int old_val = points->at(b);
  unsigned int new_val = points->at(a);
  for (auto it = points->begin(); it != points->end(); ++it)
    if (*it == old_val)
      *it = new_val;
}

std::ostream& operator<<(std::ostream& os, const quick_find& uf) {
  os << "{ ";
  for(auto it = uf.points->begin(); it != uf.points->end(); ++ it)
    os << *it << " ";
  os << '}';
  return os;
}
