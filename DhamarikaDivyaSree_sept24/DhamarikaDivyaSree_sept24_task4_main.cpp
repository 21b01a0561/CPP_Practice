#include <iostream>
#include "Time.h"

int main()
{
    Time t;

    std::cout << "Initial time (default constructor): ";
    t.printStandard();
    std::cout << "\n\n";

    // test valid values
    if (!t.setHour(13))
        std::cout << "Error: Invalid hour!\n";
    if (!t.setMinute(45))
        std::cout << "Error: Invalid minute!\n";
    if (!t.setSecond(30))
        std::cout << "Error: Invalid second!\n";

    std::cout << "After setting valid values: ";
    t.printStandard();
    std::cout << "\n\n";

    // test invalid values
    if (!t.setHour(99))
        std::cout << "Error: Invalid hour (99)!\n";
    if (!t.setMinute(-5))
        std::cout << "Error: Invalid minute (-5)!\n";
    if (!t.setSecond(70))
        std::cout << "Error: Invalid second (70)!\n";

    std::cout << "After trying invalid values : ";
    t.printStandard();
    std::cout << "\n";

    return 0;
}
