#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "point.h"
#include "graph.h"
#include "digraph.h"
#include "path.h"

const char* INPUT_FN = "graph_data.txt";
const char* NAME_PALETTE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void point_demo();
void route_demo();
void path_demo();
graph graph_demo();
void graph_copy_demo(const graph&);
void digraph_demo();
inline bool file_exists (const char*);
long file_size(std::string);
graph read_file(const char* input_filename = INPUT_FN);
std::string num_to_str(int);

#endif //MAIN_H_INCLUDED

// Local Variables:
// mode: c++
// End:
