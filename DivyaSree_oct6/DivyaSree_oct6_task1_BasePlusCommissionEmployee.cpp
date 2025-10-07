// BasePlusCommissionEmployee.cpp


#include "DivyaSree_oct6_task1_BasePlusCommissionEmployee.h"

// Constructor definition
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& first,
                                                       const std::string& last,
                                                       const std::string& ssn,
                                                       double sales, double rate,
                                                       double salary)
    : commissionEmployee(first, last, ssn, sales, rate) {
    setBaseSalary(salary);
    std::cout << "BasePlusCommissionEmployee constructor:\n";
    print();
}

// Destructor 
BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {
    std::cout << "BasePlusCommissionEmployee destructor:\n";
    print();
}

// Setters and getters
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = (salary < 0.0) ? 0.0 : salary;
}
double BasePlusCommissionEmployee::getBaseSalary() const { return baseSalary; }

// Delegate to CommissionEmployee’s methods
void BasePlusCommissionEmployee::setFirstName(const std::string& first) {
    commissionEmployee.setFirstName(first);
}
std::string BasePlusCommissionEmployee::getFirstName() const {
    return commissionEmployee.getFirstName();
}

void BasePlusCommissionEmployee::setLastName(const std::string& last) {
    commissionEmployee.setLastName(last);
}
std::string BasePlusCommissionEmployee::getLastName() const {
    return commissionEmployee.getLastName();
}

void BasePlusCommissionEmployee::setSocialSecurityNumber(const std::string& ssn) {
    commissionEmployee.setSocialSecurityNumber(ssn);
}
std::string BasePlusCommissionEmployee::getSocialSecurityNumber() const {
    return commissionEmployee.getSocialSecurityNumber();
}

void BasePlusCommissionEmployee::setGrossSales(double sales) {
    commissionEmployee.setGrossSales(sales);
}
double BasePlusCommissionEmployee::getGrossSales() const {
    return commissionEmployee.getGrossSales();
}

void BasePlusCommissionEmployee::setCommissionRate(double rate) {
    commissionEmployee.setCommissionRate(rate);
}
double BasePlusCommissionEmployee::getCommissionRate() const {
    return commissionEmployee.getCommissionRate();
}

// Calculate earnings (base salary + commission)
double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + commissionEmployee.earnings();
}

// Print details (includes base salary + CommissionEmployee details)
void BasePlusCommissionEmployee::print() const {
    std::cout << "base-salaried ";
    commissionEmployee.print();
    std::cout << "base salary: " << std::fixed << std::setprecision(2)
              << baseSalary << "\n";
}
