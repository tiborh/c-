#include <iostream>
#include "namespaces.h"

using namespace sample_space;

int main() {
  int i = 13;

  std::cout << "Variables from sample_space: '" << so_is
	    << "' and '" << so_that << "'" << std::endl;

  using namespace std;
  cout << "From current one: " << i << endl;
  
  return 0;
}
