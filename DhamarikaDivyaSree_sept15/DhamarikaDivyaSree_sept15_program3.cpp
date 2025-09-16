#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

// ---------------- Enum Types ----------------
enum ComponentType {
    COMPONENT_TYPE_ENGINE,
    COMPONENT_TYPE_AVIONICS,
    COMPONENT_TYPE_LANDING_GEAR,
    COMPONENT_TYPE_FUEL_SYSTEM
};

enum ComponentStatus {
    COMPONENT_STATUS_OPERATIONAL,
    COMPONENT_STATUS_MAINTENANCE_REQUIRED,
    COMPONENT_STATUS_FAILED
};

// Helper functions for enums
std::string ComponentTypeToString(ComponentType type) {
    switch (type) {
        case COMPONENT_TYPE_ENGINE: return "Engine";
        case COMPONENT_TYPE_AVIONICS: return "Avionics";
        case COMPONENT_TYPE_LANDING_GEAR: return "Landing Gear";
        case COMPONENT_TYPE_FUEL_SYSTEM: return "Fuel System";
        default: return "Unknown";
    }
}

std::string ComponentStatusToString(ComponentStatus status) {
    switch (status) {
        case COMPONENT_STATUS_OPERATIONAL: return "Operational";
        case COMPONENT_STATUS_MAINTENANCE_REQUIRED: return "Maintenance Required";
        case COMPONENT_STATUS_FAILED: return "Failed";
        default: return "Unknown";
    }
}

// ---------------- Class ----------------
class AerospaceComponent {
private:
    int componentIdentifier;
    double componentEfficiency;
    std::string componentManufacturer;
    ComponentType componentType;
    ComponentStatus componentStatus;

public:
    // Default constructor
    AerospaceComponent()
        : componentIdentifier(0), componentEfficiency(100.0),
          componentManufacturer("Unknown"), componentType(COMPONENT_TYPE_ENGINE),
          componentStatus(COMPONENT_STATUS_OPERATIONAL) {}

    // Parameterized constructor
    AerospaceComponent(int id, double eff, const std::string &manu,
                       ComponentType type, ComponentStatus status)
        : componentIdentifier(id), componentEfficiency(eff),
          componentManufacturer(manu), componentType(type), componentStatus(status) {}

    // Destructor
    ~AerospaceComponent() {
        std::cout << "Component " << componentIdentifier << " destroyed.\n";
    }

    // Getters and setters
    int GetID() const { return componentIdentifier; }
    double GetEfficiency() const { return componentEfficiency; }
    std::string GetManufacturer() const { return componentManufacturer; }
    ComponentType GetType() const { return componentType; }
    ComponentStatus GetStatus() const { return componentStatus; }

    void SetManufacturer(const std::string &manu) { componentManufacturer = manu; }
    void SetEfficiency(double eff) { componentEfficiency = eff; }
    void SetStatus(ComponentStatus status) { componentStatus = status; }
    void SetID(int id) { componentIdentifier = id; }
    void SetType(ComponentType type) { componentType = type; }

    // Member functions
    void UpdateStatus() {
        if (componentEfficiency < 50.0)
            componentStatus = COMPONENT_STATUS_FAILED;
        else if (componentEfficiency < 80.0)
            componentStatus = COMPONENT_STATUS_MAINTENANCE_REQUIRED;
        else
            componentStatus = COMPONENT_STATUS_OPERATIONAL;
    }

    void SimulateUsage(int usageHours) {
        for (int i = 0; i < usageHours; i++) {
            componentEfficiency -= componentEfficiency * 0.005;
            if (componentEfficiency < 0) {
                componentEfficiency = 0;
                break;
            }
        }
        UpdateStatus();
    }

    void PerformMaintenanceCheck() const {
        switch (componentStatus) {
            case COMPONENT_STATUS_OPERATIONAL:
                std::cout << "Component " << componentIdentifier << " is operational.\n";
                break;
            case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
                std::cout << "Component " << componentIdentifier << " requires maintenance.\n";
                break;
            case COMPONENT_STATUS_FAILED:
                std::cout << "Component " << componentIdentifier << " has failed. Immediate action required.\n";
                break;
        }
    }

