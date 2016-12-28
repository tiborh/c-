#include "friend.h"

using namespace std;

void foo() {
  char* temp = new char[6];
  strcpy(temp,"alpha");
  twem a = {temp};                    ;
  cout << "from twem: " << a.get_str_pt() << '\n';
}
  
int main() {
  srand(time(NULL));
  foo();
  cout << "number from twim: " << twim::gen_num();
  return 0;
}
