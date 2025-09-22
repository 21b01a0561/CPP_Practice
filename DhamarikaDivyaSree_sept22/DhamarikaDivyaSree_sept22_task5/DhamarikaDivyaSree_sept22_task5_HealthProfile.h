// HealthProfile.h
// Definition of HealthProfile class to store personal and health information

#ifndef HEALTHPROFILE_H
#define HEALTHPROFILE_H

#include <string>

class HealthProfile
{
public:
    // Constructor: initialize all attributes
    HealthProfile(const std::string& first, const std::string& last,
                  const std::string& gen, int birthMonth, int birthDay, int birthYear,
                  double heightInches, double weightPounds);

    // Set and get functions for first name
    void setFirstName(const std::string& first);
    std::string getFirstName() const;

    // Set and get functions for last name
    void setLastName(const std::string& last);
    std::string getLastName() const;

    // Set and get functions for gender
    void setGender(const std::string& gen);
    std::string getGender() const;

    // Set and get functions for birth month
    void setMonth(int birthMonth);
    int getMonth() const;

    // Set and get functions for birth day
    void setDay(int birthDay);
    int getDay() const;

    // Set and get functions for birth year
    void setYear(int birthYear);
    int getYear() const;

    // Set and get functions for height (in inches)
    void setHeight(double heightInches);
    double getHeight() const;

    // Set and get functions for weight (in pounds)
    void setWeight(double weightPounds);
    double getWeight() const;

    // Calculate and return age in years (prompts for current date)
    int getAge() const;

    // Calculate and return maximum heart rate
    int getMaximumHeartRate() const;

    // Calculate target heart rate range (50%-85% of max)
    void getTargetHeartRate(double& lower, double& upper) const;

    // Calculate and return BMI
    double getBMI() const;

private:
    std::string firstName; // first name
    std::string lastName;  // last name
    std::string gender;    // gender
    int month;             // birth month
    int day;               // birth day
    int year;              // birth year
    double height;         // height in inches
    double weight;         // weight in pounds
};

#endif
