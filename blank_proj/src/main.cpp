#include "blank.hpp"

using namespace std;

int main(int argc, char** argv) {

  Blank* a = new Blank();
  cout << *a << endl;

  delete(a);
  return 0;
}
