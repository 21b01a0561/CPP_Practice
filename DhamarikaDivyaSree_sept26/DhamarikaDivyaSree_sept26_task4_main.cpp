#include <iostream>
#include "RationalNumber.h"

int main() {
    // Create two RationalNumber objects
    RationalNumber r1(3, 4); 
    RationalNumber r2(5, 6); 

    // Display the fractions
    std::cout << "r1 = " << r1 << "\n";
    std::cout << "r2 = " << r2 << "\n\n";

    // ---------------- Arithmetic Operations ----------------
    std::cout << "r1 + r2 = " << (r1 + r2) << "\n";  // addition
    std::cout << "r1 - r2 = " << (r1 - r2) << "\n";  // subtraction
    std::cout << "r1 * r2 = " << (r1 * r2) << "\n";  // multiplication
    std::cout << "r1 / r2 = " << (r1 / r2) << "\n\n"; // division

    // ---------------- Relational Operations ----------------
    std::cout << "r1 == r2? " << (r1 == r2 ? "Yes" : "No") << "\n";
    std::cout << "r1 != r2? " << (r1 != r2 ? "Yes" : "No") << "\n";
    std::cout << "r1 < r2? " << (r1 < r2 ? "Yes" : "No") << "\n";
    std::cout << "r1 <= r2? " << (r1 <= r2 ? "Yes" : "No") << "\n";
    std::cout << "r1 > r2? " << (r1 > r2 ? "Yes" : "No") << "\n";
    std::cout << "r1 >= r2? " << (r1 >= r2 ? "Yes" : "No") << "\n";

    return 0; 
}
