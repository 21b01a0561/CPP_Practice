#include <iostream>


class RadarSignal {
private:
    int num_channels;
    float* signal_strength;

public:
    // Constructor
    RadarSignal(int num, float* signals) : num_channels(num) {
        signal_strength = new float[num_channels];
        for (int i = 0; i < num_channels; ++i)
            signal_strength[i] = signals[i];
    }

    // Copy constructor 
    RadarSignal(const RadarSignal& other) : num_channels(other.num_channels) {
        signal_strength = new float[num_channels];
        for (int i = 0; i < num_channels; ++i)
            signal_strength[i] = other.signal_strength[i];
    }

    // Destructor
    ~RadarSignal() { delete[] signal_strength; }
    

    // Function to calculate average signal
    float averageSignal() const {
        float sum = 0.0f;
        for (int i = 0; i < num_channels; ++i)
            sum += signal_strength[i];
        return sum / num_channels;
    }

    //Funtcion for Boost signal by value (copy)
    void boostSignalByValue(RadarSignal obj) {
        for (int i = 0; i < obj.num_channels; ++i)
            obj.signal_strength[i] += 5.0f;

        std::cout << "Inside boostSignalByValue (copy): ";
        for (int i = 0; i < obj.num_channels; ++i) {
            std::cout << obj.signal_strength[i];
            if (i != obj.num_channels - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

    // Function for Boost signal by reference
    void boostSignalByReference(RadarSignal& obj) {
        for (int i = 0; i < obj.num_channels; ++i)
            obj.signal_strength[i] += 5.0f;
    }

    

//Global Functions 
void printRadarSignal(const RadarSignal& radar) {
    for (int i = 0; i < radar.getNumChannels(); ++i) {
        std::cout << radar.getSignalAt(i);
        if (i != radar.getNumChannels() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

RadarSignal* createRadarSignalHeap(int num, float* signals) {
    return new RadarSignal(num, signals);
}

// Main Function
int main() {
    
    int num_channels = 4;
    float signals[4] = {55.5f, 48.2f, 60.1f, 52.6f};

    // Creating RadarSignal object on heap
    RadarSignal* radarPtr = createRadarSignalHeap(num_channels, signals);

    std::cout << "Original Radar Signals: ";
    printRadarSignal(*radarPtr);

    // printing the output for Boost by value (copy)
    radarPtr->boostSignalByValue(*radarPtr);
    std::cout << "After boostSignalByValue (original unchanged): ";
    printRadarSignal(*radarPtr);

    // printing the output for Boost by reference
    radarPtr->boostSignalByReference(*radarPtr);
    std::cout << "After boostSignalByReference (original updated): ";
    printRadarSignal(*radarPtr);

    //printing the output for Average signal
    std::cout << "Average Signal Strength: " << radarPtr->averageSignal() << std::endl;

    // Delete heap object
    delete radarPtr;
    radarPtr = nullptr;

    return 0;
}
