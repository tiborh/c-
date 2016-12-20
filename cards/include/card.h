#ifndef CARD_H
#define CARD_H
#include <iostream>
#include "../cards.h"
#include "pips.h"

class card
{
    public:
        suit s;
        pips p;
        void assign(int n)
        {
            cd = n;
            s = suit(n/CARDS_IN_SUIT);
            p.assign(n);
        }
        friend std::ostream& operator<<(std::ostream& out, card cd)
        {
            return (out << cd.p << suit_symbol[cd.s] << " ");
        }
    private:
        int cd; // a cd is from 0 to 51
};

#endif // CARD_H
