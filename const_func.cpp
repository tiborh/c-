#include <iostream>

using namespace std;

struct tester {
  int id;
  void init() { give_value(id); }
private:
  void give_value(int& i) const { // can only change parameter directly passed to it
    static int stored = 0;
    i = stored++;
  }
};

int main() {
  tester a = tester();
  a.init();
  cout << "a.id: " << a.id << endl;
  a.init();
  cout << "a.id: " << a.id << endl;
  return 0;
}
