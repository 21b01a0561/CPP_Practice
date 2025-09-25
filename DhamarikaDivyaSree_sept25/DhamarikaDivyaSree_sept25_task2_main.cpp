#include <iostream>
#include "DeckOfCards.h"

int main() {
    DeckOfCards deck;     // create deck
    deck.shuffle();       // shuffle it

    std::cout << "Dealing all 52 cards:" << std::endl;

    int count = 0;        // counter for formatting
    while (deck.moreCards()) {
        const Card dealtCard=deck.dealCard();
        std::cout << deck.dealCard().toString() << "\t";

        if (++count % 3 == 0) // print 3 cards per line
            std::cout << std::endl;
    }

    return 0; 
}
