// main.cpp
#include <iostream>
#include "Complex.h"

int main() {
    Complex x;
    Complex y(4.3, 8.2);
    Complex z(3.3, 1.1);

    std::cout << "Enter a complex number (real and imaginary parts): ";
    std::cin >> x;

    std::cout << "\nYou entered x: " << x << "\n";
    std::cout << "y: " << y << "\n";
    std::cout << "z: " << z << "\n";

    // Addition
    Complex sum = y + z;
    std::cout << "\ny + z = " << sum << "\n";

    // Subtraction
    Complex diff = y - z;
    std::cout << "y - z = " << diff << "\n";

    // Multiplication
    Complex prod = y * z;
    std::cout << "y * z = " << prod << "\n";

    // Comparisons
    std::cout << "\nComparisons:\n";
    std::cout << "y == z ? " << (y == z ? "true" : "false") << "\n";
    std::cout << "y != z ? " << (y != z ? "true" : "false") << "\n";

    return 0;
}
