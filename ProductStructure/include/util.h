#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstring>
#include "tree.h"

template<typename T1, typename T2>
void print_map(std::map<T1,T2> aMap)
{
    for (typename std::map<T1,T2>::iterator aMapi = aMap.begin(); aMapi != aMap.end(); ++aMapi)
        std::cout << aMapi->first << '\t' << aMapi->second << '\n';
}

bool open_file(std::fstream*,const char*,const char*);

#endif // UTIL_H_INCLUDED
