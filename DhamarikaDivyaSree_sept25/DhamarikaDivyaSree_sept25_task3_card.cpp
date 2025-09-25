#include "Card.h"

// Constructor
Card::Card(int f, int s) : face(f), suit(s) {}

// Get face index
int Card::getFace() const { return face; }

// Get suit index
int Card::getSuit() const { return suit; }

// Convert card to string
std::string Card::toString() const {
    static const std::string faces[13] = { "Ace","Two","Three","Four","Five","Six","Seven",
                                           "Eight","Nine","Ten","Jack","Queen","King" };
    static const std::string suits[4] = { "Hearts","Diamonds","Clubs","Spades" };
    return faces[face] + " of " + suits[suit];
}
