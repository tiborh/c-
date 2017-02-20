#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <ostream>

template<typename T> struct node;
template<typename T> std::ostream& operator<<(std::ostream&, const node<T>&);

template<typename T>
struct node {
  node():next_node(nullptr),empty(true),visited(false) {}
  node(T in):item(in),next_node(nullptr),empty(false),visited(false) {}
  node(const node& in):item(in.item),next_node(in.next_node),empty(in.empty),visited(in.visited) {}
  T item;
  node* next_node;
  bool empty,visited;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const node<T>& nd) {
  os << &nd << ": " << (!nd.empty ? nd.item : "<null>") << " -> "
     << (nd.next_node != nullptr ? nd.next_node : 0)
     << " (" << ( nd.visited ? "visited" : "unvisited" ) << ')';
  return os;
}

#endif //NODE_H_INCLUDED

// Local Variables:
// mode: c++
// End:
