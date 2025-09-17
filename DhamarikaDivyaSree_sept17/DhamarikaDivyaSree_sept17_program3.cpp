#include <iostream>
#include <cstdint>

class DetectedObject {
private:
    uint32_t object_id;
    float rel_speed;
    float distance;

public:
    // Constructor
    DetectedObject(uint32_t id = 0, float rs = 0.0f, float dist = 0.0f)
        : object_id(id), rel_speed(rs), distance(dist) {}

    // Print object details
    void display() const {
        std::cout << "Object ID= " << object_id
                  << " Relative Speed= " << rel_speed
                  << " Distance= " << distance << std::endl;
    }

    // Compare risk between two objects
    bool isHigherRisk(const DetectedObject& other) const {
        return (this->distance < other.distance) && (this->rel_speed > other.rel_speed);
    }

    // Update values by value (changes a copy, original not affected)
    void updateValuesByValue(DetectedObject obj) {
        obj.rel_speed += 2;
        obj.distance -= 5;
        std::cout << "Inside updateValuesByValue copy changed" << std::endl;
        obj.display();
    }

    // Update values by reference (changes original)
    void updateValuesByReference(DetectedObject& obj) {
        obj.rel_speed += 2;
        obj.distance -= 5;
    }

    // Getters
    uint32_t getID() const { return object_id; }
    float getRelSpeed() const { return rel_speed; }
    float getDistance() const { return distance; }
};

// Find the highest risk object
void findHighestRiskObject(DetectedObject* arr, uint32_t size, const DetectedObject*& riskObj) {
    if (arr == nullptr || size == 0) {
        riskObj = nullptr;
        return;
    }

    riskObj = &arr[0];
    for (uint32_t i = 1; i < size; i++) {
        if (arr[i].isHigherRisk(*riskObj)) {
            riskObj = &arr[i];
        }
    }
}

// Print details of one object
void printDetectedObject(const DetectedObject& obj) {
    obj.display();
}

// Print highest risk object
void printHighestRiskObject(const DetectedObject* obj) {
    if (obj != nullptr) {
        std::cout << "Highest Risk Object" << std::endl;
        obj->display();
    } else {
        std::cout << "No high risk object detected" << std::endl;
    }
}

// Call update by value
void updateObjectValuesByValueGlobal(DetectedObject obj) {
    obj.updateValuesByValue(obj);
}

// Call update by reference
void updateObjectValuesByReferenceGlobal(DetectedObject& obj) {
    obj.updateValuesByReference(obj);
}

int main() {
    uint32_t size = 3;

    // Dynamically create objects
    DetectedObject* objects = new DetectedObject[size]{
        DetectedObject(701, 15, 55),
        DetectedObject(702, 20, 35),
        DetectedObject(703, 10, 30)
    };

    std::cout << "All Detected Objects" << std::endl;
    for (uint32_t i = 0; i < size; i++) {
        printDetectedObject(objects[i]);
    }

    // Demonstrate update by value
    std::cout << "Before update by value:" << std::endl;
    objects[0].display();
    updateObjectValuesByValueGlobal(objects[0]);
    std::cout << "After update by value:" << std::endl;
    objects[0].display();

    // Demonstrate update by reference
    std::cout << "Before update by reference:" << std::endl;
    objects[1].display();
    updateObjectValuesByReferenceGlobal(objects[1]);
    std::cout << "After update by reference:" << std::endl;
    objects[1].display();

    // Find and print highest risk object
    const DetectedObject* riskObj = nullptr;
    findHighestRiskObject(objects, size, riskObj);
    printHighestRiskObject(riskObj);

    // Free memory
    delete[] objects;
    return 0;
}
