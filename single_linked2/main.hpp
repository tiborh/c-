#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "stack.hpp"
#include "queue.hpp"
#include <vector>
#include <string>

void node_test();
void simple_stack_test();
void input_test(int,char**);
template<typename T1> void list_maker(std::vector<std::string>);
template<typename T1> void list_maker(int, char**);
void simple_queue_test();

#endif //MAIN_H_INCLUDED

// Local Variables:
// mode: c++
// End:
