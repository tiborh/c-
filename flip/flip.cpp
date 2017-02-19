#include <iostream>
#include <cstdlib>		// rand(),srand()
#include <ctime>
#include <climits>
#include <bsd/stdlib.h>		// strtonum (libbsd-dev)
#include <err.h>

using namespace std;

const unsigned int NU_OF_FLIPS = 10;
const unsigned int LINE_LENGTH = 10;

int main(int argc, char** argv) {
  unsigned int n;
  if (argc < 2)
    n = NU_OF_FLIPS;
  else {
    const char *errstr;
    n = strtonum(argv[1], 1, UINT_MAX, &errstr);
    if (errstr != NULL)
      errx(1, "number of entered is %s:	%s", errstr, argv[1]);
  }
  srand((unsigned)time(0));
  for (unsigned int i = 0; i < n; ++i) {
    cout << rand() % 2 << ", ";
    if ((i+1) % LINE_LENGTH == 0)
      cout << '\n';
  }
  cout << '\n';
  return 0;
}
