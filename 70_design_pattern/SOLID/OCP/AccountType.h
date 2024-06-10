#pragma once

#include "BankAccount.h"

class AccountType
{
private:
    /* data */
public:
    friend class BankAccount;
    AccountType();
    virtual~AccountType();
    virtual void extract(const float number);
    virtual void deposit(const float number);
};
