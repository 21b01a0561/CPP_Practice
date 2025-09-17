#include <iostream>
#include <cstdint>// used to take uint32_t from this package

// ---------- Pedestrian Class ----------
class Pedestrian {
private:
//uint32_t is used because it exactly have 32 bits where as other types will vary from compiler to compiler
    uint32_t pedestrian_id;
    float distance_from_vehicle;

public:
    // Constructor
    Pedestrian(uint32_t id = 0, float distance = 0.0f) {
        pedestrian_id = id;
        distance_from_vehicle = distance;
    }

    // Update distance
    void updateDistance(float newDistance) {
        distance_from_vehicle = newDistance;
    }

    // Get distance
    float getDistance() const {
        return distance_from_vehicle;
    }

    // Get ID
    uint32_t getID() const {
        return pedestrian_id;
    }
};

// ---------- Global Functions ----------

// Print pedestrian details
void printPedestrianInfo(const Pedestrian& ped) {
    std::cout << "Pedestrian ID: " << ped.getID()
              << ", Distance from vehicle: " << ped.getDistance() << " meters"
              << std::endl;
}

// Check if all distances are equal
bool allDistancesEqual(Pedestrian* array, uint32_t size) {
    if (size == 0) return true;
    float first = array[0].getDistance();
    for (uint32_t i = 1; i < size; i++) {
        if (array[i].getDistance() != first) {
            return false;
        }
    }
    return true;
}

// Print closest pedestrian(s)
void printClosestPedestrians(Pedestrian* array, uint32_t size) {
    if (size == 0 || array == nullptr) {
        std::cout << "No pedestrian detected." << std::endl;
        return;
    }

    if (allDistancesEqual(array, size)) {
        std::cout << "\nAll pedestrians are at the same distance from the vehicle." << std::endl;
        return;
    }

    // Find minimum distance
    float minDist = array[0].getDistance();
    for (uint32_t i = 1; i < size; i++) {
        if (array[i].getDistance() < minDist) {
            minDist = array[i].getDistance();
        }
    }

    // Print all pedestrians with minimum distance
    std::cout << "\nClosest pedestrian(s) detected:" << std::endl;
    for (uint32_t i = 0; i < size; i++) {
        if (array[i].getDistance() == minDist) {
            printPedestrianInfo(array[i]);
        }
    }
}

// ---------- Main Function ----------
int main() {
    uint32_t size = 3;

    // Dynamically allocate array of pedestrians
    Pedestrian* pedestrians = new Pedestrian[size]{
        Pedestrian(101, 10.7f),
        Pedestrian(102, 8.7f),
        Pedestrian(103, 12.7f)
    };

    // Print all pedestrians
    std::cout << "All pedestrians:" << std::endl;
    for (uint32_t i = 0; i < size; i++) {
        printPedestrianInfo(pedestrians[i]);
    }

    // Print closest pedestrian(s)
    printClosestPedestrians(pedestrians, size);

    // Free memory
    delete[] pedestrians;

    return 0;
}
