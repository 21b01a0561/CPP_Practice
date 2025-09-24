#include <iostream>
#include "Date.h"

int main()
{
    // ---  Increment into the next month ---
    std::cout << "--- Increment into next month ---\n";
    Date d1(1, 30, 2025); 
    for (int i = 0; i < 5; i++) {
        d1.print();
        std::cout << "\n";
        d1.nextDay();
    }

    // ---  Increment into the next year ---
    std::cout << "\n--- Increment into next year ---\n";
    Date d2(12, 30, 2025);
    for (int i = 0; i < 5; i++) {
        d2.print();
        std::cout << "\n";
        d2.nextDay();
    }

    // --- Leap year test ---
    std::cout << "\n--- Leap Year Test ---\n";
    Date d3(2, 27, 2024); 
    for (int i = 0; i < 5; i++) {
        d3.print();
        std::cout << "\n";
        d3.nextDay();
    }

    return 0;
}
