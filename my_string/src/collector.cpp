#include "collector.h"

using namespace std;

collector::collector(): len(0)
{
    in_str = new char[1];
    assert(in_str != 0);
    in_str[0] = 0;
}
collector::collector(const char* s): len(strlen(s))
{
    in_str = new char[len + 1];
    assert(in_str != 0);
    strcpy(in_str,s);
}
collector::~collector()
{
    delete[] in_str;
}
char* collector::get() const
{
    char* out_str;
    out_str = new char[len + 1];
    assert(out_str != 0);
    strcpy(out_str,in_str);
    return out_str;
}
void collector::set(const char* s)
{
    len = strlen(s);
    delete[] in_str;
    in_str = new char[len + 1];
    assert(in_str != 0);
    strcpy(in_str,s);
}
void collector::cat(const char* s)
{
    char temp[len + 1];
    strcpy(temp,in_str);
    assert(in_str != 0);
    delete[] in_str;
    len += strlen(s);
    in_str = new char[len+1];
    strcpy(in_str,temp);
    strcat(in_str,s);
}

std::ostream& operator<<(std::ostream& os, const collector& c)
{
    os << c.get();
    return os;
}
