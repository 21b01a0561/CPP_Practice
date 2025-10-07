#include "DivyaSree_oct6_task5_DerivedPackages.h"
#include <iostream>

int main() {
    try {
        Package package("Alice", "123 Main St", "Townsville", "TS", "12345",
                        "Bob", "456 Oak St", "Cityville", "CV", "67890",
                        10, 0.5);

        TwoDayPackage twoDay("Carol", "789 Pine St", "Village", "VG", "11223",
                             "Dave", "321 Elm St", "Metropolis", "MT", "44556",
                             5, 0.6, 2.0);

        OvernightPackage overnight("Eve", "135 Maple St", "Hamlet", "HM", "77889",
                                   "Frank", "246 Birch St", "Capital", "CP", "99001",
                                   8, 0.7, 0.25);

        std::cout << "Standard Package cost: " << package.calculateCost() << std::endl;
        std::cout << "Two-Day Package cost: " << twoDay.calculateCost() << std::endl;
        std::cout << "Overnight Package cost: " << overnight.calculateCost() << std::endl;
    }
    catch (std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
