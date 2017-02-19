#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "stack.hpp"
#include "queue.hpp"
#include "RandomisedQueue.hpp"
#include <vector>
#include <string>

const char* THE_DAYS[7] = {"月","火","水","木","金","土","日"};
const int NUM_OF_DAYS = 7;

void node_test();
void simple_stack_test();
void input_test(int,char**);
template<typename T1> void list_maker(std::vector<std::string>);
template<typename T1> void list_maker(int, char**);
void simple_queue_test();
template<typename T1> void iterator_test();
void testRandomisedQueue();

#endif //MAIN_H_INCLUDED

// Local Variables:
// mode: c++
// End:
