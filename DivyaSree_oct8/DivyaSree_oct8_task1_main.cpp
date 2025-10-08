#include "DivyaSree_oct8_task1_DiagnosticReport.h"
#include <iostream>

int main() {
    DiagnosticReport report;

    // Sample Data (const objects)
    const SensorReading r1("EngineTemp", 105.0, SeverityLevel::High);
    const SensorReading r2("OilPressure", 20.0, SeverityLevel::Medium);
    const SensorReading r3("BrakeFluidLevel", 5.0, SeverityLevel::Critical);
    const SensorReading r4("BatteryVoltage", 12.5, SeverityLevel::Low);

    // Add readings to report
    report.addReading(r1);
    report.addReading(r2);
    report.addReading(r3);
    report.addReading(r4);

    // Display all readings
    report.displayAll();

    // Count and display how many readings have severity High or higher
    const int severeCount = report.countBySeverity(SeverityLevel::High);
    std::cout << "\nNumber of readings with severity HIGH or CRITICAL: "
              << severeCount << std::endl;

    return 0;
}
