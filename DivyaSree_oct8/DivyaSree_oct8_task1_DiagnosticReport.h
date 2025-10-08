#ifndef DIAGNOSTICREPORT_H
#define DIAGNOSTICREPORT_H

#include "DivyaSree_oct8_task1_SensorReading.h"
#include <vector>

class DiagnosticReport {
private:
    std::vector<SensorReading> readings;

public:
    void addReading(const SensorReading& reading);
    void displayAll() const;
    int countBySeverity(SeverityLevel minSeverity) const;
};

#endif
