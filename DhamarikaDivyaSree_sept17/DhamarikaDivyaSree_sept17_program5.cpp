#include <iostream>
#include <string>

class ParcelAnalyzer {
public:
    // Accept weight in grams
    std::string classifyWeight(int grams) {
        if (grams < 500)
            return "Light";
        else if (grams <= 2000)
            return "Medium";
        else
            return "Heavy";
    }

    // Accept weight in kilograms
    std::string classifyWeight(float kilograms) {
        if (kilograms < 0.5f)
            return "Light";
        else if (kilograms <= 2.0f)
            return "Medium";
        else
            return "Heavy";
    }

    // Accept weight in pounds
    std::string classifyWeight(double pounds) {
        if (pounds < 1.1)
            return "Light";
        else if (pounds <= 4.4)
            return "Medium";
        else
            return "Heavy";
    }
};

// Global function to print classification with input
template <typename T>
void printClassification(const T& value, const std::string& unit, const std::string& label) {
    std::cout << value << " " << unit << " " << label << std::endl;
}

int main() {
    ParcelAnalyzer analyzer;

    // Test grams
    printClassification(450, "grams", analyzer.classifyWeight(450));
    printClassification(1500, "grams", analyzer.classifyWeight(1500));
    printClassification(2500, "grams", analyzer.classifyWeight(2500));

    // Test kilograms
    printClassification(0.3f, "kg", analyzer.classifyWeight(0.3f));
    printClassification(1.5f, "kg", analyzer.classifyWeight(1.5f));
    printClassification(3.0f, "kg", analyzer.classifyWeight(3.0f));

    // Test pounds
    printClassification(0.9, "lb", analyzer.classifyWeight(0.9));
    printClassification(2.5, "lb", analyzer.classifyWeight(2.5));
    printClassification(5.0, "lb", analyzer.classifyWeight(5.0));

    return 0;
}
