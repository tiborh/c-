#include <iostream>
#include <cstring>

//failed attempt. only an experiment

using namespace std;

const int MAXNUMLENGTH = 3;
const char* IDPREFIX = "ID";

struct refcount {
  refcount(): refcounter(1) {
    if (idnum > 0)
      cout << "idnum: " << idnum << '\n';
    else
      idnum = 0;
    id = new char[strlen(IDPREFIX) + MAXNUMLENGTH + 1];
    strcpy(id,IDPREFIX);
    strcat(id,to_string(idnum++).c_str());
  }
  refcount(const refcount& other): refcounter(1) {
    ++refcounter;
    idnum++;
    id = other.id;		// shallow copy
  }
  ~refcount() {
    cout << "idnum: " << idnum << '\n';
    cout << "destructor called ... ";
    if (--refcounter == 0) {
      delete(id);
      cout << "and it destroyed an object\n";
    } else {
      cout << "but it only reduced refcounter\n";
    }
  }
  int get_idnum() { return idnum; }
  friend ostream& operator<<(ostream&, const refcount&);
private:
  static int idnum;
  char *id;
  int refcounter;
};

int refcount::idnum;

ostream& operator<<(ostream& os, const refcount& rc) {
  os << "ID: " << rc.id
     << " (idnum: " << rc.idnum
     << "), refcounter: " << rc.refcounter;
  return os;
}

int main() {
  refcount a = refcount();
  refcount *a1 = &a;
  refcount *a2 = a1;
  cout << "*a2: " << *a2 << '\n';
  refcount b = refcount(a);
  cout << "b: " << b << '\n';
  return 0;
}
