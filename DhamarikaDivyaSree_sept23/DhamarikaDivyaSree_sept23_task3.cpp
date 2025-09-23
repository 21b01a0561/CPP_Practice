#include <iostream>

int main() {
    const int TOTAL_SEATS = 10;
    const int FIRST_CLASS_SEATS = 5;

    bool seats[TOTAL_SEATS] = {false}; // false = available, true = booked

    int choice;
    while (true) {
       std:: cout << "\nPlease type 1 for First Class" 
             << "\nPlease type 2 for Economy"
             << "\nYour choice: ";
       std:: cin >> choice;

        bool assigned = false;

        if (choice == 1) { // First Class
            for (int i = 0; i < FIRST_CLASS_SEATS; i++) {
                if (!seats[i]) {
                    seats[i] = true;
                   std:: cout << "Boarding Pass: Seat #" << (i + 1) 
                         << " - First Class" << std::endl;
                    assigned = true;
                    break;
                }
            }

            if (!assigned) { // if first class full
                std::cout << "First Class is full. Is Economy acceptable? (1 = Yes, 0 = No): ";
                int ans;
                std::cin >> ans;
                if (ans == 1) {
                    for (int i = FIRST_CLASS_SEATS; i < TOTAL_SEATS; i++) {
                        if (!seats[i]) {
                            seats[i] = true;
                            std::cout << "Boarding Pass: Seat #" << (i + 1) 
                                 << " - Economy" << std::endl;
                            assigned = true;
                            break;
                        }
                    }
                }
                if (!assigned) {
                    std::cout << "Next flight leaves in 3 hours.\n";
                }
            }
        } 
        else if (choice == 2) { // Economy
            for (int i = FIRST_CLASS_SEATS; i < TOTAL_SEATS; i++) {
                if (!seats[i]) {
                    seats[i] = true;
                    std::cout << "Boarding Pass: Seat #" << (i + 1) 
                         << " - Economy" << std::endl;
                    assigned = true;
                    break;
                }
            }

            if (!assigned) { // If economy is full
                std::cout << "Economy is full. Is First Class acceptable? (1 = Yes, 0 = No): ";
                int ans;
                std::cin >> ans;
                if (ans == 1) {
                    for (int i = 0; i < FIRST_CLASS_SEATS; i++) {
                        if (!seats[i]) {
                            seats[i] = true;
                           std:: cout << "Boarding Pass: Seat #" << (i + 1) 
                                 << " - First Class" << std::endl;
                            assigned = true;
                            break;
                        }
                    }
                }
                if (!assigned) {
                    std::cout << "Next flight leaves in 3 hours.\n";
                }
            }
        } 
        else {
            std::cout << "Invalid choice. Try again.\n";
        }

        // If plane is full → exit program
        bool allFull = true;
        for (int i = 0; i < TOTAL_SEATS; i++) {
            if (!seats[i]) {
                allFull = false;
                break;
            }
        }
        if (allFull) {
            std::cout << "\nAll seats booked. Next flight leaves in 3 hours.\n";
            break;
        }
    }

    return 0;
}
