#include <iostream>  

int main() {
    const int SIZE = 20;   // Maximum number of inputs
    int unique[SIZE];      // Array to store unique numbers
    int count = 0;         // Number of unique numbers stored

    // Loop to read SIZE numbers
    for (int i = 0; i < SIZE; i++) {
        int num;
        std::cout << "Enter number " << (i + 1) << " (10–100): ";
        std::cin >> num;

        // Validate the input range
        if (num < 10 || num > 100) {
            std::cout << "Invalid input! Must be between 10 and 100.\n";
            i--; 
            continue;
        }

        // Check if the number is already stored or not
        bool duplicate = false;
        for (int j = 0; j < count; j++) {
            if (unique[j] == num) {
                duplicate = true;
                break;
            }
        }

        // Store only unique
        if (!duplicate) {
            unique[count] = num;
            count++;
        }
    }

    // Display the unique values
    std::cout << "\nUnique numbers entered:\n";
    for (int i = 0; i < count; i++) {
        std::cout << unique[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
