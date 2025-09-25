#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    int face;  // 0-12
    int suit;  // 0-3

public:
    Card(int f = 0, int s = 0);

    int getFace() const;
    int getSuit() const;

    std::string toString() const;
};

#endif
