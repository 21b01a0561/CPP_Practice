#include <iostream>
#include "Polynomial.h"

int main() {
    Polynomial p1;
    p1.setTerm(0, 2, 3); 
    p1.setTerm(1, 3, 1); 

    Polynomial p2;
    p2.setTerm(0, 4, 3); 
    p2.setTerm(1, -3, 1);
    p2.setTerm(2, 5, 0); 

    std::cout << "p1 = " << p1 << "\n";
    std::cout << "p2 = " << p2 << "\n\n";

    Polynomial p3 = p1 + p2;
    std::cout << "p1 + p2 = " << p3 << "\n";

    Polynomial p4 = p1 - p2;
    std::cout << "p1 - p2 = " << p4 << "\n";

    Polynomial p5 = p1 * p2;
    std::cout << "p1 * p2 = " << p5 << "\n";

    p1 += p2;
    std::cout << "p1 += p2 -> p1 = " << p1 << "\n";

    p1 -= p2;
    std::cout << "p1 -= p2 -> p1 = " << p1 << "\n";

    p1 *= p2;
    std::cout << "p1 *= p2 -> p1 = " << p1 << "\n";

    return 0;
}