    void BoostEfficiency() {
        while (componentEfficiency < 100.0) {
            componentEfficiency += 1.0;
        }
        if (componentEfficiency > 100.0)
            componentEfficiency = 100.0;
        UpdateStatus();
    }

    void DisplayDetails() const {// to display particular component
        std::cout << "ID: " << componentIdentifier
                  << ", Efficiency: " << componentEfficiency
                  << "%, Manufacturer: " << componentManufacturer
                  << ", Type: " << ComponentTypeToString(componentType)
                  << ", Status: " << ComponentStatusToString(componentStatus) << "\n";
    }
};

// ---------------- Global Functions ----------------
void AssignManufacturer(AerospaceComponent &component, const std::string &manufacturerName) {
    component.SetManufacturer(manufacturerName);
    std::cout << "Component ID " << component.GetID()
              << " is now assigned to manufacturer " << manufacturerName << ".\n";
}

bool IsEfficient(const AerospaceComponent &component) {
    return component.GetEfficiency() > 85.0;
}

bool IsSameType(const AerospaceComponent &componentA, const AerospaceComponent &componentB) {
    return componentA.GetType() == componentB.GetType();
}

bool IsSameStatus(const AerospaceComponent &componentA, const AerospaceComponent &componentB) {
    return componentA.GetStatus() == componentB.GetStatus();
}

void PrintFormattedComponentList(const AerospaceComponent componentList[], const int listSize) {
    std::cout << "--------------------------------------------------------------\n";
    std::cout << std::left << std::setw(6) << "ID"
              << std::setw(15) << "Manufacturer"
              << std::setw(12) << "Efficiency"
              << std::setw(15) << "Type"
              << "Status\n";
    std::cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < listSize; i++) {
        std::cout << std::left << std::setw(6) << componentList[i].GetID()
                  << std::setw(15) << componentList[i].GetManufacturer()
                  << std::setw(12) << componentList[i].GetEfficiency()
                  << std::setw(15) << ComponentTypeToString(componentList[i].GetType())
                  << ComponentStatusToString(componentList[i].GetStatus()) << "\n";
    }
    std::cout << "--------------------------------------------------------------\n";
}

int SearchComponentByIdentifier(const AerospaceComponent componentList[], const int listSize, const int searchIdentifier) {
    for (int i = 0; i < listSize; i++) {
        if (componentList[i].GetID() == searchIdentifier) {
            return i;
        }
    }
    return -1;
}

