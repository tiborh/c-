#include "utils.hpp"

std::array<int,3> proc_input(int argc, char **argv) {
  int num = NUM;
  int min = MIN;
  int max = MAX;
  int readsuccess = 0, tempnum = 0;
  if (argc > 2) {
    readsuccess = sscanf(argv[2],"%d",&tempnum);
    if (readsuccess > 0)
      max = tempnum;
    tempnum = 0;
    assert(max > 0);
    min = -max;
  }
  if (argc > 1) {
    readsuccess = sscanf(argv[1],"%d",&tempnum);
    if (readsuccess > 0)
      num = tempnum;
  }

  std::array<int,3> outarr = {num,min,max};
  
  return outarr;
}

std::multiset<int> make_set(int num, int min, int max) {
  std::multiset<int> outset;
  std::uniform_int_distribution<int> u(min,max);
  std::default_random_engine e(time(0));

  for(int i = 0; i < num; ++i)
    outset.insert(u(e));

  return(outset);
}
