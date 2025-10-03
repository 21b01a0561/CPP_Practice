#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include <string>
#include <iostream>

class BatteryMonitor {
private:
    std::string scooterID;
    int chargeCycles;
    float batteryCapacity;
    float originalCapacity;
    bool isActive;
    int* tripDistances;
    int tripCount;

public:
    // Constructor
    BatteryMonitor(std::string id = "", int cycles = 0, float capacity = 0, float original = 0, bool active = true, int trips = 0);

    // Copy Constructor
    BatteryMonitor(const BatteryMonitor& b);

    // Assignment Operator
    BatteryMonitor& operator=(const BatteryMonitor& b);

    // Destructor
    ~BatteryMonitor();

    // Relational operators
    bool operator>(const BatteryMonitor& b) const;
    bool operator<(const BatteryMonitor& b) const;

    // Compound assignment +=
    BatteryMonitor& operator+=(int additionalCycles);

    // Subscript operator
    int& operator[](int index);

    // Unary logical operator !
    bool operator!() const;

    // Stream insertion <<
    friend std::ostream& operator<<(std::ostream& out, const BatteryMonitor& b);
};

#endif
