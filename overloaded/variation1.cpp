#include "functions.h"

int f(int i)
{
    return(i);
}

double f(double)
{
    return(f(1) + f(1.0));
}
