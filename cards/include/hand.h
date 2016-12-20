#ifndef HAND_H
#define HAND_H
#include <vector>
#include "card.h"

class hand
{
    public:
        hand(int hand_size) { max_hs = hand_size; }
        unsigned int add_card(card);
        friend std::ostream& operator<<(std::ostream& out,hand x)
        {
            std::vector<card>::iterator xi;
            for (xi = x.begin(); xi != x.end(); ++xi)
                out << *xi;
            std::cout << std::endl;
            return out;
        }
        std::vector<card>::iterator begin() { return h.begin(); }
        std::vector<card>::iterator end() { return h.end(); }
        unsigned int get_max_hs() { return max_hs; }
        unsigned int get_hs() { return h.size(); }
    private:
        unsigned int max_hs;
        std::vector<card> h;
};

#endif // HAND_H
