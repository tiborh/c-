#include <iostream>
#include <cstring>

using namespace std;

class twam {
public:
  void foo(const char*);
};

class twem {
  friend class twam;	// twam can access all private parts
  char* a;
  ~twem() { delete(a); }
  char *get_str_pt() { return a; }
public:
  twem(char* instr) {
    a = new char[strlen(instr)+1];
    strcpy(a,instr);
  }
};

void twam::foo(const char *instr) {
  char* temp = new char[strlen(instr) + 1];
  strcpy(temp,const_cast<char*>(instr));
  twem* a = new twem(temp);
  cout << "from twem: " << a->get_str_pt() << '\n';
}

int main() {
  twam a = twam();
  a.foo("alpha");
  a.foo("beta");
  return 0;
}
