#ifndef SENSORREADING_H
#define SENSORREADING_H

#include <string>

// Enum Class for severity levels
enum class SeverityLevel {
    Low,
    Medium,
    High,
    Critical
};

// Convert severity level to string
std::string severityToString(SeverityLevel severity);

// Class representing a single sensor reading
class SensorReading {
private:
    std::string sensorName;
    double value;
    SeverityLevel severity;

public:
    SensorReading(const std::string& name, double val, SeverityLevel sev);

    void display() const;
    SeverityLevel getSeverity() const;
};

#endif
