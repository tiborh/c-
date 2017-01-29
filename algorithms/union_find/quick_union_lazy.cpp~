#include "quick_union.hpp"
#include <iostream>

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

void quick_union::connect(unsigned int a, unsigned int b) {
  if (is_connected(a,b))
    return;

  unsigned int temp_a = points->at(a);
  unsigned int temp_b = points->at(b);

  while(temp_b != points->at(temp_b)) {
    temp_b = points->at(temp_b);
    temp_a = points->at(temp_a);
  }
  
  points->at(temp_b) = temp_a;
}

// print connection values:
void pcv(unsigned int ca, unsigned int na, unsigned int cb, unsigned int nb) {
  std::cout << "\tcurrent a: " << ca << ", next a: " << na << "; current b: " << cb << ", next b: " << nb << '\n';
}

bool quick_union::is_connected(unsigned int a, unsigned int b) {
  unsigned int graph_size = points->size();
  assert(a < graph_size && b < graph_size);
  if (a == b) return true;	// 
  if (points->at(b) == a) return true; // b points at a
  if (points->at(a) == b) return true; // a points at b
  if (points->at(a) == points->at(b)) return true; // they point at the same
  unsigned int curr_point_a = a;
  unsigned int next_point_a = points->at(a);
  unsigned int curr_point_b = b;
  unsigned int next_point_b = points->at(b);
  unsigned int safety_catch = graph_size;
  pcv(curr_point_a,next_point_a,curr_point_b,next_point_b);
  while(curr_point_a != next_point_a || curr_point_b != next_point_b) { // repeat until both points at itself
    if (safety_catch == 0) {
      std::cerr << "Danger of an infinite loop. (Safety catch is at zero.)\n";
      std::cerr << "current point a: " << curr_point_a << "; next_point a: " << next_point_a << '\n';
      std::cerr << "current point b: " << curr_point_b << "; next_point b: " << next_point_b << '\n';
      break;
    }
    if (next_point_a == next_point_b) return true; // they point at the same
    if (next_point_a == curr_point_b) return true; // 'a' points at 'b'
    if (next_point_b == curr_point_a) return true; // 'b' points at 'a'
    curr_point_a = next_point_a;
    next_point_a = points->at(curr_point_a);
    curr_point_b = next_point_b;
    next_point_b = points->at(curr_point_b);
    pcv(curr_point_a,next_point_a,curr_point_b,next_point_b);
    --safety_catch;
  }
  return false;
}
