#include "DhamarikaDivyasree_sept25_task2_DeckOfCards.h"
#include <cstdlib>   // for rand(), srand()
#include <ctime>     
#include <algorithm> // for std::swap

// Constructor builds deck of 52 cards
DeckOfCards::DeckOfCards() {
    currentCard = 0; // setting to first card for start 
    for (int suit = 0; suit < 4; ++suit) {
        for (int face = 0; face < 13; ++face) {
            deck.push_back(Card(face, suit)); // for adding card to deck
        }
    }
}

// For Shuffling cards
void DeckOfCards::shuffle() {
    std::srand(static_cast<unsigned>(std::time(0))); //srand for random generating
    for (size_t i = 0; i < deck.size(); ++i) {
        int j = std::rand() % deck.size(); // random index
        std::swap(deck[i], deck[j]);       // swap two cards
    }
    currentCard = 0; // reset dealing position to first card
}

// Deal one card
Card DeckOfCards::dealCard() {
    if (moreCards()) {
        return deck[currentCard++];  // return next card and move forward
    } else {
        return Card(-1, -1);         // invalid card if none left
    }
}

// Check for cards remain
bool DeckOfCards::moreCards() const {
    return currentCard < deck.size();
}

