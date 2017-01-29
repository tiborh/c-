#include "quick_union_lazy.hpp"
#include <iostream>

quick_union_lazy::quick_union_lazy(const char* fn) {
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
    std::cout << '\t' << *this << '\n';
  }
}

unsigned int quick_union_lazy::get_root(unsigned int a) {
  assert(a < points->size());
  unsigned int pointed = points->at(a);
  while (pointed != points->at(pointed))
    pointed = points->at(pointed);
  return pointed;
}

void quick_union_lazy::connect(unsigned int a, unsigned int b) {
  if (is_connected(a,b))
    return;

  unsigned int root_a = get_root(a);
  unsigned int root_b = get_root(b);

  points->at(root_b) = root_a;
}

bool quick_union_lazy::is_connected(unsigned int a, unsigned int b) {
  unsigned int graph_size = points->size();
  assert(a < graph_size && b < graph_size);
  if (a == b) return true;	// same point
  if (points->at(b) == a) return true; // b points at a
  if (points->at(a) == b) return true; // a points at b
  if (points->at(a) == points->at(b)) return true; // they point at the same

  unsigned int root_a = get_root(a);
  unsigned int root_b = get_root(b);

  if (root_a == root_b) return true; // they have the same root
  
  return false;
}
