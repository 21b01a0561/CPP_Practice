#include <iostream>

// size of array
const int SIZE = 20;

// Function to print the floor
void printFloor(const bool floor[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            std::cout << (floor[r][c] ? '*' : ' ');
        }
        std::cout << std::endl;
    }
}

int main() {
    bool floor[SIZE][SIZE] = {false}; // Initialize floor
    int row = 0, col = 0;             // Turtle position
    int dir = 0;                       // 0=right,1=down,2=left,3=up
    bool penDown = false;              // Pen starts up

    std::cout << "Welcome to Turtle Graphics!\n";
    std::cout << "Commands:\n"
              << "1 - Pen Up\n"
              << "2 - Pen Down\n"
              << "3 - Turn Right\n"
              << "4 - Turn Left\n"
              << "5,n - Move Forward n steps\n"
              << "6 - Print Floor\n"
              << "9 - End Program\n";

    while (true) {
        int command, param = 0;
        std::cout << "\nEnter command: ";
        std::cin >> command;

        if (command == 5) {
            std::cout << "Enter number of steps: ";
            std::cin >> param;
        }

        if (command == 1) {
            penDown = false;
        } else if (command == 2) {
            penDown = true;
        } else if (command == 3) {
            dir = (dir + 1) % 4; // turn right
        } else if (command == 4) {
            dir = (dir + 3) % 4; // turn left
        } else if (command == 5) {
            // Move forward param steps
            for (int step = 0; step < param; step++) {
                if (penDown) {
                    floor[row][col] = true;
                }

                // Move turtle within bounds
                if (dir == 0 && col + 1 < SIZE) col++;
                else if (dir == 1 && row + 1 < SIZE) row++;
                else if (dir == 2 && col - 1 >= 0) col--;
                else if (dir == 3 && row - 1 >= 0) row--;
            }
        } else if (command == 6) {
            std::cout << "\n--- FLOOR ---\n";
            printFloor(floor);
            std::cout << "-------------\n";
        } else if (command == 9) {
            std::cout << "Program ended.\n";
            break;
        } else {
            std::cout << "Invalid command. Try again.\n";
        }
    }

    return 0;
}
