#ifndef CARDS_H_INCLUDED
#define CARDS_H_INCLUDED

#ifndef CARDS_IN_SUIT
#define CARDS_IN_SUIT 13
#endif // CARDS_IN_SUIT

#ifndef NUM_OF_SUITS
#define NUM_OF_SUITS 4
#endif // NUM_OF_SUITS

#ifndef NUM_OF_CARDS
#define NUM_OF_CARDS (NUM_OF_SUITS * CARDS_IN_SUIT)
#endif // NUM_OF_CARDS

const char pips_symbol[CARDS_IN_SUIT+1] = { '?', 'A', '2', '3', '4', '5', '6', '7', '8', '9',
                         'T', 'J', 'Q', 'K' };

const char suit_symbol[NUM_OF_SUITS] = { 'c', 'd', 'h', 's' };

enum suit { clubs, diamonds, hearts, spades };

#endif // CARDS_H_INCLUDED
