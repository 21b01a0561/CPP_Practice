#include "Card.h"

// Initializing static arrays of card faces
const std::string Card::faces[13] = {
    "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
    "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

// Initializing static arrays of card suits
const std::string Card::suits[4] = {
    "Hearts", "Diamonds", "Clubs", "Spades"
};

// Constructor
Card::Card(int cardFace, int cardSuit) {
    face = cardFace;
    suit = cardSuit;
}

// Return card as string
std::string Card::toString() const {
    return faces[face] + " of " + suits[suit];
}
