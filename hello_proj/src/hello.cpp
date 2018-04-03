#include "hello.hpp"

int main(int argc, char** argv) {
  logger("Hello World!");
  std::cin.get(); 		// in case it gets started in graphical env
}
