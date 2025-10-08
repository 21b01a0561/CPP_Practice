#ifndef CARD_H
#define CARD_H

#include <string>   

// -------------------- Card Class --------------------
class Card {
private:
    int face;   // index for card face (0–12)
    int suit;   // index for card suit (0–3)

public:
    // Constructor with default values
    Card(int cardFace = 0, int cardSuit = 0);

    // Convert card to string 
    std::string toString() const;

    // Static arrays 
    static const std::string faces[13];
    static const std::string suits[4];
};

#endif
