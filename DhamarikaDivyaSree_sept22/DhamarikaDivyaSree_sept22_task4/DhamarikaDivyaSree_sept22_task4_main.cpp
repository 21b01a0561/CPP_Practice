// main.cpp
// Program to test HeartRates class functionality

#include <iostream>
#include <iomanip> // for formatting floating-point numbers
#include "HeartRates.h"

int main()
{
    std::string first, last;
    int birthMonth, birthDay, birthYear;

    //taking user inputs
    std::cout << "Enter first name: ";
    std::cin >> first;

    std::cout << "Enter last name: ";
    std::cin >> last;

    std::cout << "Enter birth month (1-12): ";
    std::cin >> birthMonth;

    std::cout << "Enter birth day (1-31): ";
    std::cin >> birthDay;

    std::cout << "Enter birth year: ";
    std::cin >> birthYear;

    // Create HeartRates object with entered data
    HeartRates person(first, last, birthMonth, birthDay, birthYear);

    // Display personal information
    std::cout << "\nPerson Information:" << std::endl;
    std::cout << "Name: " << person.getFirstName() << " " << person.getLastName() << std::endl;
    std::cout << "Date of Birth: " << person.getMonth() << "/" 
              << person.getDay() << "/" << person.getYear() << std::endl;

    // Calculate and display age
    int age = person.getAge();
    std::cout << "Age: " << age << " years" << std::endl;

    // Calculate and display maximum heart rate
    int maxHR = 220 - age;
    std::cout << "Maximum Heart Rate: " << maxHR << " bpm" << std::endl;

    // Calculate and display target heart rate range
    double lower, upper;
    lower = maxHR * 0.5;
    upper = maxHR * 0.85;
    std::cout << "Target Heart Rate Range: " << lower << " - " << upper << " bpm" << std::endl;

    return 0;
}
