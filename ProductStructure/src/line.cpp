#include "line.h"
#include <iostream>

using namespace std;

void line::split_line(string line_str)
{
    stringstream iss(line_str);
    if (!iss)
        throw "empty stringstream";
    init_pars();
    for (string *an_item : pars)
        {
            string sub;
            if (!getline(iss,sub,sep))
                *an_item = "";
            *an_item = sub;
        }
}

void line::init_pars()
{
    for(string *a_par : {&num,&rev,&nam,&des})
            pars.push_back(a_par);
}

bool line::validate()
{
    valid = false;

    if (num.length() < min_pno_length)
        return false;
    if (rev.length() < min_rst_length)
        return false;
    if (nam.length() < min_fdes_length)
        return false;

    valid = true;
    return true;
}

void line::set_tier()
{
    tier = 0;
    while (num.front() == '.')
    {
        ++tier;
        num.erase(0,2);
    }
}
