#include <iostream>
#include <iomanip>

class VehicleStatus {
public:
    int num_wheels;
    float* wheel_speed;   // dynamic array
    int num_temps;
    float* engine_temp;   // dynamic array

public:
    // Constructor
    VehicleStatus(int n_wheels, const float* speeds, int n_temps, const float* temps) {
        num_wheels = n_wheels;
        num_temps = n_temps;

        // Allocate dynamic arrays
        wheel_speed = new float[num_wheels];
        engine_temp = new float[num_temps];

        // Initialize arrays
        for (int i = 0; i < num_wheels; i++)
            wheel_speed[i] = speeds[i];

        for (int i = 0; i < num_temps; i++)
            engine_temp[i] = temps[i];
    }

    // Destructor
    ~VehicleStatus() {
        delete[] wheel_speed;
        delete[] engine_temp;
    }

    // Average wheel speed
    float averageWheelSpeed() const {
        float sum = 0.0f;
        for (int i = 0; i < num_wheels; i++)
            sum += wheel_speed[i];
        return sum / num_wheels;
    }

    // Maximum engine temperature
    float maxEngineTemp() const {
        float max_val = engine_temp[0];
        for (int i = 1; i < num_temps; i++) {
            if (engine_temp[i] > max_val)
                max_val = engine_temp[i];
        }
        return max_val;
    }

    // Get maximum wheel speed
    float maxWheelSpeed() const {
        float max_val = wheel_speed[0];
        for (int i = 1; i < num_wheels; i++)
            if (wheel_speed[i] > max_val)
                max_val = wheel_speed[i];
        return max_val;
    }

    // Compare max wheel speed (member function)
    int compareWheelSpeed(const VehicleStatus& other) const {
        float max_this = maxWheelSpeed();
        float max_other = other.maxWheelSpeed();

        if (max_this > max_other) return 1;   // this > other
        else if (max_this < max_other) return -1; // this < other
        else return 0;   // equal
    }

   };

// Global function to print status
void printVehicleStatus(const VehicleStatus& vs) {
    std::cout << "Wheel Speeds: ";
    for (int i = 0; i < vs.num_wheels; i++)
        std::cout << std::fixed << std::setprecision(1) << vs.wheel_speed[i] << " ";
    std::cout << std::endl;

    std::cout << "Engine Temperatures: ";
    for (int i = 0; i < vs.num_temps; i++)
        std::cout << std::fixed << std::setprecision(1) << vs.engine_temp[i] << " ";
    std::cout << std::endl;

    std::cout << "Average Wheel Speed: " << vs.averageWheelSpeed() << std::endl;
    std::cout << "Max Engine Temp: " << vs.maxEngineTemp() << std::endl;

}

// Global comparison
int compareWheelSpeedGlobal(const VehicleStatus& vs1, const VehicleStatus& vs2) {
    return vs1.compareWheelSpeed(vs2);
}

// Main function
int main() {
    // Sample Data
    int num_wheels1 = 4;
    float wheel_speed1[] = {55.5f, 56.6f, 57.2f, 55.9f};
    int num_temps1 = 2;
    float engine_temp1[] = {90.5f, 88.9f};

    int num_wheels2 = 4;
    float wheel_speed2[] = {50.0f, 51.2f, 49.8f, 50.4f};
    int num_temps2 = 2;
    float engine_temp2[] = {92.0f, 89.5f};

    VehicleStatus v1(num_wheels1, wheel_speed1, num_temps1, engine_temp1);
    VehicleStatus v2(num_wheels2, wheel_speed2, num_temps2, engine_temp2);

    std::cout << "Vehicle 1 Status:" << std::endl;
    printVehicleStatus(v1);

    std::cout << "Vehicle 2 Status:" << std::endl;
    printVehicleStatus(v2);

    // Compare using member function
    int result1 = v1.compareWheelSpeed(v2);
    if (result1 == 1)
        std::cout << "Vehicle 1 has higher max wheel speed (Member Function)." << std::endl;
    else if (result1 == -1)
        std::cout << "Vehicle 2 has higher max wheel speed (Member Function)." << std::endl;
    else
        std::cout << "Both vehicles have equal max wheel speed (Member Function)." << std::endl;

    // Compare using global function
    int result2 = compareWheelSpeedGlobal(v1, v2);
    if (result2 == 1)
        std::cout << "Vehicle 1 has higher max wheel speed (Global Function)." << std::endl;
    else if (result2 == -1)
        std::cout << "Vehicle 2 has higher max wheel speed (Global Function)." << std::endl;
    else
        std::cout << "Both vehicles have equal max wheel speed (Global Function)." << std::endl;

    return 0;
}
