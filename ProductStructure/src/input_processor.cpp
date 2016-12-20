#include "input_processor.h"

using namespace std;

input_processor::input_processor(const char* fn)
{
    fstream *fh = {};
    if (open_file(fh,fn,"r"))
        in_proc<fstream>(fh);
    else
        throw "file cannot be opened";
}

template <typename T>
void input_processor::in_proc(T *in_stream)
{
    stringstream ss = {};
    string instr;
    while(getline(*in_stream,instr,'\n'))
    {
        size_t vtab = instr.find(char(0x0B));
        if (vtab != string::npos)
            instr.erase(vtab,1);
        ss.clear();
        ss << instr;
        do
        {
            string test;
            getline(ss,test,'\t');
            cout << '\"' << test << "\" (" << test.length() << ")\n";
        }
        while(ss.good());
    }
}

input_processor::~input_processor()
{
    //dtor
}
