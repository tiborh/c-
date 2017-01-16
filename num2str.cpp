#include <iostream>
#include <string>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <sstream>

const char* NAME_PALETTE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int NAME_PALETTE_SIZE = strlen(NAME_PALETTE);

using namespace std;

string num_to_str(int input) {
  assert(input >= 0);
  stringstream ss;
  string outstr;
  if (input < NAME_PALETTE_SIZE) {
    ss << NAME_PALETTE[input];
    ss >> outstr;
    return outstr;
  }
  while(input >= 0) {
    if (input >= NAME_PALETTE_SIZE) {
      ss << NAME_PALETTE[NAME_PALETTE_SIZE-1];
      input -= NAME_PALETTE_SIZE;
    } else {
      ss << NAME_PALETTE[input];
      input -= NAME_PALETTE_SIZE;
    }
  }
  ss >> outstr;
  return outstr;
}

int main(int argc, char** argv) {
  int readsuccess = 0, num_to_convert=0;
  if (argc > 1) {
    readsuccess = sscanf(argv[1],"%d",&num_to_convert);
    assert(readsuccess > 0);
    assert(num_to_convert >= 0);
    cout << "result: " << num_to_str(num_to_convert) << '\n';
  }
  else
    cout << "Give a positive integer to convert to string as an argument.\n";
  
  return 0;
}
