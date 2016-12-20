#include <iostream>
#include "include/deck.h"
#include "include/card.h"

using namespace std;

int main()
{
    deck a_deck;
    cout << "\nFresh deck:\n";
    a_deck.init_deck();
    cout << a_deck;

    cout << "\nShuffled deck:\n";
    a_deck.shuffle();
    cout << a_deck;

    cout << "\nDeal 5 cards:\n";
    hand a_hand(5);
    a_deck.deal(6,a_hand);
    a_deck.deal(1,a_hand); //should be ineffective, over max size
    cout << a_deck;
    cout << "And the hand:\n";
    cout << a_hand;

    return 0;
}
