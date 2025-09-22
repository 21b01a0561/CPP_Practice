// Account.h
// Definition of Account class that represents a bank account.

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account
{
public:
    // constructor initializes balance with validation
    explicit Account(double initialBalance);

    // add an amount to the account balance
    void credit(double amount);

    // withdraw an amount from the account balance if sufficient funds
    void debit(double amount);

    // return the account balance
    double getBalance() const;

private:
    double balance; // account balance
};

#endif
