#include <iostream>

// Enum for sensor type
enum SensorType { LIDAR, RADAR, CAMERA };

// Function to convert SensorType to string
const char* sensorTypeToString(SensorType t) {
    switch (t) {
        case LIDAR: return "LIDAR";
        case RADAR: return "RADAR";
        case CAMERA: return "CAMERA";
        default: return "UNKNOWN";
    }
}

class SensorArray {
private:
    int sensor_id;
    SensorType type;
    double* temperature_readings;
    int num_readings;
    static double global_max_temperature;

public:
    // Constructor
    SensorArray(int id = 0, SensorType t = LIDAR, double* readings = nullptr, int n = 0)
        : sensor_id(id), type(t), num_readings(n) {
        temperature_readings = new double[n];
        for (int i = 0; i < n; i++) {
            temperature_readings[i] = readings[i];
            if (readings[i] > global_max_temperature)
                global_max_temperature = readings[i];
        }
    }

    // Destructor
    ~SensorArray() {
        delete[] temperature_readings;
    }

    // Get max temperature for this sensor
    double getMaxTemperature() const {
        double max_temp = temperature_readings[0];
        for (int i = 1; i < num_readings; i++) {
            if (temperature_readings[i] > max_temp)
                max_temp = temperature_readings[i];
        }
        return max_temp;
    }

    // Print sensor info
    void printSensorInfo() const {
        std::cout << "Sensor ID " << sensor_id
                  << " Type " << sensorTypeToString(type)
                  << " Max Temperature " << getMaxTemperature() << std::endl;
    }

    // Static function
    static double getGlobalMaxTemperature() {
        return global_max_temperature;
    }
};

// Initialize static member
double SensorArray::global_max_temperature = -1e9;

// Global function to print a sensor
void printSensor(const SensorArray& s) {
    s.printSensorInfo();
}

// Global function to print all sensors
void printAllSensors(SensorArray* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i].printSensorInfo();
    }
}

int main() {
    int size = 3;

    double lidar_readings[] = {35.5, 36.1, 34.9};
    double radar_readings[] = {39.0, 38.7, 39.3};
    double camera_readings[] = {30.2, 31.0, 40.5};

    // Dynamically allocate array of sensors
    SensorArray* sensors = new SensorArray[size]{
        SensorArray(801, LIDAR, lidar_readings, 3),
        SensorArray(802, RADAR, radar_readings, 3),
        SensorArray(803, CAMERA, camera_readings, 3)
    };

    std::cout << "All Sensors:" << std::endl;
    printAllSensors(sensors, size);

    std::cout << "Global Maximum Temperature " << SensorArray::getGlobalMaxTemperature() << std::endl;

    delete[] sensors;
    return 0;
}
