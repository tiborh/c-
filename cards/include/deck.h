#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <vector>
#include "../cards.h"
#include "card.h"
#include "hand.h"

class deck
{
    public:
        void init_deck();
        void shuffle();
        void deal(int, hand&);
        int cards_left() { return d.size(); }
        friend std::ostream& operator<<(std::ostream& out,deck x)
        {
            std::vector<card>::iterator xi;
            int i = 0;
            for (xi = x.begin(); xi != x.end(); ++xi,++i)
            {
                if (i % CARDS_IN_SUIT == 0)
                    out << std::endl;
                out << *xi;
            }
            std::cout << std::endl;
            return out;
        }
        std::vector<card>::iterator begin() { return d.begin(); }
        std::vector<card>::iterator end() { return d.end(); }
    private:
        std::vector<card> d;
};

#endif // DECK_H
