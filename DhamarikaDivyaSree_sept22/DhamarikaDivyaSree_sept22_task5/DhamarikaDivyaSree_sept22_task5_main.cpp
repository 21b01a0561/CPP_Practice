// main.cpp
// Test program for HealthProfile class

#include <iostream>
#include <iomanip>
#include "HealthProfile.h"

int main()
{
    std::string first, last, gender;
    int birthMonth, birthDay, birthYear;
    double height, weight;

    // Prompt user for personal info
    std::cout << "Enter first name: ";
    std::cin >> first;
    std::cout << "Enter last name: ";
    std::cin >> last;
    std::cout << "Enter gender: ";
    std::cin >> gender;
    std::cout << "Enter birth month (1-12): ";
    std::cin >> birthMonth;
    std::cout << "Enter birth day (1-31): ";
    std::cin >> birthDay;
    std::cout << "Enter birth year: ";
    std::cin >> birthYear;
    std::cout << "Enter height in inches: ";
    std::cin >> height;
    std::cout << "Enter weight in pounds: ";
    std::cin >> weight;

    // Create HealthProfile object
    HealthProfile person(first, last, gender, birthMonth, birthDay, birthYear, height, weight);

    std::cout << "\nHealth Profile Information:" << std::endl;
    std::cout << "Name: " << person.getFirstName() << " " << person.getLastName() << std::endl;
    std::cout << "Gender: " << person.getGender() << std::endl;
    std::cout << "Date of Birth: " << person.getMonth() << "/" << person.getDay()
              << "/" << person.getYear() << std::endl;
    std::cout << "Height: " << person.getHeight() << " inches" << std::endl;
    std::cout << "Weight: " << person.getWeight() << " pounds" << std::endl;

    // Calculate and display age
    int age = person.getAge();
    std::cout << "Age: " << age << " years" << std::endl;

    // Calculate and display BMI
    double bmi = person.getBMI();
    std::cout << "BMI: " << std::fixed << std::setprecision(2) << bmi << std::endl;

    // Calculate and display maximum heart rate
    int maxHR = 220 - age;
    std::cout << "Maximum Heart Rate: " << maxHR << " bpm" << std::endl;

    // Calculate and display target heart rate range
    double lower, upper;
    lower = maxHR * 0.5;
    upper = maxHR * 0.85;
    std::cout << "Target Heart Rate Range: " << lower << " - " << upper << " bpm" << std::endl;

    // Display BMI chart
    std::cout << "\nBMI VALUES CHART" << std::endl;
    std::cout << "Underweight: less than 18.5" << std::endl;
    std::cout << "Normal:      18.5 - 24.9" << std::endl;
    std::cout << "Overweight:  25 - 29.9" << std::endl;
    std::cout << "Obese:       30 or greater" << std::endl;

    return 0;
}
