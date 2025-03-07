#include "wallet.cpp"

#include <iostream>
#include <map>
using namespace std;

class WalletManager
{
private:
    map<string, Wallet *> wallets;

public:
    ~WalletManager()
    {
        for (auto it : wallets)
        {
            delete it.second;
        }
    }

    void createWallet(string accountNumber)
    {
        if (wallets.count(accountNumber))
        {
            cout << "Wallet already exists" << endl;
            return;
        }
        wallets[accountNumber] = new Wallet(accountNumber);

        cout << "Wallet created successfully for account number: " << accountNumber << endl;
    }

    void transferAmount(string sender, string receiver, double amount)
    {

        if (!wallets.count(sender) || !wallets.count(receiver))
        {
            cout << "Invalid sender or receiver account number" << endl;
            return;
        }

        if (wallets[sender]->withdraw(amount) && wallets[receiver]->deposit(amount))
        {
            cout << "Transferred F₹ " << amount << " from " << sender << " to " << receiver << endl;
        }
        else
        {
            cout << "Transfer failed due to insufficient balance or invalid amount.\n";
        }
    }

    void depositAmount(std::string accountNumber, double amount)
    {
        if (wallets.find(accountNumber) == wallets.end())
        {
            std::cout << "Account not found!\n";
            return;
        }
        if (wallets[accountNumber]->deposit(amount))
        {
            std::cout << "Deposited F₹ " << amount << " into account " << accountNumber << "\n";
        }
        else
        {
            std::cout << "Invalid deposit amount!\n";
        }
    }

    void showAccountStatement(string accountNumber)
    {
        if (wallets.find(accountNumber) == wallets.end())
        {
            cout << "Account not found" << endl;
            return;
        }

        wallets[accountNumber]->printStatement();
    }

    void showOverview()
    {
        cout << "Current wallet overview is--->" << endl;
        for (auto &pair : wallets)
        {
            pair.second->printStatement();
        }
    }
};
