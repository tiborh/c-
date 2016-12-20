#include "person.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

const int DATE_COMPS = 3;
const char* DEFAULT_DATE_STR = "1800 1 1";

Person::Person(char* name_str, char* birthday_str, char* address_str)
{
    name = name_str;
    try
    {
        birthday = parse_birthday_str(birthday_str);
    }
    catch (char* error_txt)
    {
        cout << error_txt << endl;
        delete error_txt;
        birthday = parse_birthday_str(const_cast<char*>(DEFAULT_DATE_STR));
    }
    address = address_str;
}

int* Person::parse_birthday_str(char* birthday_str)
{
    int* out_birth = new int[DATE_COMPS];
    istringstream date_comp (birthday_str);
    for (int i=0; i<DATE_COMPS; i++)
    {
        int date_val;
        if (!(date_comp >> date_val))
        {
            char* thrown_msg = new char[512];
            sprintf(thrown_msg,"Cannot convert date component [%d] of \"%s\"",i,birthday_str);
            throw thrown_msg;
        }
        out_birth[i] = date_val;
    }
    return out_birth;
}

char* Person::get_name() const
{
    return name;
}

char* Person::get_address() const
{
    return address;
}

char* Person::get_birthday() const
{
    char* birthday_str = new char[11];
    sprintf(birthday_str,"%d %d %d",birthday[0],birthday[1],birthday[2]);
    return birthday_str;
}

Person::~Person()
{
    delete [] birthday;
}
