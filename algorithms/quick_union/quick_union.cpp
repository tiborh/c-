#include "quick_union.hpp"
#include <iostream>

quick_union::quick_union(unsigned int s) {
  points = new std::vector<unsigned int>(s);
  init();
}

quick_union::quick_union(const char* fn) {
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

void quick_union::init() {
  unsigned int the_size = points->size();
  for (unsigned int i = 0; i < the_size; ++i)
    points->at(i) = i;
}

std::vector<unsigned int> quick_union::get_root_and_size(unsigned int a) {
  assert(a < points->size());
  unsigned int tree_size = 1;
  unsigned int pointed = points->at(a);
  while (pointed != points->at(pointed)) {
    pointed = points->at(pointed);
    ++tree_size;
  }
  points->at(a) = pointed;
  std::vector<unsigned int> return_vals = {pointed,tree_size};
  return return_vals;
}

void quick_union::connect(unsigned int a, unsigned int b) {
  if (is_connected(a,b))
    return;

  std::vector<unsigned int> rs_a = get_root_and_size(a);
  std::vector<unsigned int> rs_b = get_root_and_size(b);

  if(rs_a.at(1) >= rs_b.at(1))
    points->at(rs_b.at(0)) = rs_a.at(0);
  else
    points->at(rs_a.at(0)) = rs_b.at(0);
}

bool quick_union::is_connected(unsigned int a, unsigned int b) {
  unsigned int graph_size = points->size();
  assert(a < graph_size && b < graph_size);
  if (a == b) return true;	// same point
  if (points->at(b) == a) return true; // b points at a
  if (points->at(a) == b) return true; // a points at b
  if (points->at(a) == points->at(b)) return true; // they point at the same

  unsigned int root_a = get_root_and_size(a)[0];
  unsigned int root_b = get_root_and_size(b)[0];

  if (root_a == root_b) return true; // they have the same root
  
  return false;
}

std::ostream& operator<<(std::ostream& os, const quick_union& uf) {
  os << "{ ";
  for(auto it = uf.points->begin(); it != uf.points->end(); ++ it)
    os << *it << " ";
  os << '}';
  return os;
}
