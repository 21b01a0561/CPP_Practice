// HealthProfile.cpp
// Implementation of HealthProfile class

#include "DhamarikaDivyaSree_sept22_task5_HealthProfile.h"
#include <iostream>

// Constructor: initialize all attributes
HealthProfile::HealthProfile(const std::string& first, const std::string& last,
                             const std::string& gen, int birthMonth, int birthDay, int birthYear,
                             double heightInches, double weightPounds)
    : firstName(first), lastName(last), gender(gen),
      month(birthMonth), day(birthDay), year(birthYear),
      height(heightInches), weight(weightPounds)
{
}

// Set/Get first name
void HealthProfile::setFirstName(const std::string& first) { firstName = first; }
std::string HealthProfile::getFirstName() const { return firstName; }

// Set/Get last name
void HealthProfile::setLastName(const std::string& last) { lastName = last; }
std::string HealthProfile::getLastName() const { return lastName; }

// Set/Get gender
void HealthProfile::setGender(const std::string& gen) { gender = gen; }
std::string HealthProfile::getGender() const { return gender; }

// Set/Get month
void HealthProfile::setMonth(int birthMonth) { month = birthMonth; }
int HealthProfile::getMonth() const { return month; }

// Set/Get day
void HealthProfile::setDay(int birthDay) { day = birthDay; }
int HealthProfile::getDay() const { return day; }

// Set/Get year
void HealthProfile::setYear(int birthYear) { year = birthYear; }
int HealthProfile::getYear() const { return year; }

// Set/Get height
void HealthProfile::setHeight(double heightInches) { height = heightInches; }
double HealthProfile::getHeight() const { return height; }

// Set/Get weight
void HealthProfile::setWeight(double weightPounds) { weight = weightPounds; }
double HealthProfile::getWeight() const { return weight; }

// Calculate age based on current date entered by user
int HealthProfile::getAge() const
{
    int currentMonth, currentDay, currentYear;
    std::cout << "Enter current month (1-12): ";
    std::cin >> currentMonth;
    std::cout << "Enter current day (1-31): ";
    std::cin >> currentDay;
    std::cout << "Enter current year: ";
    std::cin >> currentYear;

    int age = currentYear - year;
    if (currentMonth < month || (currentMonth == month && currentDay < day))
        age--;
    return age;
}

// Calculate maximum heart rate (220 - age)
int HealthProfile::getMaximumHeartRate() const
{
    int age = getAge();
    return 220 - age;
}

// Calculate target heart rate range (50%-85% of max)
void HealthProfile::getTargetHeartRate(double& lower, double& upper) const
{
    int maxHR = getMaximumHeartRate();
    lower = maxHR * 0.5;
    upper = maxHR * 0.85;
}

// Calculate BMI: (weight in pounds * 703) / (height in inches)^2
double HealthProfile::getBMI() const
{
    return (weight * 703) / (height * height);
}

