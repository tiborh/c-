#include "hand.h"
using namespace std;

unsigned int hand::add_card(card c)
{
    if (h.size() < max_hs)
        h.push_back(c);
    else // should never reach this branch, probably an exception would be better.
        cerr << "Hand is full.\n";

    return h.size();
}
