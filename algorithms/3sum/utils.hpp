#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <random>
#include <set>
#include <array>
#include <cstdio>
#include <cassert>
#include <ctime>

const int NUM = 100;
const int MAX = 100;
const int MIN = -MAX;

std::multiset<int> make_set(int num=NUM,int min=MIN, int max=MAX);
std::array<int,3> proc_input(int, char**);

#endif //UTILS_H_INCLUDED

// Local Variables:
// mode: c++
// End:
