#include <iostream>
#include <cstring>

using namespace std;

class twem {
  friend void foo(const char*);	// foo can access all private parts
  char* a;
  ~twem() { delete(a); }
  char *get_str_pt() { return a; }
public:
  twem(char* instr) {
    a = new char[strlen(instr)+1];
    strcpy(a,instr);
  }
};

void foo(const char *instr) {
  char* temp = new char[strlen(instr) + 1];
  strcpy(temp,const_cast<char*>(instr));
  twem* a = new twem(temp);
  cout << "from twem: " << a->get_str_pt() << '\n';
}

int main() {
  foo("alpha");
  foo("beta");
  return 0;
}
