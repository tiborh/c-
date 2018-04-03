#include <iostream>
#include <string>

long factorial(int n) {
  if (n == 0)
    return 1; // base step
  else
    return n * factorial(n-1);
}

int main(int argc, char** argv) {
  if (argc > 1) {
    std::string::size_type sz;
    std::cout << argv[1] << "! == " << factorial(std::stoi(argv[1],&sz)) << '\n';
  }
  return 0;
}
