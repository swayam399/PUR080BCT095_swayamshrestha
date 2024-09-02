/*Create a base class Account with data memebers accountNumber and balance. Derive two classes SavingsAccount
 and Checking Accountfrom Account. Implement polymorphic behaviour where the base class pointer can point to
 objects of derived classes, and call their repsective memeber functions to deposit and withdraw money, applying
sppecific rules each account types. */
#include <iostream>
using namespace std;

class Account
{
protected:
    int accountNumber;
    double balance;

public:
    Account(int acc_Num, double initialBalance) : accountNumber(acc_Num), balance(initialBalance) {}

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;

    virtual void display() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account
{

public:
    SavingsAccount(int accNum, double initialBalance) : Account(accNum, initialBalance) {}

    void deposit(double amount) override
    {
        balance += amount;
    }

    void withdraw(double amount) override
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance in SavingsAccount" << endl;
        }
    }

    void display() const override
    {
        Account::display();
        cout << "Account Type: Savings" << endl;
    }
};

class CheckingAccount : public Account
{
    static const double overdraftLimit = 500.00;

public:
    CheckingAccount(int accNum, double initialBalance) : Account(accNum, initialBalance) {}

    void deposit(double amount) override
    {
        balance += amount;
    }

    void withdraw(double amount) override
    {
        if (amount <= balance + overdraftLimit)
        {
            balance -= amount;
        }
        else
        {
            cout << "Exceeded overdraft limit in CheckingAccount" << endl;
        }
    }

    void display() const override
    {
        Account::display();
        cout << "Account Type: Checking" << endl;
    }
};

int main()
{

    Account *accountptr[2];
    accountptr[0] = new SavingsAccount(12345, 1000.00);
    accountptr[1] = new CheckingAccount(67890, 500.00);

    accountptr[0]->deposit(200.00);
    accountptr[0]->withdraw(50.00);
    accountptr[0]->display();

    accountptr[1]->deposit(100.00);
    accountptr[1]->withdraw(600.00);
    accountptr[1]->display();

    delete accountptr[0];
    delete accountptr[1];

    return 0;
}
