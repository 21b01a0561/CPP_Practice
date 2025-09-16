#include <iostream>
#include <string>
#include <stdexcept>
#include <limits> 

// ---------------- FleetVehicle Class ----------------
class FleetVehicle {
private:
    int vehicleID;              
    float fuelLevel;          
    double distanceTravelled;  
    char status;               
    bool isAvailable;           
    std::string driverName;     
public:
    // Default Constructor -> Initializes default values
    FleetVehicle() {
        vehicleID = 0;
        fuelLevel = 50.0;
        distanceTravelled = 0.0;
        status = 'A';
        isAvailable = true;
        driverName = "Unassigned";
    }

    // Parameterized Constructor -> Used when user provides details
    FleetVehicle(int id, float fuel, double distance, char st, bool avail, std::string driver) {
        vehicleID = id;
        fuelLevel = fuel;
        distanceTravelled = distance;
        status = st;
        isAvailable = avail;
        driverName = driver;
    }

    // Destructor -> Automatically called when object is destroyed
    ~FleetVehicle() {
        std::cout << "Destructor called for vehicle ID: " << vehicleID << std::endl;
    }

    // ---------------- Getters (Accessors) ----------------
    int getVehicleID() const { return vehicleID; }
    float getFuelLevel() const { return fuelLevel; }
    double getDistanceTravelled() const { return distanceTravelled; }
    char getStatus() const { return status; }
    bool getAvailability() const { return isAvailable; }
    std::string getDriverName() const { return driverName; }

    // ---------------- Setters (Mutators) ----------------
    void setVehicleID(int id) { vehicleID = id; }
    void setFuelLevel(float fuel) { fuelLevel = fuel; }
    void setDistanceTravelled(double dist) { distanceTravelled = dist; }
    void setStatus(char st) { status = st; }
    void setAvailability(bool avail) { isAvailable = avail; }
    void setDriverName(std::string name) { driverName = name; }

    // Update vehicle status based on fuel and availability
    void updateStatus() {
        if (fuelLevel < 10.0 || !isAvailable)
            status = 'I';  // Inactive if low fuel or unavailable
        else
            status = 'A';  // Active otherwise
    }

    // Display all vehicle details
    void displayInfo() const {
        std::cout << "\n--- Vehicle Info ---\n";
        std::cout << "Vehicle ID        : " << vehicleID << std::endl;
        std::cout << "Fuel Level        : " << fuelLevel << " liters" << std::endl;
        std::cout << "Distance Travelled: " << distanceTravelled << " km" << std::endl;
        std::cout << "Status            : " << (status == 'A' ? "Active" : "Inactive") << std::endl;
        std::cout << "Available         : " << (isAvailable ? "Yes" : "No") << std::endl;
        std::cout << "Driver Name       : " << driverName << std::endl;
        std::cout << "---------------------\n";
    }
};

// ---------------- Global Functions ----------------

// Assigns driver to a vehicle
void assignDriver(FleetVehicle &vehicle, std::string name) {
    vehicle.setDriverName(name);
    std::cout << "Driver " << vehicle.getDriverName()
              << " assigned to Vehicle ID: " << vehicle.getVehicleID() << std::endl;
}

// Refuels a vehicle and checks for invalid fuel input
void refuelVehicle(FleetVehicle &vehicle, float fuelAmount) {
    if (fuelAmount <= 0) {
        throw std::invalid_argument("Fuel amount must be greater than 0!");
    }
    vehicle.setFuelLevel(vehicle.getFuelLevel() + fuelAmount);
    std::cout << "Vehicle ID " << vehicle.getVehicleID()
              << " refueled by " << fuelAmount << " liters. "
              << "New Fuel Level: " << vehicle.getFuelLevel() << " liters\n";
}


// This template is a generic function which makes input validation reusable for all data types.
template <typename T>
bool getValidatedInput(T &var) {
    std::cin >> var;
    if (std::cin.fail()) { // If wrong data type entered
        std::cin.clear();  // Clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
        std::cout << "Invalid input! Please try again.\n";
        return false;
    }
    return true;
}

// ---------------- Main Function ----------------
int main() {
     FleetVehicle fleet[3] = {
        FleetVehicle(101, 45.5, 120.0, 'A', true, "Raj"),
        FleetVehicle(102, 8.0, 300.0, 'A', true, "Priya"),
        FleetVehicle() // default
    }; 

    int choice, id;
    std::string driver;
    float fuel;

    do {
       
        std::cout << "\n==== Fleet Vehicle Monitoring Menu ====\n";
        std::cout << "1. Add Vehicle Details\n";
        std::cout << "2. Assign Driver\n";
        std::cout << "3. Refuel Vehicle\n";
        std::cout << "4. Update Status\n";
        std::cout << "5. Display Vehicle Info\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";

        if (!getValidatedInput(choice)) continue; 
        switch (choice) {
        case 1: { // Add Vehicle Details using Parameterized Constructor
            int index;
            std::cout << "Enter array index (0-2): ";
            if (!getValidatedInput(index)) break; // Validate index

            if (index >= 0 && index < 3) {
                int vid; float f; double dist; char st; bool avail; std::string drv;

                // Collect vehicle details with validation
                std::cout << "Enter VehicleID: ";
                if (!getValidatedInput(vid)) break;

                std::cout << "Enter FuelLevel: ";
                if (!getValidatedInput(f)) break;

                std::cout << "Enter Distance: ";
                if (!getValidatedInput(dist)) break;

                std::cout << "Enter Status (A/I): ";
                if (!getValidatedInput(st)) break;

                std::cout << "Enter Availability (1/0): ";
                if (!getValidatedInput(avail)) break;

                std::cout << "Enter Driver Name: ";
                std::cin >> drv;

                // Re-assign object with new values using parameterized constructor
                fleet[index] = FleetVehicle(vid, f, dist, st, avail, drv);
                std::cout << "Vehicle added at index " << index << " using parameterized constructor.\n";
            } else {
                std::cout << "Invalid index!\n";
            }
            break;
        }

        case 2: // Assign Driver
            std::cout << "Enter Vehicle ID: ";
            if (!getValidatedInput(id)) break;
            for (int i = 0; i < 3; i++) {
                if (fleet[i].getVehicleID() == id) {
                    std::cout << "Enter Driver Name: ";
                    std::cin >> driver;
                    assignDriver(fleet[i], driver);
                }
            }
            break;

        case 3: // Refuel Vehicle
            std::cout << "Enter Vehicle ID: ";
            if (!getValidatedInput(id)) break;
            for (int i = 0; i < 3; i++) {
                if (fleet[i].getVehicleID() == id) {
                    std::cout << "Enter Fuel Amount: ";
                    if (!getValidatedInput(fuel)) break;
                    try {
                        refuelVehicle(fleet[i], fuel);
                    } catch (const std::exception &e) {
                        std::cout << "Error: " << e.what() << std::endl;
                    }
                }
            }
            break;

        case 4: // Update Status for all vehicles
            for (int i = 0; i < 3; i++) {
                fleet[i].updateStatus();
                std::cout << "Status updated for Vehicle ID: " << fleet[i].getVehicleID() << std::endl;
            }
            break;

        case 5: // Display all vehicle information
            for (int i = 0; i < 3; i++) {
                fleet[i].displayInfo();
            }
            break;

        case 6: // Exit program
            std::cout << "Exiting system...\n";
            break;

        default: // Invalid menu choice
            std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6); // Keep running until Exit chosen

    return 0;
}
