#include "DivyaSree_oct1_task2_BatteryMonitor.h"
#include <iostream>

int main() {
    // 1. Create two BatteryMonitor objects
    BatteryMonitor s1("SCT101", 300, 4.0f, 5.0f, true, 3);
    BatteryMonitor s2("SCT202", 150, 3.5f, 5.0f, true, 2);

    // 2. Populate trips (cannot make s1/s2 const because trips are modified)
    s1[0] = 12; s1[1] = 18; s1[2] = 25;
    s2[0] = 10; s2[1] = 15;

    // 3. Display both scooters as const references
    const BatteryMonitor& cs1 = s1;
    const BatteryMonitor& cs2 = s2;
    std::cout << "Scooter 1:\n" << cs1;
    std::cout << "Scooter 2:\n" << cs2;

    // 4. Compare battery health using const objects
    if (cs1 > cs2) std::cout << "s1 has better battery health than s2.\n";
    else if (cs1 < cs2) std::cout << "s1 has worse battery health than s2.\n";
    else std::cout << "s1 and s2 have equal battery health.\n";

    // 5. Simulate 50 charge cycles and degradation
    s1 += 50;
    std::cout << "\nAfter adding 50 charge cycles to s1:\n" << s1;

    // 6. Check if scooter is inactive using const object
    if (!cs2) std::cout << "s2 is inactive.\n";
    else std::cout << "s2 is active.\n";

    // 7. Copy scooter
    BatteryMonitor s3;
    s3 = s1;
    std::cout << "\nCopied scooter s3 from s1:\n" << s3;

    // 8. Destructor will clean up dynamic memory automatically at end of scope

    return 0;
}

