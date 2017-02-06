#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <ostream>

template<typename T> struct node;
template<typename T> std::ostream& operator<<(std::ostream&, const node<T>&);

template<typename T>
struct node {
  node():next_node(nullptr),empty(true) {}
  node(T in):item(in),next_node(nullptr),empty(false) {}
  node(const node& in):item(in.item),next_node(in.next_node),empty(in.empty) {}
  T item;
  node* next_node;
  bool empty;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const node<T>& nd) {
  os << &nd << ": " << (!nd.empty ? nd.item : "<null>") << " -> "
     << (nd.next_node != nullptr ? nd.next_node : 0);
  return os;
}

#endif //NODE_H_INCLUDED

// Local Variables:
// mode: c++
// End:
