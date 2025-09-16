#include <iostream>

class LaneBoundary {
private:
    float curvature;
    int lane_id;

public:
    // Constructor
    LaneBoundary(float c, int id) : curvature(c), lane_id(id) {}

    // Const getter functions
    float getCurvature() const { return curvature; }
    int getLaneId() const { return lane_id; }

    // Function to compare curvature using this pointer
    bool compareCurvature(const LaneBoundary& other) const {
        return this->curvature > other.curvature;
    }

    // Function to display lane details
    void display() const {
        std::cout << "Lane ID: " << lane_id << ", Curvature: " << curvature << std::endl;
    }
};

// ---------------- Global Functions ----------------
bool isCurvatureGreater(const LaneBoundary& lane1, const LaneBoundary& lane2) {
    return lane1.getCurvature() > lane2.getCurvature();
}

void printLaneComparison(const LaneBoundary& lane1, const LaneBoundary& lane2) {
    if (lane1.getCurvature() > lane2.getCurvature()) {
        std::cout << "Lane " << lane1.getLaneId() << " has greater curvature." << std::endl;
    } else if (lane2.getCurvature() > lane1.getCurvature()) {
        std::cout << "Lane " << lane2.getLaneId() << " has greater curvature." << std::endl;
    } else {
        std::cout << "Both lanes have equal curvature." << std::endl;
    }
}

// ---------------- Main Function ----------------
int main() {
    // Create sample LaneBoundary objects
    LaneBoundary lane1(0.03f, 1);
    LaneBoundary lane2(0.023f, 2);

    // Display lanes
    lane1.display();
    lane2.display();

    // Compare using member function
    if (lane1.compareCurvature(lane2)) {
        std::cout << "Using member function: Lane " << lane1.getLaneId() << " has greater curvature." << std::endl;
    } else {
        std::cout << "Using member function: Lane " << lane2.getLaneId() << " has greater curvature." << std::endl;
    }

    // Compare using global function
    if (isCurvatureGreater(lane1, lane2)) {
        std::cout << "Using global function: Lane " << lane1.getLaneId() << " has greater curvature." << std::endl;
    } else {
        std::cout << "Using global function: Lane " << lane2.getLaneId() << " has greater curvature." << std::endl;
    }

    // Use global comparison print function
    printLaneComparison(lane1, lane2);

    return 0;
}
