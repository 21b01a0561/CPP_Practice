#include <iostream>
#include <iomanip>
#include "DhamarikaDivyaSree_sept25_task1_SavingsAccount.h"


// Initialize static member
double SavingsAccount::annualInterestRate = 0.0;

// Constructor
SavingsAccount::SavingsAccount(double balance) {
    savingsBalance = balance;
}

// Function to calculate monthly interest
void SavingsAccount::calculateMonthlyInterest() {
    double monthlyInterest = (savingsBalance * annualInterestRate) / 12;
    savingsBalance += monthlyInterest;
}

// Function to display balance
void SavingsAccount::displayBalance() const {
    std::cout << fixed << setprecision(2) << "$" << savingsBalance;
}

// Static function to modify the interest rate
void SavingsAccount::modifyInterestRate(double newRate) {
    annualInterestRate = newRate;
}

