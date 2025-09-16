#include <iostream>


class ObjectDistance {
private:
    float radar_distance;
    float camera_distance;

public:
    // Constructor
    ObjectDistance(float radar, float camera)
        : radar_distance(radar), camera_distance(camera) {}

    // Adjust distances by value 
    void adjustDistancesByValue(ObjectDistance obj) {
        obj.radar_distance += 5.0f;
        obj.camera_distance += 5.0f;
        std::cout << "Inside adjustDistancesByValue: ";
        std::cout << "Radar=" << obj.radar_distance 
                  << ", Camera=" << obj.camera_distance << std::endl;
        // Changes not reflected in original object
    }

    // Adjust distances by reference
    void adjustDistancesByReference(ObjectDistance& obj) {
        obj.radar_distance += 5.0f;
        obj.camera_distance += 5.0f;
        // Changes reflected in original object
    }

    // Getter functions
    float getRadarDistance() const { return radar_distance; }
    float getCameraDistance() const { return camera_distance; }
};

// ---------------- Global Functions ----------------
void printObjectDistance(const ObjectDistance& obj) {
    std::cout << "Radar Distance: " << obj.getRadarDistance()
              << ", Camera Distance: " << obj.getCameraDistance() << std::endl;
}

ObjectDistance* createObjectDistanceOnHeap(float radar, float camera) {
    return new ObjectDistance(radar, camera);
}

// ---------------- Main Function ----------------
int main() {
    // Create object on heap
    ObjectDistance* objPtr = createObjectDistanceOnHeap(35.5f, 34.8f);

    std::cout << "Original distances:" << std::endl;
    printObjectDistance(*objPtr);

    // Adjust by value
    objPtr->adjustDistancesByValue(*objPtr);
    std::cout << "After adjustDistancesByValue (original object unchanged):" << std::endl;
    printObjectDistance(*objPtr);

    // Adjust by reference
    objPtr->adjustDistancesByReference(*objPtr);
    std::cout << "After adjustDistancesByReference (original object updated):" << std::endl;
    printObjectDistance(*objPtr);

    // Delete heap object
    delete objPtr;
    objPtr = nullptr;

    return 0;
}
