#ifndef INPUT_PROCESSOR_H
#define INPUT_PROCESSOR_H

//#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "util.h"

class input_processor
{
    public:
        input_processor(const char *);
        input_processor();
        ~input_processor();
    protected:
        template <typename T>
        void in_proc(T*);
    private:
};

#endif // INPUT_PROCESSOR_H
