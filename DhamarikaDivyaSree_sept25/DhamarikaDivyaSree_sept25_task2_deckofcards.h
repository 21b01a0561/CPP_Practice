#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <vector>   
#include "Card.h"   

// -------------------- DeckOfCards Class --------------------
class DeckOfCards {
private:
    std::vector<Card> deck;  // vector storing 52 cards
    int currentCard;         // index of next card to deal

public:
    // Constructor builds deck of 52 cards
    DeckOfCards();

    // Shuffle the deck
    void shuffle();

    // Deal one card
    Card dealCard();

    // Check if cards remain
    bool moreCards() const;
};

#endif
