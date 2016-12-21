#include <iostream>

extern int counter();
//extern void hidden(); // linking error
extern void speak_hidden();

using namespace std;

int main() {
  cout << "Each time counter() is called, the counter value increases.\n";
  
  for (int i = 0; i < 5; ++i)
    cout << "Counter: " << counter() << endl;

  //hidden();
  speak_hidden();
  
  return 0;
}
