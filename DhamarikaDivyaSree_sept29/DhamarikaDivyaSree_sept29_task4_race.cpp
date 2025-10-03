#include "race.h"
#include <iostream>
#include <cstdlib>  // rand()

// Move the tortoise based on random number
void moveTortoise(int* pos) {
    int i = std::rand() % 10 + 1;  // i in [1,10]

    if (i >= 1 && i <= 5)        // Fast plod (50%)
        *pos += 3;
    else if (i >= 6 && i <= 7)   // Slip (20%)
        *pos -= 6;
    else                          // Slow plod (30%)
        *pos += 1;
}

// Move the hare based on random number
void moveHare(int* pos) {
    int i = std::rand() % 10 + 1;  // i in [1,10]

    if (i >= 1 && i <= 2)         // Sleep (20%)
        *pos += 0;
    else if (i >= 3 && i <= 4)    // Big hop (20%)
        *pos += 9;
    else if (i == 5)              // Big slip (10%)
        *pos -= 12;
    else if (i >= 6 && i <= 8)    // Small hop (30%)
        *pos += 1;
    else                          // Small slip (9-10, 20%)
        *pos -= 2;
}

// Print the race track line
void printRaceTrack(int tortoisePos, int harePos) {
    for (int i = 1; i <= FINISH; i++) {
        if (i == tortoisePos && i == harePos)
            std::cout << "OUCH!!!";
        else if (i == tortoisePos)
            std::cout << "T";
        else if (i == harePos)
            std::cout << "H";
        else
            std::cout << " ";
    }
    std::cout << std::endl;
}
