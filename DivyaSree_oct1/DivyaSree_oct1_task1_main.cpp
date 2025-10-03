#include "HybridVehicle.h"
#include <iostream>

int main() {
    // 1. Create two HybridVehicle objects
    HybridVehicle v1("Prius", 120.5, 80.0, 4.5);
    HybridVehicle v2("Volt", 100.0, 90.0, 5.0);


    v1[0] = 50; v1[1] = 60;
    v2[0] = 70; v2[1] = 40;

    // 2. Display both vehicles
    std::cout << "Vehicle 1:\n" << v1;
    std::cout << "Vehicle 2:\n" << v2;

    // 3. Combine using + and display
    HybridVehicle v3 = v1 + v2;
    std::cout << "\nCombined Vehicle:\n" << v3;

    // 4. Compare efficiency using ==
    if (v1 == v2) std::cout << "v1 and v2 have the same efficiency." << std::endl;
    else std::cout << "v1 and v2 have different efficiency." << std::endl;

    // 5. Increment v1 with a dummy trip
    ++v1;
    std::cout << "\nAfter adding dummy trip to v1:\n" << v1;

    // 6. Access a trip using []
    std::cout << "v2 first trip distance: " << v2[0] << std::endl;

    // 7. Use () to get total distance
    std::cout << "v1 total distance: " << v1() << std::endl;

    // 8. Use float() to get efficiency
    std::cout << "v2 fuel efficiency: " << float(v2) << " km/L" << std::endl;

    // 9. Assignment = to copy v1 to v4
    HybridVehicle v4;
    v4 = v1;
    std::cout << "\nCopied Vehicle v4 from v1:\n" << v4;

    return 0;
}
