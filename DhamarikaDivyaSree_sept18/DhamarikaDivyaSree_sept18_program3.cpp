#include <iostream>
#include <string>

enum SatelliteStatus { OPERATIONAL, MAINTENANCE, DECOMMISSIONED };

class SatelliteData {
public:
    int satellite_id;
    int num_antennas;
    float* signal_strength;
    float orbital_altitude;
    SatelliteStatus status;
    static int active_satellites;

public:
    SatelliteData(int id, int antennas, const float* signals, float altitude, SatelliteStatus st)
        : satellite_id(id), num_antennas(antennas), orbital_altitude(altitude), status(st) {
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++)
            signal_strength[i] = signals[i];
        active_satellites++;
    }

    SatelliteData(const SatelliteData& other)
        : satellite_id(other.satellite_id),
          num_antennas(other.num_antennas),
          orbital_altitude(other.orbital_altitude),
          status(other.status) {
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++)
            signal_strength[i] = other.signal_strength[i];
        active_satellites++;
    }

    ~SatelliteData() {
        delete[] signal_strength;
        active_satellites--;
    }

    float getAverageSignalStrength() const {
        float sum = 0.0f;
        for (int i = 0; i < num_antennas; i++)
            sum += signal_strength[i];
        return sum / num_antennas;
    }

    void boostSignal(float factor) {
        for (int i = 0; i < num_antennas; i++)
            signal_strength[i] *= factor;
    }

    void boostSignal(float factor, float threshold) {
        for (int i = 0; i < num_antennas; i++)
            if (signal_strength[i] < threshold)
                signal_strength[i] *= factor;
    }

    void setStatus(SatelliteStatus new_status) { status = new_status; }

    const char* getStatusString() const {
        switch (status) {
            case OPERATIONAL: return "OPERATIONAL";
            case MAINTENANCE: return "MAINTENANCE";
            case DECOMMISSIONED: return "DECOMMISSIONED";
            default: return "UNKNOWN";
        }
    }

    int getID() const { return satellite_id; }
    float getAltitude() const { return orbital_altitude; }
    static int getActiveSatelliteCount() { return active_satellites; }

};

int SatelliteData::active_satellites = 0;

void printSatelliteData(const SatelliteData& sd) {
    std::cout << "Satellite ID: " << sd.satellite_id << "\n";
    std::cout << "Orbital Altitude: " << sd.orbital_altitude << "\n";
    std::cout << "Signal Strengths: [";
    for (int i = 0; i < sd.num_antennas; i++) {
        std::cout << sd.signal_strength[i];
        if (i != sd.num_antennas - 1) std::cout << ", ";
    }
    std::cout << "]\nStatus: " << sd.getStatusString() << "\n\n";
}

bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2) {
    return s1.orbital_altitude > s2.orbital_altitude;
}

void cloneSatellite(const SatelliteData& source, SatelliteData*& target) {
    target = new SatelliteData(source);
}

void printActiveSatelliteCount() {
    std::cout << "Active satellites: " << SatelliteData::getActiveSatelliteCount() << "\n";
}

void updateStatusIfWeak(SatelliteData& sd, float confidence_threshold) {
    if (sd.getAverageSignalStrength() < confidence_threshold)
        sd.setStatus(MAINTENANCE);
}

int main() {
    // Sample data
    float signals1[3] = {78.5f, 80.2f, 79.0f};
    float signals2[2] = {75.0f, 76.5f};

    SatelliteData* sat1 = new SatelliteData(101, 3, signals1, 550.0f, OPERATIONAL);
    SatelliteData* sat2 = new SatelliteData(102, 2, signals2, 600.0f, MAINTENANCE);

    // Boost signals
    sat1->boostSignal(1.05f);            // Boost all
    sat2->boostSignal(1.10f, 76.0f);     // Boost only below threshold

    // Compare altitudes
    if (compareAltitude(*sat1, *sat2))
        std::cout << "Satellite " << sat1->getID() << " has higher altitude than " << sat2->getID() << "\n\n";
    else
        std::cout << "Satellite " << sat2->getID() << " has higher altitude than " << sat1->getID() << "\n\n";

    // Clone satellite
    SatelliteData* sat_clone = nullptr;
    cloneSatellite(*sat1, sat_clone);

    // Print all satellite data
    printSatelliteData(*sat1);
    printSatelliteData(*sat2);
    printSatelliteData(*sat_clone);

    // Update status dynamically if weak
    updateStatusIfWeak(*sat1, 80.0f);
    updateStatusIfWeak(*sat2, 77.0f);

    std::cout << "After dynamic status check:\n";
    printSatelliteData(*sat1);
    printSatelliteData(*sat2);

    // Active satellite count before deletion
    printActiveSatelliteCount();

    // Delete satellites
    delete sat1;
    delete sat2;
    delete sat_clone;

    // Active satellite count after deletion
    printActiveSatelliteCount();

    return 0;
}
