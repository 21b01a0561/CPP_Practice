#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <vector>
#include "Card.h"

class DeckOfCards {
private:
    std::vector<Card> deck;
    int currentCard;

public:
    DeckOfCards();

    void shuffle();
    Card dealCard();
};

#endif
