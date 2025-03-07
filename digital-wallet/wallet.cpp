#include <iostream>
#include <iomanip>
using namespace std;

class Wallet
{
private:
    string accountNumber;
    double balance;

public:
    Wallet(string accNum) : accountNumber(accNum), balance(0.0) {}

    string getAccountNumber() const
    {
        return accountNumber;
    }

    bool deposit(double amount)
    {
        if (amount < 0.0001)
            return false;
        balance += amount;
        return true;
    }

    bool withdraw(double amount)
    {
        if (amount < 0.0001 || amount > balance)
            return false;
        balance -= amount;
        return true;
    }

    void printStatement() const
    {
        cout << "Account: " << accountNumber << " | Balance: F₹ " << fixed << setprecision(4) << balance << "\n";
    }
};
