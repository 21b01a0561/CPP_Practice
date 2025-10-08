#include "DivyaSree_oct8_task2_DiagnosticReport.h"
#include <iostream>

int main() {
    DiagnosticReport report;

    report.addReading("BrakeFluidLevel", 2.5, SeverityLevel::Critical);
    report.addReading("EngineTemp", 90.0, SeverityLevel::High);
    report.addReading("OilPressure", 30.0, SeverityLevel::Medium);
    report.addReading("BatteryVoltage", 12.1, SeverityLevel::Low);
    report.addReading("CoolantLevel", 70.0, SeverityLevel::High);

    std::cout << "\n--- Severity Distribution ---\n";
    auto dist = report.severityDistribution();
    for(const auto& p : dist)
        std::cout << p.first << ": " << p.second << std::endl;

    std::cout << "\n--- Sorted by Severity Descending ---\n";
    report.sortBySeverityDescending();
    report.displayAll();

    std::cout << "\n--- Filter: Critical Readings ---\n";
    int count;
    SensorReading* criticalReadings = report.filterBySeverity(SeverityLevel::Critical, count);
    if(criticalReadings) {
        for(int i = 0; i < count; i++)
            criticalReadings[i].display();
        delete[] criticalReadings;
    }

    std::cout << "\n--- Search for BrakeFluidLevel ---\n";
    SensorReading* sensor = report.findReadingByName("BrakeFluidLevel");
    if(sensor) sensor->display();
    else std::cout << "Sensor not found.\n";

    return 0;
}
