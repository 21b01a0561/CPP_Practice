// main.cpp
// Program to test class Account with double balances.

#include <iostream>
#include "DhamarikaDivyaSree_sept22_task2_Account.h"

int main()
{
    // create two Account objects
    Account account1(50.75);   // valid initial balance
    Account account2(-7.25);   // invalid initial balance, should reset to 0

    // display initial balances
    std::cout << "Account1 balance: $" << account1.getBalance() << std::endl;
    std::cout << "Account2 balance: $" << account2.getBalance() << std::endl;

    // credit accounts
    std::cout << "\nAdding $25.50 to account1..." << std::endl;
    account1.credit(25.50);

    std::cout << "Adding $50.25 to account2..." << std::endl;
    account2.credit(50.25);

    // display balances
    std::cout << "Account1 balance: $" << account1.getBalance() << std::endl;
    std::cout << "Account2 balance: $" << account2.getBalance() << std::endl;

    // debit accounts
    std::cout << "\nAttempting to debit $30.25 from account1..." << std::endl;
    account1.debit(30.25);

    std::cout << "Attempting to debit $100.00 from account2..." << std::endl;
    account2.debit(100.00);

    // display final balances
    std::cout << "Account1 balance: $" << account1.getBalance() << std::endl;
    std::cout << "Account2 balance: $" << account2.getBalance() << std::endl;

    return 0;
}
