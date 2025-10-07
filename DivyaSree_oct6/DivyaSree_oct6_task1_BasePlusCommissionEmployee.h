// BasePlusCommissionEmployee.h


#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H
#define BASEPLUSCOMMISSIONEMPLOYEE_H

#include "DivyaSree_oct6_task1_CommissionEmployee.h"

class BasePlusCommissionEmployee {
private:
    CommissionEmployee commissionEmployee;  // Composition: object of CommissionEmployee
    double baseSalary;                      // Additional attribute for base salary

public:
    // Constructor
    BasePlusCommissionEmployee(const std::string& first, const std::string& last,const std::string& ssn, double sales,double rate, double salary);

    // Destructor
    ~BasePlusCommissionEmployee();

    // Setter and getter for base salary
    void setBaseSalary(double salary);
    double getBaseSalary() const;

    // Setters and getters 
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