// ---------------- Main ----------------
int main() {
    AerospaceComponent components[3] = {
        AerospaceComponent(101, 92.5, "GE Aviation", COMPONENT_TYPE_ENGINE, COMPONENT_STATUS_OPERATIONAL),
        AerospaceComponent(102, 45.0, "Honeywell", COMPONENT_TYPE_AVIONICS, COMPONENT_STATUS_FAILED),
        AerospaceComponent()
    };

    int choice;
    bool running = true;

    while (running) {
        std::cout << "\n---- Menu ----\n";
        std::cout << "1. Add component details\n";
        std::cout << "2. Assign manufacturer\n";
        std::cout << "3. Simulate usage\n";
        std::cout << "4. Boost efficiency\n";
        std::cout << "5. Check maintenance status\n";
        std::cout << "6. Compare components\n";
        std::cout << "7. Search by ID\n";
        std::cout << "8. Display all components\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {//to add new components to list
                int slot;
                std::cout << "Enter slot (0-2): ";
                std::cin >> slot;
                if (slot < 0 || slot > 2) {
                    std::cout << "Invalid slot.\n";
                    break;
                }

                int id, type, status;
                double eff;
                std::string manu;

                std::cout << "Enter Component ID: ";
                std::cin >> id;
                std::cout << "Enter efficiency (0-100): ";
                std::cin >> eff;
                if (eff < 0 || eff > 100) {
                    std::cout << "Invalid efficiency.\n";
                    break;
                }
                std::cin.ignore();
                std::cout << "Enter manufacturer: ";
                std::getline(std::cin, manu);
                if (manu.empty()) {
                    std::cout << "Manufacturer cannot be empty.\n";
                    break;
                }
                std::cout << "Enter type (0=Engine,1=Avionics,2=Landing Gear,3=Fuel System): ";
                std::cin >> type;
                if (type < 0 || type > 3) {
                    std::cout << "Invalid type.\n";
                    break;
                }
                std::cout << "Enter status (0=Operational,1=Maintenance Required,2=Failed): ";
                std::cin >> status;
                if (status < 0 || status > 2) {
                    std::cout << "Invalid status.\n";
                    break;
                }

                components[slot] = AerospaceComponent(id, eff, manu,
                                                     static_cast<ComponentType>(type),
                                                     static_cast<ComponentStatus>(status));
                std::cout << "Component added successfully at slot " << slot << ".\n";
                break;
            }
            case 2: {//assign manufacturer
                int id;
                std::string manu;
                std::cout << "Enter component ID: ";
                std::cin >> id;
                int idx = SearchComponentByIdentifier(components, 3, id);
                if (idx == -1) {
                    std::cout << "Component ID not found.\n";
                } else {
                    std::cout << "Enter new manufacturer: ";
                    std::cin.ignore();
                    std::getline(std::cin, manu);
                    AssignManufacturer(components[idx], manu);
                }
                break;
            }
            case 3: {//to mention how many hours component is used and display the remaining efficiency
                int id, hours;
                std::cout << "Enter component ID: ";
                std::cin >> id;
                int idx = SearchComponentByIdentifier(components, 3, id);
                if (idx == -1) {
                    std::cout << "Component ID not found.\n";
                } else {
                    std::cout << "Enter usage hours: ";
                    std::cin >> hours;
                    components[idx].SimulateUsage(hours);
                    std::cout << "Component ID " << id << " simulated for " << hours
                              << " hours. Efficiency now: " << components[idx].GetEfficiency() << "%\n";
                }
                break;
            }
            case 4: {// boosting efficiency to selected component to 100%
                int id;
                std::cout << "Enter component ID: ";
                std::cin >> id;
                int idx = SearchComponentByIdentifier(components, 3, id);
                if (idx == -1) {
                    std::cout << "Component ID not found.\n";
                } else {
                    components[idx].BoostEfficiency();
                    std::cout << "Component ID " << id << " efficiency boosted to "
                              << components[idx].GetEfficiency() << "%\n";
                }
                break;
            }
            case 5: {//checking maintence status
                int id;
                std::cout << "Enter component ID: ";
                std::cin >> id;
                int idx = SearchComponentByIdentifier(components, 3, id);
                if (idx == -1) {
                    std::cout << "Component ID not found.\n";
                } else {
                    components[idx].PerformMaintenanceCheck();
                }
                break;
            }
            case 6: {// to compare 2 components based on id's and compare only the type ans status 
                int id1, id2;
                std::cout << "Enter first component ID: ";
                std::cin >> id1;
                std::cout << "Enter second component ID: ";
                std::cin >> id2;
                int idx1 = SearchComponentByIdentifier(components, 3, id1);
                int idx2 = SearchComponentByIdentifier(components, 3, id2);
                if (idx1 == -1 || idx2 == -1) {// used to print if any of the id's is not available or not found
                    std::cout << "One or both component IDs not found.\n";
                } else {
                    std::cout << "Comparing Component " << id1 << " and Component " << id2 << ":\n";
                    std::cout << "- Same Type? " << (IsSameType(components[idx1], components[idx2]) ? "Yes" : "No") << "\n";
                    std::cout << "- Same Status? " << (IsSameStatus(components[idx1], components[idx2]) ? "Yes" : "No") << "\n";
                }
                break;
            }
            case 7: {// searching by component id
                int id;
                std::cout << "Enter component ID to search: ";
                std::cin >> id;
                int idx = SearchComponentByIdentifier(components, 3, id);
                if (idx == -1)
                    std::cout << "Component ID not found.\n";
                else {
                    
                    components[idx].DisplayDetails();
                }
                break;
            }
            case 8:// prints all components in a formated list
                PrintFormattedComponentList(components, 3);
                break;
            case 9:
                running = false;
                std::cout << "Exiting system.\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
