#include <iostream>
#include <sstream>
#include "expenseManager.cpp"
using namespace std;

int main()
{
    ExpenseManager manager;

    // Create Users
    manager.addUser("u1", "User1", "user1@example.com", "1234567890");
    manager.addUser("u2", "User2", "user2@example.com", "1234567891");
    manager.addUser("u3", "User3", "user3@example.com", "1234567892");
    manager.addUser("u4", "User4", "user4@example.com", "1234567893");

    string command;
    while (getline(cin, command))
    {
        istringstream iss(command);
        string action;
        iss >> action;

        if (action == "SHOW")
        {
            string userId;
            if (iss >> userId)
            {
                manager.showUserBalance(userId);
            }
            else
            {
                manager.showBalances();
            }
        }
        else if (action == "EXPENSE")
        {
            string payer, type;
            double amount;
            int numUsers;
            iss >> payer >> amount >> numUsers;

            vector<string> users(numUsers);
            for (int i = 0; i < numUsers; ++i)
            {
                iss >> users[i];
            }
            iss >> type;

            vector<double> values;
            if (type == "EXACT" || type == "PERCENT")
            {
                values.resize(numUsers);
                for (int i = 0; i < numUsers; ++i)
                {
                    iss >> values[i];
                }
            }

            manager.addExpense(Expense(payer, amount, users, type, values));
        }
    }
}
