#include "DeckOfCards.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

DeckOfCards::DeckOfCards() {
    currentCard = 0;
    for(int s=0; s<4; s++)
        for(int f=0; f<13; f++)
            deck.push_back(Card(f,s));
}

void DeckOfCards::shuffle() {
    std::srand(static_cast<unsigned>(std::time(0)));
    for(size_t i=0;i<deck.size();i++){
        int j = std::rand() % deck.size();
        std::swap(deck[i], deck[j]);
    }
    currentCard = 0;
}

Card DeckOfCards::dealCard() {
    if(currentCard < deck.size()) return deck[currentCard++];
    return Card(-1,-1); // invalid card
}
