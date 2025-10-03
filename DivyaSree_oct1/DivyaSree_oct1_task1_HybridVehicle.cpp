#include "HybridVehicle.h"

// Constructor
HybridVehicle::HybridVehicle(std::string name, float eKm, float gKm, float gUsed) {
    modelName = name;
    electricKm = eKm;
    gasolineKm = gKm;
    gasolineUsed = gUsed;
    tripCount = 0;
    for (int i = 0; i < 10; i++) trips[i] = 0;
}

// Copy Constructor
HybridVehicle::HybridVehicle(const HybridVehicle& v) {
    modelName = v.modelName;
    electricKm = v.electricKm;
    gasolineKm = v.gasolineKm;
    gasolineUsed = v.gasolineUsed;
    tripCount = v.tripCount;
    for (int i = 0; i < 10; i++) trips[i] = v.trips[i];
}

// Assignment operator
HybridVehicle& HybridVehicle::operator=(const HybridVehicle& v) {
    if (this != &v) {
        modelName = v.modelName;
        electricKm = v.electricKm;
        gasolineKm = v.gasolineKm;
        gasolineUsed = v.gasolineUsed;
        tripCount = v.tripCount;
        for (int i = 0; i < 10; i++) trips[i] = v.trips[i];
    }
    return *this;
}

// Binary + operator
HybridVehicle HybridVehicle::operator+(const HybridVehicle& v) {
    HybridVehicle result;
    result.modelName = modelName + "+" + v.modelName;
    result.electricKm = electricKm + v.electricKm;
    result.gasolineKm = gasolineKm + v.gasolineKm;
    result.gasolineUsed = gasolineUsed + v.gasolineUsed;
    result.tripCount = (tripCount + v.tripCount <= 10) ? tripCount + v.tripCount : 10;
    for (int i = 0; i < 10; i++) {
        if (i < tripCount) result.trips[i] = trips[i];
        else if (i - tripCount < v.tripCount) result.trips[i] = v.trips[i - tripCount];
        else result.trips[i] = 0;
    }
    return result;
}

// Binary == operator
bool HybridVehicle::operator==(const HybridVehicle& v) {
    float eff1 = (electricKm + gasolineKm) / (gasolineUsed == 0 ? 1 : gasolineUsed);
    float eff2 = (v.electricKm + v.gasolineKm) / (v.gasolineUsed == 0 ? 1 : v.gasolineUsed);
    return eff1 == eff2;
}

// Unary prefix ++ operator
HybridVehicle& HybridVehicle::operator++() {
    if (tripCount < 10) trips[tripCount++] = 0;
    return *this;
}

// Subscript operator
float& HybridVehicle::operator[](int index) {
    if (index >= 0 && index < 10) return trips[index];
    else {
        std::cout << "Index out of range. Returning trips[0]." << std::endl;
        return trips[0];
    }
}

// Function call operator
float HybridVehicle::operator()() {
    float total = electricKm + gasolineKm;
    for (int i = 0; i < tripCount; i++) total += trips[i];
    return total;
}

// Type conversion to float
HybridVehicle::operator float() {
    return gasolineUsed == 0 ? 0 : (electricKm + gasolineKm) / gasolineUsed;
}

// Stream insertion
std::ostream& operator<<(std::ostream& out, const HybridVehicle& v) {
    out << "Model: " << v.modelName << std::endl;
    out << "Electric Km: " << v.electricKm << ", Gasoline Km: " << v.gasolineKm 
        << ", Gasoline Used: " << v.gasolineUsed << std::endl;
    out << "Trips: ";
    for (int i = 0; i < 10; i++) {
        if (v.trips[i] != 0) out << v.trips[i] << " ";
    }
    out << std::endl;
    return out;
}
