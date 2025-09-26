#include "DoubleSubscriptedArray.h"  
#include <iostream>                  
int main() {
    // Create a constant array (testing const correctness)
    const DoubleSubscriptedArray constArr(2, 2);   
    std::cout << "Const array (initialized with 0s):\n" << constArr;

    // Create a 3x4 array
    DoubleSubscriptedArray a(3, 4);                 

    std::cout << "\nEnter 12 integers for 3x4 array:\n";
    std::cin >> a;                                  
    std::cout << "\nArray a is:\n" << a;            

    // Modify an element using operator()
    a(1, 2) = 99;                                   
    std::cout << "\nAfter modifying element (1,2):\n" << a;

    // Copy constructor test
    DoubleSubscriptedArray b = a;                   // Deep copy into b
    std::cout << "\nCopied array b from a:\n" << b;

    // Equality test
    std::cout << "\nAre a and b equal? " << (a == b ? "Yes" : "No") << '\n';

    // Modify b
    b(0, 0) = -1;                                   // Change element (0,0) in b
    std::cout << "\nAfter modifying b(0,0):\n" << b;
    std::cout << "Are a and b equal now? " << (a == b ? "Yes" : "No") << '\n';

    return 0;                                       
}
