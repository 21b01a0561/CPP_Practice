#include <iostream>
#include <cstdint>
#include <limits>

// ---------- TrackedVehicle Class ----------
class TrackedVehicle {
private:
    uint32_t vehicle_id;
    float speed;
    float distance;

    // Static members (shared across all objects)
    static float min_recorded_distance;
    static int vehicle_count;

public:
    // Constructor
    TrackedVehicle(uint32_t id = 0, float spd = 0.0f, float dist = 0.0f)
        : vehicle_id(id), speed(spd), distance(dist) {
        
        // Increment vehicle count whenever a new object is created
        vehicle_count++;

        // Update min_recorded_distance if this distance is smaller
        if (dist < min_recorded_distance) {
            min_recorded_distance = dist;
        }
    }

    // Display function
    void display() const {
        std::cout << "Vehicle ID: " << vehicle_id
                  << ", Speed: " << speed << " km/h"
                  << ", Distance: " << distance << " m"
                  << std::endl;
    }

    // Compare distances between vehicles
    const TrackedVehicle* compareDistance(const TrackedVehicle& other) const {
        if (distance < other.distance) {
            return this;
        } else if (distance > other.distance) {
            return &other;
        } else {
            return this; // return current object explicitly if equal
        }
    }

    // Getter for distance
    float getDistance() const { return distance; }

    // Getter for ID
    uint32_t getID() const { return vehicle_id; }

    // Static functions
    static float getMinRecordedDistance() {
        return min_recorded_distance;
    }

    static int getVehicleCount() {
        return vehicle_count;
    }
};

// Initialize static members
float TrackedVehicle::min_recorded_distance = std::numeric_limits<float>::max();
int TrackedVehicle::vehicle_count = 0;

// ---------- Global Functions ----------

// Print vehicle details
void printTrackedVehicle(const TrackedVehicle& vehicle) {
    vehicle.display();
}

// Find lead vehicle (smallest distance)
void findLeadVehicle(TrackedVehicle* arr, uint32_t size, const TrackedVehicle*& lead) {
    if (arr == nullptr || size == 0) {
        lead = nullptr;
        return;
    }

    lead = &arr[0];
    for (uint32_t i = 1; i < size; i++) {
        if (arr[i].getDistance() < lead->getDistance()) {
            lead = &arr[i];
        }
    }
}

// Print lead vehicle
void printLeadVehicle(const TrackedVehicle* lead) {
    if (lead != nullptr) {
        std::cout << "\nLead Vehicle Detected:" << std::endl;
        lead->display();
    } else {
        std::cout << "None found" << std::endl;
    }
}

// ---------- Main Function ----------
int main() {
    uint32_t size = 4;

    // Dynamically allocate array of vehicles
    TrackedVehicle* vehicles = new TrackedVehicle[size]{
        TrackedVehicle(501, 80.0f, 60.0f),
        TrackedVehicle(502, 78.0f, 45.0f),
        TrackedVehicle(503, 85.0f, 100.0f),
        TrackedVehicle(504, 76.0f, 40.0f)
    };

    // Find lead vehicle
    const TrackedVehicle* lead = nullptr;
    findLeadVehicle(vehicles, size, lead);

    // Print all vehicles
    std::cout << "All Tracked Vehicles:" << std::endl;
    for (uint32_t i = 0; i < size; i++) {
        printTrackedVehicle(vehicles[i]);
    }

    // Print lead vehicle
    printLeadVehicle(lead);

    // Print system-wide statistics
    std::cout << "\nMinimum recorded distance across all vehicles: "
              << TrackedVehicle::getMinRecordedDistance() << " m" << std::endl;

    std::cout << "Total number of tracked vehicles created: "
              << TrackedVehicle::getVehicleCount() << std::endl;

    // Free memory
    delete[] vehicles;

    return 0;
}
