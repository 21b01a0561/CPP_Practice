#include "DivyaSree_oct1_task2_BatteryMonitor.h"

// Constructor
BatteryMonitor::BatteryMonitor(std::string id, int cycles, float capacity, float original, bool active, int trips) {
    scooterID = id;
    chargeCycles = cycles;
    batteryCapacity = capacity;
    originalCapacity = original;
    isActive = active;
    tripCount = trips;
    tripDistances = new int[tripCount];
    for (int i = 0; i < tripCount; i++) tripDistances[i] = 0;
}

// Copy Constructor (deep copy)
BatteryMonitor::BatteryMonitor(const BatteryMonitor& b) {
    scooterID = b.scooterID;
    chargeCycles = b.chargeCycles;
    batteryCapacity = b.batteryCapacity;
    originalCapacity = b.originalCapacity;
    isActive = b.isActive;
    tripCount = b.tripCount;
    tripDistances = new int[tripCount];
    for (int i = 0; i < tripCount; i++) tripDistances[i] = b.tripDistances[i];
}

// Assignment operator
BatteryMonitor& BatteryMonitor::operator=(const BatteryMonitor& b) {
    if (this != &b) {
        delete[] tripDistances;  // free old memory
        scooterID = b.scooterID;
        chargeCycles = b.chargeCycles;
        batteryCapacity = b.batteryCapacity;
        originalCapacity = b.originalCapacity;
        isActive = b.isActive;
        tripCount = b.tripCount;
        tripDistances = new int[tripCount];
        for (int i = 0; i < tripCount; i++) tripDistances[i] = b.tripDistances[i];
    }
    return *this;
}

// Destructor
BatteryMonitor::~BatteryMonitor() {
    delete[] tripDistances;
}

// Relational operators based on battery health %
bool BatteryMonitor::operator>(const BatteryMonitor& b) const {
    return (batteryCapacity / originalCapacity) > (b.batteryCapacity / b.originalCapacity);
}

bool BatteryMonitor::operator<(const BatteryMonitor& b) const {
    return (batteryCapacity / originalCapacity) < (b.batteryCapacity / b.originalCapacity);
}

// Compound assignment += (simulate charge cycles and degradation)
BatteryMonitor& BatteryMonitor::operator+=(int additionalCycles) {
    chargeCycles += additionalCycles;
    batteryCapacity -= (additionalCycles / 50.0f) * 0.05f;
    if (batteryCapacity < 0) batteryCapacity = 0;
    return *this;
}

// Subscript operator
int& BatteryMonitor::operator[](int index) {
    if (index >= 0 && index < tripCount) return tripDistances[index];
    else {
        std::cout << "Index out of range. Returning first trip." << std::endl;
        return tripDistances[0];
    }
}

// Unary ! operator: check if inactive
bool BatteryMonitor::operator!() const {
    return !isActive;
}

// Stream insertion
std::ostream& operator<<(std::ostream& out, const BatteryMonitor& b) {
    out << "Scooter ID: " << b.scooterID << "\n";
    out << "Charge Cycles: " << b.chargeCycles 
        << ", Battery Capacity: " << b.batteryCapacity 
        << "/" << b.originalCapacity 
        << " kWh (" << (b.batteryCapacity / b.originalCapacity * 100) << "% health)\n";
    out << "Status: " << (b.isActive ? "Active" : "Inactive") << "\n";
    out << "Trips: ";
    for (int i = 0; i < b.tripCount; i++) {
        out << b.tripDistances[i] << " ";
    }
    out << "\n";
    return out;
}

