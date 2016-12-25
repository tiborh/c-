#include <iostream>
#include "slist.h"
//#include "slist_elem.h"

using namespace std;

int main() {
  slist_elem* a0e = new slist_elem();
  cout << "default constructor: " << *a0e << endl;
  slist_elem* ae = new slist_elem('a');
  cout << "slist elem with no next address: " << *ae << endl;
  slist_elem* be = new slist_elem('b');
  be->set_na(ae);
  cout << "another elem: " << *be << endl;
  slist_elem* de = new slist_elem(*be);
  cout << "copy-constructed elem: " << *de << endl;
  
  slist a = slist();
  cout << "empty list created: " << a << "(done)" << endl;
  cout << "is empty? " << boolalpha << a.is_empty() << endl;
  cout << "creating another new one with a char\n";
  slist b = slist('a');
  cout << "created: " << b << endl;
  cout << "is empty? " << boolalpha << b.is_empty() << endl;
  b.add('b');
  cout << "added one elem: " << b << endl;
  slist_elem* ce = new slist_elem('c');
  b.push(ce);
  cout << "pushed one elem: " << b << endl;
  cout << "top address: " << b.top() << endl;
  b.reverse();
  cout << "reversed: " << b << endl;
  cout << "top address: " << b.top() << endl;
  slist_elem* popped = b.pop();
  cout << "popped elem: " << *popped << endl;
  cout << "remaining: " << b << endl;
  b.erase();
  cout << "after erase: " << b << endl;
  return 0;
}
