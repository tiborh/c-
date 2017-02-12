#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <ostream>
#include <cassert>

/*
 * This development track has been abandoned.
 * Reason: the node should not try to be too intelligent because it becomes bloated
 *         and still proned to bugs, the list should handle the nodes properly
 */

template<typename T> struct Item;
template<typename T1> std::ostream& operator<<(std::ostream&, const Item<T1>&);

// this "smart node" brings up serious problems (a stupid node will be better)
template<typename T>
struct Item {
  Item():next_item(nullptr),prev_item(nullptr),empty(true),unconnected(true) {}
  Item(T in):id(in),next_item(nullptr),prev_item(nullptr),empty(false),unconnected(true) {}
  Item(const Item& in):id(in.id),next_item(in.next_item),prev_item(in.prev_item),
		       empty(in.empty),unconnected(in.unconnected) {} // problem area!!!
  void set_id(T newid) { id = newid; empty = false; }
  T get_id() const { assert(!empty); return id; }
  Item* get_next() const { return next_item; }
  Item* get_prev() const { return prev_item; }
  bool is_empty() const { return empty; }
  bool is_unconnected() const { return unconnected; }
  bool is_first() const { return(next_item != nullptr && prev_item == nullptr); }
  bool is_mid() const { return(next_item != nullptr && prev_item != nullptr); }
  bool is_last() const { return(next_item == nullptr && prev_item != nullptr); }
  void disconnect_from(Item* next);
  bool is_connected_to(Item *other) const {
    assert( (next_item == other && other->prev_item == this) ||
	    (next_item != other && other->prev_item != this) );
    return (next_item == other && other->prev_item == this);
  }
  bool has_next() const { return next_item != nullptr; }
  bool has_prev() const { return prev_item != nullptr; }
  void connect_to(Item* next) {
    assert(!is_connected_to(next));
    set_next(next);
    next->set_prev(this);
  }
  void connect(Item* prev, Item* next) {
    prev->connect_to(this);
    this->connect_to(next);
  }
  void unconnect();
  template<typename T1> friend std::ostream& operator<<(std::ostream&, const Item<T1>&);
private:
  void set_next(Item* newnext) { next_item = newnext; unconnected = false; }
  void set_prev(Item* newprev) { prev_item = newprev; unconnected = false; }
  T id;
  Item<T> *next_item,*prev_item;
  bool empty,unconnected;
};

template<typename T>
void Item<T>::disconnect_from(Item* next) {
    assert(is_connected_to(next));
    next->prev_item = nullptr;
    if (!next->has_next())
      next->unconnected = true;
    next_item = nullptr;
    if (!has_prev())
      unconnected = true;
}

template<typename T>
void Item<T>::unconnect() {
  assert(!unconnected);
  if (prev_item != nullptr && next_item != nullptr)
    prev_item->connect_to(next_item);
  else {
    if (next_item != nullptr)
      next_item->prev_item = nullptr;
    if (prev_item != nullptr)
      prev_item->next_item = nullptr;
  }
  next_item = nullptr;
  prev_item = nullptr;
  unconnected = true;
}

template<typename T1>
std::ostream& operator<<(std::ostream& os, const Item<T1>& nd) {
  os << &nd << ": " << (!nd.empty ? nd.id : "<null>") << '\n'
     << "\t(prev) " << (nd.prev_item != nullptr ? nd.prev_item : 0) << '\n'
     << "\t(next) " << (nd.next_item != nullptr ? nd.next_item : 0) << '\n';
  return os;
}

#endif //ITEM_H_INCLUDED

// Local Variables:
// mode: c++
// End:
