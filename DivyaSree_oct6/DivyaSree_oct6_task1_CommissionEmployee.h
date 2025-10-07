// CommissionEmployee.h


#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include <string>
#include <iostream>
#include <iomanip>

class CommissionEmployee {
private:
    // Private data members
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    double grossSales;
    double commissionRate;

public:
    // Constructor
    CommissionEmployee(const std::string& first, const std::string& last,
                       const std::string& ssn, double sales, double rate);

    // Destructor
    ~CommissionEmployee();

    // Set and get functions for all data members
    void setFirstName(const std::string& first);
    std::string getFirstName() const;

    void setLastName(const std::string& last);
    std::string getLastName() const;

    void setSocialSecurityNumber(const std::string& ssn);
    std::string getSocialSecurityNumber() const;

    void setGrossSales(double sales);
    double getGrossSales() const;

    void setCommissionRate(double rate);
    double getCommissionRate() const;

    // Calculate earnings
    double earnings() const;

    // Print employee details
    void print() const;
};

#endif
