#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <map>
#include <iomanip>
#include "user.cpp"
#include "expense.cpp"
using namespace std;

class ExpenseManager
{
private:
    map<string, map<string, double>> balanceSheet;
    map<string, User> users;

public:
    void addUser(string userId, string name, string email, string mobile)
    {
        users.emplace(userId, User(userId, name, email, mobile));
    }
    void addExpense(Expense expense)
    {
        int n = expense.participants.size();
        string payer = expense.paidBy;
        string expenseType = expense.type;
        double total = expense.amount;

        if (expenseType == "EQUAL")
        {
            double share = round(total / n * 100) / 100;
            double firstShare = share + (total - share * n);

            for (int i = 0; i < n; ++i)
            {
                if (expense.participants[i] != payer)
                {
                    balanceSheet[expense.participants[i]][payer] += (i == 0 ? firstShare : share);
                    balanceSheet[payer][expense.participants[i]] -= (i == 0 ? firstShare : share);
                }
            }
        }
        else if (expenseType == "EXACT")
        {
            double sum = 0;
            for (double v : expense.values)
                sum += v;
            if (sum != total)
            {
                cerr << "Invalid exact amounts!" << endl;
                return;
            }

            for (int i = 0; i < n; ++i)
            {
                if (expense.participants[i] != payer)
                {
                    balanceSheet[expense.participants[i]][payer] += expense.values[i];
                    balanceSheet[payer][expense.participants[i]] -= expense.values[i];
                }
            }
        }
        else if (expenseType == "PERCENT")
        {
            double sum = 0;
            for (double v : expense.values)
                sum += v;
            if (sum != 100)
            {
                cerr << "Invalid percentage sum!" << endl;
                return;
            }

            for (int i = 0; i < n; ++i)
            {
                double share = round((expense.values[i] * total / 100) * 100) / 100.0;
                if (expense.participants[i] != payer)
                {
                    balanceSheet[expense.participants[i]][payer] += share;
                    balanceSheet[payer][expense.participants[i]] -= share;
                }
            }
        }
    }

    void showUserBalance(string userId)
    {

        bool hasBalance = false;
        for (const auto &p : balanceSheet[userId])
        {
            if (p.second > 0)
            {
                cout << userId << " owes " << p.first << ": " << fixed << setprecision(2) << p.second << endl;
                hasBalance = true;
            }
        }
        for (const auto &p : balanceSheet)
        {
            if (p.second.count(userId) && p.second.at(userId) > 0)
            {
                cout << p.first << " owes " << userId << ": " << fixed << setprecision(2) << p.second.at(userId) << endl;
                hasBalance = true;
            }
        }
        if (!hasBalance)
            cout << "No balances" << endl;
    }

    void showBalances()
    {
        bool hasAnyBalance = false;
        for (const auto &userBalances : balanceSheet)
        {
            for (const auto &balance : userBalances.second)
            {
                if (balance.second > 0)
                {
                    cout << userBalances.first << " owes " << balance.first << ": "
                         << fixed << setprecision(2) << balance.second << endl;
                    hasAnyBalance = true;
                }
            }
        }
        if (!hasAnyBalance)
            cout << "No balances" << endl;
    }
};
