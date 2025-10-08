#ifndef DIAGNOSTICREPORT_H
#define DIAGNOSTICREPORT_H

#include "DivyaSree_oct8_task2_SensorReading.h"
#include <map>
#include <algorithm>

class DiagnosticReport {
private:
    SensorReading** readings;
    int size;
    int capacity;

public:
    DiagnosticReport(int cap = 10);
    ~DiagnosticReport();

    void addReading(const std::string& name, double value, SeverityLevel sev);

    SensorReading* filterBySeverity(SeverityLevel level, int& count) const;
    void sortBySeverityDescending();
    std::map<std::string, int> severityDistribution() const;
    SensorReading* findReadingByName(const std::string& name) const;
    void displayAll() const;
};

inline DiagnosticReport::DiagnosticReport(int cap) : size(0), capacity(cap) {
    readings = new SensorReading*[capacity];
}

inline DiagnosticReport::~DiagnosticReport() {
    for(int i = 0; i < size; i++) delete readings[i];
    delete[] readings;
}

inline void DiagnosticReport::addReading(const std::string& name, double value, SeverityLevel sev) {
    if(size < capacity)
        readings[size++] = new SensorReading(name, value, sev);
}

inline SensorReading* DiagnosticReport::filterBySeverity(SeverityLevel level, int& count) const {
    count = 0;
    for(int i = 0; i < size; i++)
        if(readings[i]->severity == level) count++;

    if(count == 0) return nullptr;

    SensorReading* result = new SensorReading[count];
    int idx = 0;
    for(int i = 0; i < size; i++)
        if(readings[i]->severity == level)
            result[idx++] = *readings[i];
    return result;
}

inline void DiagnosticReport::sortBySeverityDescending() {
    auto severityRank = [](SeverityLevel s) {
        switch(s) {
            case SeverityLevel::Critical: return 4;
            case SeverityLevel::High: return 3;
            case SeverityLevel::Medium: return 2;
            case SeverityLevel::Low: return 1;
        }
        return 0;
    };
    std::sort(readings, readings + size, [&](SensorReading* a, SensorReading* b){
        return severityRank(a->severity) > severityRank(b->severity);
    });
}

inline std::map<std::string, int> DiagnosticReport::severityDistribution() const {
    std::map<std::string,int> dist;
    for(int i = 0; i < size; i++)
        dist[severityToString(readings[i]->severity)]++;
    return dist;
}

inline SensorReading* DiagnosticReport::findReadingByName(const std::string& name) const {
    for(int i = 0; i < size; i++)
        if(readings[i]->name == name) return readings[i];
    return nullptr;
}

inline void DiagnosticReport::displayAll() const {
    for(int i = 0; i < size; i++)
        readings[i]->display();
}

#endif // DIAGNOSTICREPORT_H
