#include "quick_union_compress.hpp"
#include <iostream>

quick_union_compress::quick_union_compress(const char* fn) {
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

std::vector<unsigned int> quick_union_compress::get_root_and_size(unsigned int a) {
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


// void quick_union_compress::connect(unsigned int a, unsigned int b) {
//   /* compiler cannot find the following: */
//   quick_union_shorter::commect(a,b);
// }
void quick_union_compress::connect(unsigned int a, unsigned int b) {
  if (is_connected(a,b))
    return;

  std::vector<unsigned int> rs_a = get_root_and_size(a);
  std::vector<unsigned int> rs_b = get_root_and_size(b);

  if(rs_a.at(1) >= rs_b.at(1))
    points->at(rs_b.at(0)) = rs_a.at(0);
  else
    points->at(rs_a.at(0)) = rs_b.at(0);
}
