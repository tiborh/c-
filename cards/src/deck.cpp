#include <cstdlib>
#include <ctime>
#include "deck.h"
#include "hand.h"

void deck::init_deck()
{
    for (int i = 0; i < NUM_OF_CARDS; ++i)
    {
        card a_card;
        a_card.assign(i);
        d.push_back(a_card);
    }
}

void deck::shuffle()
{
    std::vector<card>::iterator di;
    std::vector<card>::iterator dstarti = d.begin();
    srand(time(NULL));
    for (di = d.begin(); di != d.end(); ++di)
        std::swap(*di,*(dstarti + (rand() % (NUM_OF_CARDS))));
}

void deck::deal(int num, hand& ahand)
{
    unsigned int maxhs = ahand.get_max_hs();
    unsigned int currhs = ahand.get_hs();
    for(int i = 0; i < num && d.size() > 0 && currhs < maxhs; ++i)
    {
        currhs = ahand.add_card(d.back());
        d.pop_back();
    }

    if (0 == d.size())
        std::cout << "No cards in deck.\n";
}
