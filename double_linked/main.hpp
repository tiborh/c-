#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "Deque.hpp"
#include <string>

const char* THE_DAYS[7] = {"月","火","水","木","金","土","日"};
const int NUM_OF_DAYS = 7;

void item_test();
void simple_stack_test();
void simple_queue_test();
void remove_last_test();
void corner_case_tests();
template<typename T1> void iterator_test();

#endif //MAIN_H_INCLUDED

// Local Variables:
// mode: c++
// End:
