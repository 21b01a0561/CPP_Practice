#include <iostream>
#include "DhamarikaDivyaSree_sept24_task1_Time.h"

int main()
{
    // Normal test: incrementing seconds
    Time t1(12, 34, 56);
    std::cout << "Starting time: ";
    t1.printStandard();
    std::cout << "\n";

    for (int i = 0; i < 10; i++) {
        t1.tick();           
        t1.printStandard();  
        std::cout << "\n";
    }

    // Case A: Incrementing into the next minute
    std::cout << "\n--- Test Case 1: Increment into next minute ---\n";
    Time t2(14, 59, 58); 
    for (int i = 0; i < 5; i++) {
        t2.printStandard();
        std::cout << "\n";
        t2.tick();
    }

    // Case B: Incrementing into the next hour
    std::cout << "\n--- Test Case 2: Increment into next hour ---\n";
    Time t3(10, 59, 59);
    for (int i = 0; i < 3; i++) {
        t3.printStandard();
        std::cout << "\n";
        t3.tick();
    }

    // Case C: Incrementing into the next day
    std::cout << "\n--- Test Case 3: Increment into next day ---\n";
    Time t4(23, 59, 58);
    for (int i = 0; i < 5; i++) {
        t4.printStandard();
        std::cout << "\n";
        t4.tick();
    }

    return 0;
}
