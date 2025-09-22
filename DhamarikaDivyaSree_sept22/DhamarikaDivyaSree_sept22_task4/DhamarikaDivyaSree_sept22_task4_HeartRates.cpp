// HeartRates.cpp
// Implementation of HeartRates class member functions

#include "HeartRates.h"
#include <iostream> // for std::cin and std::cout

// Constructor: initialize all data members
HeartRates::HeartRates(const std::string& first, const std::string& last,
                       int birthMonth, int birthDay, int birthYear)
    : firstName(first), lastName(last), month(birthMonth), day(birthDay), year(birthYear)
{
    
}

// Set and get first name
void HeartRates::setFirstName(const std::string& first)
{
    firstName = first; // store the first name
}

std::string HeartRates::getFirstName() const
{
    return firstName; // return the first name
}

// Set and get last name
void HeartRates::setLastName(const std::string& last)
{
    lastName = last; // store the last name
}

std::string HeartRates::getLastName() const
{
    return lastName; // return the last name
}

// Set and get birth month
void HeartRates::setMonth(int birthMonth)
{
    month = birthMonth; // store the month
}

int HeartRates::getMonth() const
{
    return month; // return the month
}

// Set and get birth day
void HeartRates::setDay(int birthDay)
{
    day = birthDay; // store the day
}

int HeartRates::getDay() const
{
    return day; // return the day
}

// Set and get birth year
void HeartRates::setYear(int birthYear)
{
    year = birthYear; // store the year
}

int HeartRates::getYear() const
{
    return year; // return the year
}

// Calculate and return age
int HeartRates::getAge() const
{
    int currentMonth, currentDay, currentYear;

    // Prompt the user to enter the current date
    std::cout << "Enter current month (1-12): ";
    std::cin >> currentMonth;
    std::cout << "Enter current day (1-31): ";
    std::cin >> currentDay;
    std::cout << "Enter current year: ";
    std::cin >> currentYear;

    // Calculate age
    int age = currentYear - year;

    // Adjust if the birthday has not occurred yet this year
    if (currentMonth < month || (currentMonth == month && currentDay < day))
    {
        age--;
    }

    return age; // return calculated age
}

// Calculate and return maximum heart rate
int HeartRates::getMaximumHeartRate() const
{
    int age = getAge();      // get current age
    return 220 - age;        // max heart rate formula
}

// Calculate target heart rate range 
void HeartRates::getTargetHeartRate(double& lower, double& upper) const
{
    int maxRate = getMaximumHeartRate(); // get max heart rate
    lower = maxRate * 0.5;               // lower bound 50%
    upper = maxRate * 0.85;              // upper bound 85%
}
