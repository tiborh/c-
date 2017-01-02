#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstring>

using namespace std;

const int PROBRANGE = 100;
const int NUM_OF_TRIES = 100000;

bool prob(double probval=0.5) {
  assert(probval > 0 && probval < 1.00);
  int probint = static_cast<int>(probval*PROBRANGE);
  int randval = rand() % PROBRANGE;
  // cout << " probval: " << probval
  //      << " probint: " << probint
  //      << " randval: " << randval << '\n';
  return randval < probint ? true : false;
}

void help(const char* progname) {
  cout << "usage: " << progname
       << " [0 < probability value < 1.00]\n";
  exit(0);
}

struct boolcounter {
  int trues;
  int falses;
};

int main(int argc, char** argv) {
  double probval;
  int readsuccess;
  int trynum = NUM_OF_TRIES;
  if (argc > 2) {
    int num = 0;
    int readsuccess = sscanf(argv[2],"%d",&num);
    if (readsuccess > 0)
      trynum = num;
  } 
  if (argc < 2)
    probval = 0.5;
  else if (0 == strcmp(argv[1],"-h") ||
	   0 == strcmp(argv[1],"-help"))
    help(argv[0]);
  else {
    readsuccess = sscanf(argv[1],"%lf",&probval);
    if (readsuccess == 0) help(argv[0]);
    if (probval <= 0 || probval >= 1) help(argv[0]);
  }
  srand(time(0));

  boolcounter c = {0,0};
  for (int i = 0; i < trynum; ++i) {
    bool result = prob(probval);
    if (result == true)
      ++c.trues;
    else
      ++c.falses;
  }
  cout << setw(7) << "true: " << c.trues << " ("
       << setprecision(4) << 100*((double)c.trues/trynum)
       << "%)\n";
  cout << setw(7) << "false: " << c.falses << " ("
       << setprecision(4) << 100*((double)c.falses/trynum)
       << "%)\n";
  return 0;
}
