#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
private:
    double savingsBalance;                  // Individual balance
    static double annualInterestRate;       // Shared interest rate

public:
    // Constructor
    SavingsAccount(double balance = 0.0);

    // Calculate and add monthly interest
    void calculateMonthlyInterest();

    // Display balance
    void displayBalance() const;

    // Static function to modify interest rate
    static void modifyInterestRate(double newRate);
};

#endif
