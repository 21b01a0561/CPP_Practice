#include "DivyaSree_oct8_task1_DiagnosticReport.h"
#include <iostream>

void DiagnosticReport::addReading(const SensorReading& reading) {
    readings.push_back(reading);
}

void DiagnosticReport::displayAll() const {
    std::cout << "\n=== Diagnostic Report ===" << std::endl;
    for (const SensorReading& reading : readings) {
        reading.display();
    }
}

int DiagnosticReport::countBySeverity(SeverityLevel minSeverity) const {
    int count = 0;
    for (const SensorReading& reading : readings) {
        if (static_cast<int>(reading.getSeverity()) >= static_cast<int>(minSeverity)) {
            ++count;
        }
    }
    return count;
}
