// HeartRates.h
// Definition of the HeartRates class to calculate age, maximum heart rate,
// and target heart rate range based on user input.

#ifndef HEARTRATES_H
#define HEARTRATES_H

#include <string> // for std::string

class HeartRates
{
public:
    // Constructor: initializes all data members with personal information
    HeartRates(const std::string& first, const std::string& last,
               int birthMonth, int birthDay, int birthYear);

    // Set and get functions for first name
    void setFirstName(const std::string& first); // set first name
    std::string getFirstName() const;            // get first name

    // Set and get functions for last name
    void setLastName(const std::string& last); // set last name
    std::string getLastName() const;           // get last name

    // Set and get functions for birth month
    void setMonth(int birthMonth); // set birth month
    int getMonth() const;          // get birth month

    // Set and get functions for birth day
    void setDay(int birthDay); // set birth day
    int getDay() const;        // get birth day

    // Set and get functions for birth year
    void setYear(int birthYear); // set birth year
    int getYear() const;         // get birth year

    // Calculate and return the person's age in years
    int getAge() const;

    // Calculate and return maximum heart rate (220 - age)
    int getMaximumHeartRate() const;

    // Calculate and return target heart rate range (50% - 85% of max)
    void getTargetHeartRate(double& lower, double& upper) const;

private:
    std::string firstName; // Person's first name
    std::string lastName;  // Person's last name
    int month;             // Birth month (1-12)
    int day;               // Birth day (1-31)
    int year;              // Birth year (e.g., 1990)
};

#endif
