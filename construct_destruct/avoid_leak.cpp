#include <iostream>
#include <ostream>
#include <cstring>
#include <cassert>

// leak avoidance is important with "set" and "cat"

using namespace std;

struct collector {
  collector(): len(0) {
    in_str = new char[1];
    assert(in_str != 0);
    in_str[0] = 0;
  }
  collector(const char* s) {
    len = strlen(s);
    in_str = new char[len + 1];
    assert(in_str != 0);
    strcpy(in_str,s);
  }
  collector(const collector& c) {
    collector(c.get());
  }
  ~collector() { delete[] in_str; }
  char* get() const {
    char* out_str;
    out_str = new char[len + 1];
    assert(out_str != 0);
    strcpy(out_str,in_str);
    return out_str;
  }
  int size() const { return len; }
  void set(const char* s) {
    len = strlen(s);
    delete[] in_str;
    in_str = new char[len + 1];
    assert(in_str != 0);
    strcpy(in_str,s);
  }
  void cat(const char* s) {
    char temp[len + 1];
    strcpy(temp,in_str);
    assert(in_str != 0);
    delete[] in_str;
    len += strlen(s);
    in_str = new char[len+1];
    strcpy(in_str,temp);
    strcat(in_str,s);
  }
  void cat(const collector& s) {
    cat(s.get());
  }
private:
  int len;
  char *in_str;
};

ostream& operator<<(ostream& os, const collector& c) {
  os << c.get();
  return os;
}

int main() {
  collector a = collector();
  cout << "length after empty constructor: " << a.size() << endl;
  a.set("one");
  cout << "set to: " << a << endl;
  a.cat(" two");
  a.cat(" three");
  cout << "after contatenations: " << a << endl;
  collector b = collector("etc");
  cout << "b: " << b << endl;
  a.cat(" ");
  a.cat(b);
  cout << "after the concat of b: " << a << endl;
  return 0;
}
