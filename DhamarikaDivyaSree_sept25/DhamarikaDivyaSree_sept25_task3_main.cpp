#include <iostream>
#include <vector>
#include "DeckOfCards.h"
#include "PokerLogic.h"

int main(){
    DeckOfCards deck;
    deck.shuffle();

    // Deal two hands of 5 cards each
    std::vector<Card> hand1, hand2;
    for(int i=0;i<5;i++){
        hand1.push_back(deck.dealCard());
        hand2.push_back(deck.dealCard());
    }

    std::cout << "Hand 1:\n";
    for(const Card& c: hand1) std::cout << c.toString() << std::endl;

    std::cout << "\nHand 2:\n";
    for(const Card& c: hand2) std::cout << c.toString() << std::endl;

    int score1 = evaluateHand(hand1);
    int score2 = evaluateHand(hand2);

    std::cout << "\nHand 1: " << handToString(score1) << std::endl;
    std::cout << "Hand 2: " << handToString(score2) << std::endl;

    if(score1 > score2) std::cout << "\nHand 1 wins!" << std::endl;
    else if(score2 > score1) std::cout << "\nHand 2 wins!" << std::endl;
    else std::cout << "\nIt's a tie!" << std::endl;

    return 0;
}
