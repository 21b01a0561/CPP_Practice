#ifndef HYBRIDVEHICLE_H
#define HYBRIDVEHICLE_H

#include <string>
#include <iostream>

class HybridVehicle {
private:
    std::string modelName;
    float electricKm;
    float gasolineKm;
    float gasolineUsed;
    float trips[10];  // max 10 trips
    int tripCount;

public:
    // Constructor
    HybridVehicle(std::string name = "", float eKm = 0, float gKm = 0, float gUsed = 0);

    // Copy Constructor
    HybridVehicle(const HybridVehicle& v);

    // Assignment operator
    HybridVehicle& operator=(const HybridVehicle& v);

    // Binary + operator: combine two vehicles’ usage
    HybridVehicle operator+(const HybridVehicle& v);

    // Binary == operator: compare efficiency
    bool operator==(const HybridVehicle& v);

    // Unary prefix ++: increment trip count and add dummy trip
    HybridVehicle& operator++();

    // Subscript [] operator: access trip by index
    float& operator[](int index);

    // Function call operator (): return total distance
    float operator()();

    // Type conversion operator: float() - fuel efficiency (km/L)
    operator float();

    // Stream insertion << operator
    friend std::ostream& operator<<(std::ostream& out, const HybridVehicle& v);
};

#endif
