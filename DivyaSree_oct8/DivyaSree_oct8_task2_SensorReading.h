#ifndef SENSORREADING_H
#define SENSORREADING_H

#include <string>
#include <iostream>

enum class SeverityLevel { Low, Medium, High, Critical };

inline std::string severityToString(SeverityLevel level) {
    switch(level) {
        case SeverityLevel::Low: return "Low";
        case SeverityLevel::Medium: return "Medium";
        case SeverityLevel::High: return "High";
        case SeverityLevel::Critical: return "Critical";
        default: return "Unknown";
    }
}

class SensorReading {
public:
    std::string name;
    double value;
    SeverityLevel severity;

    // Default constructor
    SensorReading() : name(""), value(0), severity(SeverityLevel::Low) {}

    // Parameterized constructor
    SensorReading(const std::string& n, double v, SeverityLevel s) 
        : name(n), value(v), severity(s) {}

    void display() const {
        std::cout << "Sensor: " << name 
                  << " | Value: " << value 
                  << " | Severity: " << severityToString(severity) 
                  << std::endl;
    }
};

#endif // SENSORREADING_H
