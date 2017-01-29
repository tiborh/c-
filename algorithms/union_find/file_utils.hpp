#ifndef FILE_UTILS_H_INCLUDED
#define FILE_UTILS_H_INCLUDED

#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>

inline bool file_exists (const char*);
long file_size(const char*);
std::vector<std::vector<unsigned int>> read_file(const char*);

#endif //FILE_UTILS_H_INCLUDED

// Local Variables:
// mode: c++
// End:
