// CommissionEmployee.cpp


#include "DivyaSree_oct6_task1_CommissionEmployee.h"

// Constructor definition
CommissionEmployee::CommissionEmployee(const std::string& first, const std::string& last,
                                       const std::string& ssn, double sales, double rate)
    : firstName(first), lastName(last), socialSecurityNumber(ssn),
      grossSales(sales), commissionRate(rate) {
    std::cout << "CommissionEmployee constructor:\n";
    print();
}

// Destructor definition
CommissionEmployee::~CommissionEmployee() {
    std::cout << "CommissionEmployee destructor:\n";
    print();
}

// Setters and getters
void CommissionEmployee::setFirstName(const std::string& first) { firstName = first; }
std::string CommissionEmployee::getFirstName() const { return firstName; }

void CommissionEmployee::setLastName(const std::string& last) { lastName = last; }
std::string CommissionEmployee::getLastName() const { return lastName; }

void CommissionEmployee::setSocialSecurityNumber(const std::string& ssn) {
    socialSecurityNumber = ssn;
}
std::string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

void CommissionEmployee::setGrossSales(double sales) {
    grossSales = (sales < 0.0) ? 0.0 : sales;
}
double CommissionEmployee::getGrossSales() const { return grossSales; }

void CommissionEmployee::setCommissionRate(double rate) {
    commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0.0;
}
double CommissionEmployee::getCommissionRate() const { return commissionRate; }

// Calculate total earnings
double CommissionEmployee::earnings() const {
    return commissionRate * grossSales;
}

// Print employee details
void CommissionEmployee::print() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "commission employee: " << firstName << ' ' << lastName << '\n'
              << "social security number: " << socialSecurityNumber << '\n'
              << "gross sales: " << grossSales << '\n'
              << "commission rate: " << commissionRate << '\n';
}
