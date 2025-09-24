//main.cpp
#include <iostream>
#include "DateAndTime.h"

int main()
{
    // start close to midnight
    DateAndTime dt(12, 31, 2024, 23, 59, 57);

    std::cout << "Testing tick() into the next day:\n";
    for (int i = 0; i < 6; i++) {
        dt.printStandard();
        std::cout << "\n";
        dt.tick();
    }

    return 0;
}
