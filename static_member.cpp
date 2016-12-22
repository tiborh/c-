#include <iostream>

using namespace std;

struct Id {
  Id(): id(create_id()) {}
  int get_id() { return id; }
private:
  static int create_id() {	// class member function
    static int idcount = 0;	// "state" variable of the function
    return idcount++;
  }
  int id;
};

int main() {
  Id i1 = Id();
  cout << "i1: " << i1.get_id() << endl;
  Id i2 = Id();
  cout << "i2: " << i2.get_id() << endl;
  return 0;
}
