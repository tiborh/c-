#ifndef PIPS_H
#define PIPS_H
#include <iostream>
#include "../cards.h"

class pips
{
    public:
        void assign(int n) { p = n % CARDS_IN_SUIT + 1; }
        friend std::ostream& operator<<(std::ostream& out, pips x)
        {
            return (out << pips_symbol[x.p]);
        }
    private:
        int p;
};

#endif // PIPS_H
