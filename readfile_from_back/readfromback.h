#ifndef READFROMBACK_H_INCLUDED
#define READFROMBACK_H_INCLUDED

#include <stack>

bool open_file(std::fstream&, const char*, const char*);
int check_flags(const std::fstream&);
unsigned char read_next(std::fstream&);
unsigned char* empty_stack(std::stack<unsigned char>, int);
std::string read_from_rear(const char*);

#endif // READFROMBACK_H_INCLUDED
