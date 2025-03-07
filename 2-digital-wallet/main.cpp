#include <iostream>
#include "wallet-manager.cpp"

using namespace std;

int main()
{
    WalletManager walletManager;

    int choice;
    string acc1, acc2;
    double amount;

    while (true)
    {
        cout << "\n1. Create Wallet\n2. Transfer Amount\n3. Account Statement\n4. Overview\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter account number: ";
            cin >> acc1;
            walletManager.createWallet(acc1);
            break;

        case 2:
            cout << "Enter account number: ";
            cin >> acc1;
            cout << "Enter deposit amount: ";
            cin >> amount;
            walletManager.depositAmount(acc1, amount);
            break;

        case 3:
            cout << "Enter account number: ";
            cin >> acc1;
            walletManager.showAccountStatement(acc1);
            break;

        case 4:
            walletManager.showOverview();
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}

// test for the gh account