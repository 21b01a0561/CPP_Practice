#include <iostream>
#include "HugeInt.h"

int main() {
    // Initial HugeInt objects
    HugeInt n1(7654321);
    HugeInt n2(7891234);
    HugeInt n3("99999999999999999999999999999");
    HugeInt n4("1");
    HugeInt n5;

    std::cout << "n1 is " << n1 << "\n n2 is " << n2
              << "\n n3 is " << n3 << "\n n4 is " << n4
              << "\n n5 is " << n5 << "\n\n";

    // Addition: HugeInt + HugeInt
    n5 = n1 + n2;
    std::cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

    // Addition: HugeInt + HugeInt (large numbers)
    std::cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

    // Addition: HugeInt + int
    n5 = n1 + 9;
    std::cout << n1 << " + 9 = " << n5 << "\n\n";

    // Addition: HugeInt + string
    n5 = n2 + "10000";
    std::cout << n2 << " + " << "10000 = " << n5 << "\n\n";

    // Multiplication
    HugeInt n6 = n1 * n2;
    std::cout << n1 << " * " << n2 << " = " << n6 << "\n\n";

    // Division
    HugeInt n7("100");
    HugeInt n8("25");
    HugeInt n9 = n7 / n8;
    std::cout << n7 << " / " << n8 << " = " << n9 << "\n\n";

    // Relational operator tests
    HugeInt n10("12345");
    HugeInt n11("6789");

    std::cout << "Comparisons:\n";
    std::cout << n10 << " == " << n11 << "? " << (n10 == n11 ? "Yes" : "No") << "\n";
    std::cout << n10 << " != " << n11 << "? " << (n10 != n11 ? "Yes" : "No") << "\n";
    std::cout << n10 << " < " << n11 << "? " << (n10 < n11 ? "Yes" : "No") << "\n";
    std::cout << n10 << " <= " << n11 << "? " << (n10 <= n11 ? "Yes" : "No") << "\n";
    std::cout << n10 << " > " << n11 << "? " << (n10 > n11 ? "Yes" : "No") << "\n";
    std::cout << n10 << " >= " << n11 << "? " << (n10 >= n11 ? "Yes" : "No") << "\n";

    return 0;
}
