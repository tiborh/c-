#include "line_collector.h"

using namespace std;

deque<line*> linecollector()
{
    deque<line*> linecollect;
    //stringstream ss = {};
    string instr;
    while(getline(cin,instr,'\n'))
    {
        size_t vtab = instr.find(char(0x0B));
        if (vtab != string::npos)
            instr.erase(vtab,1);
        //clog << "string: " << instr << '\n';
        line *aLine = new line(instr);
        //clog << "Line: " << *aLine << '\n';
        //clog << "Validity: " << boolalpha << aLine->is_valid() << '\n';
        if (aLine->is_valid())
            linecollect.push_back(aLine);
        else
            cerr << "Invalid line: " << instr << '\n';
    }
    return linecollect;
}
