#ifndef FILE_CHECKS_H_INCLUDED
#define FILE_CHECKS_H_INCLUDED

#include <fstream> // for f_is_good
#include <unistd.h> // for f_*_access functions

int f_stat(const char*);
int check_flags(const std::fstream&);

inline bool f_is_good(const char* fn)
{
    std::ofstream fh(fn); // name.c_str() if c++ string
    if (fh.good())
    {
        fh.close();
        return true;
    } else
    {
        fh.close();
        return false;
    }

}

inline bool f_exists (const char* fn) {
    return ( access( fn, F_OK ) != -1 );
}

inline bool f_read_access (const char* fn) {
    return ( access( fn, R_OK ) != -1 );
}

inline bool f_write_access (const char* fn) {
    return ( access( fn, W_OK ) != -1 );
}

inline bool f_execute_access (const char* fn) {
    return ( access( fn, X_OK ) != -1 );
}

#endif // FILE_CHECKS_H_INCLUDED
