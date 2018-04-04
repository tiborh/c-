#include <iostream>
#include <cstring>

using namespace std;

int main() {
  void* ptr = nullptr;
  cout << "size of null pointer: " << sizeof(ptr) << endl;
  // cout << "size of null pointer target: " << sizeof(*ptr) << endl; // error
  cout << "size of null pointer target (cast as int): " << sizeof(*(int*)ptr) << endl;
  int a = 12;
  cout << "size of integer: " << sizeof(a) << endl;
  cout << "size of integer address: " << sizeof(&a) << endl;
  ptr = &a;
  
  cout << "ptr: " << ptr << endl;

  cout << "a == " << a << endl;
  *(int*)ptr = 15;
  cout << "a == " << a << endl;

  char* buffer = new char[8];
  cout << "buffer: \"" << buffer << "\"" << endl;
  memset(buffer,0x41,8);
  cout << "buffer: \"" << buffer << "\"" << endl;

  char** ptr_buffer = &buffer;
  cout << "pointer to pointer: " << ptr_buffer << endl;
  cout << "pointer to pointer dereferenced: " << *ptr_buffer << endl;
  
  return 0;
}
