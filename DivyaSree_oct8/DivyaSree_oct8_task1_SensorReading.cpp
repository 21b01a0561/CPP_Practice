#include "DivyaSree_oct8_task1_SensorReading.h"
#include <iostream>

// Convert severity level to string
std::string severityToString(SeverityLevel severity) {
    switch (severity) {
        case SeverityLevel::Low: return "Low";
        case SeverityLevel::Medium: return "Medium";
        case SeverityLevel::High: return "High";
        case SeverityLevel::Critical: return "Critical";
        default: return "Unknown";
    }
}

// Constructor
SensorReading::SensorReading(const std::string& name, double val, SeverityLevel sev)
    : sensorName(name), value(val), severity(sev) {}

// Display method
void SensorReading::display() const {
    std::cout << "Sensor: " << sensorName
              << " | Value: " << value
              << " | Severity: " << severityToString(severity)
              << std::endl;
}

// Getter for severity
SeverityLevel SensorReading::getSeverity() const {
    return severity;
}
