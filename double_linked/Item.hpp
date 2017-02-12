#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <ostream>
#include <cassert>

template<typename T>
struct Item {
  Item():prev_item(nullptr),
	 next_item(nullptr) {}
  Item(T in):id(in),
	     prev_item(nullptr),
	     next_item(nullptr) {}
  Item(const Item& in):id(in.id),
		       prev_item(in.prev_item),
		       next_item(in.next_item) {}
  void disconnect() {
    prev_item = nullptr;
    next_item = nullptr;
  }
  bool is_disconnected() const {
    return (prev_item == nullptr && next_item == nullptr);
  }
  bool is_first() const {
    return(prev_item == nullptr && next_item != nullptr);
  }
  bool is_mid() const {
    return(prev_item != nullptr && next_item != nullptr);
  }
  bool is_last() const {
    return(prev_item != nullptr && next_item == nullptr);
  }
  template<typename T1> friend std::ostream& operator<<(std::ostream&, const Item<T1>&);
  T id;
  Item<T> *prev_item,*next_item;
};

template<typename T1>
std::ostream& operator<<(std::ostream& os, const Item<T1>& nd) {
  os << &nd << ": "
     << "\t(id) \"" << nd.id << "\""
     << "\t(prev) " << (nd.prev_item != nullptr ? nd.prev_item : 0)
     << "\t(next) " << (nd.next_item != nullptr ? nd.next_item : 0) << '\n';
  return os;
}

#endif //ITEM_H_INCLUDED

// Local Variables:
// mode: c++
// End:
