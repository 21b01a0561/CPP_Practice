// Account.cpp
// Member-function definitions for class Account.

#include "DhamarikaDivyaSree_sept22_task2_Account.h"

// constructor initializes balance with validation using initializer list
Account::Account(double initialBalance)
    : balance(initialBalance >= 0.0 ? initialBalance : 0.0)
{
    if (initialBalance < 0.0)
    {
        std::cout << "Error: Initial balance was invalid. Setting balance to 0." << std::endl;
    }
}

// add an amount to the account balance
void Account::credit(double amount)
{
    balance += amount; // add amount to balance
}

// withdraw an amount from the account balance if sufficient funds
void Account::debit(double amount)
{
    if (amount > balance)
    {
        std::cout << "Debit amount exceeded account balance." << std::endl;
    }
    else
    {
        balance -= amount; // subtract amount from balance
    }
}

// return the account balance
double Account::getBalance() const
{
    return balance;
}

