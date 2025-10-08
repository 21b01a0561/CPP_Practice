#include <iostream>
#include "DhamarikaDivyaSree_sept25_task1_SavingsAccount.h"


int main() {
    // Create two savers with given balances
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    // Set interest rate to 3%
    SavingsAccount::modifyInterestRate(0.03);

    // Calculate monthly interest
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "Balances after 1 month at 3% annual interest:" << std::endl;
    std::cout << "Saver 1: "; saver1.displayBalance(); std::cout << std::endl;
    std::cout << "Saver 2: "; saver2.displayBalance(); std::cout << std::endl;

    // Change interest rate to 4%
    SavingsAccount::modifyInterestRate(0.04);

    // Calculate next month’s interest
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "\nBalances after next month at 4% annual interest:" << std::endl;
    std::cout << "Saver 1: "; saver1.displayBalance(); std::cout << std::endl;
    std::cout << "Saver 2: "; saver2.displayBalance(); std::cout << std::endl;

    return 0;
}
