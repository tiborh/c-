#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
  string name = "";
  if (argc > 1)
    name = argv[1];
  else
    {
      cout << "お名前は？";
      cin >> name;
    }
  cout << name << "さん、始めまして！\n";
  return 0;
}
