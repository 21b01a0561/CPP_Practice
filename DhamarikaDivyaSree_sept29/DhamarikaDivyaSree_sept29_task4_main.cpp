#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DhamarikaDivyaSree_sept29_task4_Race.h"

int main() {
    int tortoisePos = 1;
    int harePos = 1;

    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Race start message
    std::cout << "BANG !!!!!\nAND THEY'RE OFF !!!!!\n";

    // Race loop
    while (tortoisePos < FINISH && harePos < FINISH) {
        moveTortoise(&tortoisePos);
        moveHare(&harePos);

        // Clamp positions
        if (tortoisePos < 1) tortoisePos = 1;
        if (harePos < 1) harePos = 1;

        printRaceTrack(tortoisePos, harePos);
    }

    // Determine winner
    if (tortoisePos >= FINISH && harePos >= FINISH) {
        std::cout << "It's a tie!\n";
    } else if (tortoisePos >= FINISH) {
        std::cout << "TORTOISE WINS!!! YAY!!!\n";
    } else {
        std::cout << "HARE WINS. Yuch.\n";
    }

    return 0;
}

