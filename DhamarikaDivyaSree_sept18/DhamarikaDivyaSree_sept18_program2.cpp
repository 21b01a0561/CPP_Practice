#include <iostream>

class EgoVehicleData {
public:
    int num_lanes;
    float* lane_positions;
    float* sensor_confidence;

public:
    // Constructor
    EgoVehicleData(int lanes, const float* positions, const float* confidence)
        : num_lanes(lanes) {
        lane_positions = new float[num_lanes];
        sensor_confidence = new float[num_lanes];
        for (int i = 0; i < num_lanes; i++) {
            lane_positions[i] = positions[i];
            sensor_confidence[i] = confidence[i];
        }
    }

    // Destructor
    ~EgoVehicleData() {
        delete[] lane_positions;
        delete[] sensor_confidence;
    }

    // Update sensor confidence
    void updateSensorConfidence(float factor) {
        for (int i = 0; i < num_lanes; i++)
            sensor_confidence[i] *= factor;
    }

    // Total confidence sum
    float getTotalConfidence() const {
        float sum = 0.0f;
        for (int i = 0; i < num_lanes; i++)
            sum += sensor_confidence[i];
        return sum;
    }

 
};

// Print EgoVehicleData
void printEgoVehicleData(const EgoVehicleData& data, int objectNumber) {
    std::cout << "Object " << objectNumber << ":\n";
    std::cout << "num_lanes = " << data.num_lanes << "\n";

    std::cout << "lane_positions = [";
    for (int i = 0; i < data.num_lanes; i++) {
        std::cout << data.lane_positions[i];
        if (i != data.num_lanes - 1) std::cout << ", ";
    }
    std::cout << "]\n";

    std::cout << "sensor_confidence = [";
    for (int i = 0; i < data.num_lanes; i++) {
        std::cout << data.sensor_confidence[i];
        if (i != data.num_lanes - 1) std::cout << ", ";
    }
    std::cout << "]\n\n";
}

// Print which object(s) have the highest confidence
void printHighestConfidenceVehicle(const int* objectNumbers, int count, int totalVehicles) {
    if (count == 0) {
        std::cout << "No vehicle found!\n";
    } else if (count == 1) {
        std::cout << "Object " << objectNumbers[0] << " has the highest confidence.\n";
    } else if (count == totalVehicles) {
        std::cout << "All vehicles have equal highest confidence.\n";
    } else {
        std::cout << "Tie detected! Objects ";
        for (int i = 0; i < count; i++) {
            std::cout << objectNumbers[i];
            if (i != count - 1) std::cout << " and ";
        }
        std::cout << " have equal highest confidence.\n";
    }
}

// Find highest confidence vehicle(s)
int findHighestConfidenceVehicle(EgoVehicleData* array, int size, int* highestIndices) {
    if (size <= 0) return 0;

    float maxConfidence = array[0].getTotalConfidence();
    highestIndices[0] = 1; // Object numbering starts from 1
    int count = 1;

    for (int i = 1; i < size; i++) {
        float conf = array[i].getTotalConfidence();
        if (conf > maxConfidence) {
            maxConfidence = conf;
            highestIndices[0] = i + 1;
            count = 1;
        } else if (conf == maxConfidence) {
            highestIndices[count++] = i + 1;
        }
    }
    return count;
}

int main() {
    // Example input data 
    float lane_positions1[3] = {3.2f, 3.0f, 3.4f};
    float confidence1[3] = {0.95f, 0.97f, 0.93f};

    float lane_positions2[3] = {2.9f, 2.8f, 3.1f};
    float confidence2[3] = {0.92f, 0.90f, 0.88f};

    float lane_positions3[3] = {3.4f, 3.5f, 3.6f};
    float confidence3[3] = {0.99f, 0.98f, 0.97f};

    // Dynamically allocate vehicles
    EgoVehicleData* vehicles = new EgoVehicleData[3]{
        EgoVehicleData(3, lane_positions1, confidence1),
        EgoVehicleData(3, lane_positions2, confidence2),
        EgoVehicleData(3, lane_positions3, confidence3)
    };

    // Optionally update confidence factors dynamically
    vehicles[0].updateSensorConfidence(1.05f);
    vehicles[1].updateSensorConfidence(1.02f);
    vehicles[2].updateSensorConfidence(1.10f);

    // Print all vehicle data
    std::cout << "=== All Vehicle Data ===\n";
    for (int i = 0; i < 3; i++) {
        printEgoVehicleData(vehicles[i], i + 1);
    }

    // Determine highest confidence vehicle(s)
    int highestIndices[3];
    int count = findHighestConfidenceVehicle(vehicles, 3, highestIndices);
    printHighestConfidenceVehicle(highestIndices, count, 3);

    delete[] vehicles;
    return 0;
}
