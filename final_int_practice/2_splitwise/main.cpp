#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

enum SplitType
{
    EQUAL,
    EXACT,
    PERCENTAGE
};

class User
{
public:
    int id;
    string name;
    User(int id, string name) : id(id), name(name) {}
};

class Expense
{
public:
    int expenseId;
    double amount;
    User *payer;
    SplitType splitType;
    map<User *, double> splits;

    Expense(int id, double amount, User *payer, SplitType splitType)
        : expenseId(id), amount(amount), payer(payer), splitType(splitType) {}

    void addSplit(User *user, double amt)
    {
        splits[user] = amt;
    }
};

class SplitWise
{
private:
    map<int, User *> users;
    map<int, Expense *> expenses;
    int nextUserId = 1;
    int nextExpenseId = 1;

public:
    User *addUser(string name)
    {
        User *user = new User(nextUserId++, name);
        users[user->id] = user;
        return user;
    }

    void splitExpense(double amount, User *payer, SplitType splitType, vector<User *> participants, vector<double> shares = {})
    {

        Expense *expense = new Expense(nextExpenseId++, amount, payer, splitType);

        switch (splitType)
        {

        case EQUAL:
        {
            double share = amount / participants.size();
            for (auto user : participants)
            {
                expense->addSplit(user, share);
            }
            break;
        }
        case EXACT:
        {
            if (shares.size() != participants.size())
            {
                cout << "Number of shares must match number of participants for EXACT split." << endl;
                return;
            }

            for (int i = 0; i < participants.size(); i++)
            {
                expense->addSplit(participants[i], shares[i]);
            }
            break;
        }
        case PERCENTAGE:
        {
            if (shares.size() != participants.size())
            {
                cout << "Number of shares must match number of participants for PERCENTAGE split." << endl;
                return;
            }

            double totalPercentage = 0;

            for (auto percent : shares)
            {
                totalPercentage += percent;
            }

            if (totalPercentage != 100)
            {
                cout << "Total percentage must be 100 for PERCENTAGE split." << endl;
                return;
            }

            for (int i = 0; i < participants.size(); i++)
            {
                double share = (amount * shares[i]) / 100;
                expense->addSplit(participants[i], share);
            }

            break;
        }
        default:
        {
            cout << "Invalid split type." << endl;
            return;
        }
        }

        expenses[expense->expenseId] = expense;
    }

    void showExpenses()
    {
        for (auto pair : expenses)
        {
            auto expense = pair.second;

            cout << "--------------------------------" << endl;

            cout << "Expense ID: " << expense->expenseId << " Amount: " << expense->amount << " Payer: " << expense->payer->name << endl;

            switch (expense->splitType)
            {
            case EQUAL:
                cout << "Split Type: EQUAL" << endl;
                break;
            case EXACT:
                cout << "Split Type: EXACT" << endl;
                break;
            case PERCENTAGE:
                cout << "Split Type: PERCENTAGE" << endl;
                break;
            default:
                cout << "Invalid split type." << endl;
                break;
            }

            for (auto split : expense->splits)
            {
                cout << "User: " << split.first->name << " Amount: " << split.second << endl;
            }
            cout << "--------------------------------" << endl;
        }
    }

    void showExpenseForUser(User *user)
    {
        for (auto pair : expenses)
        {
            auto expense = pair.second;

            if (expense->splits.count(user))
            {
                cout << "--------------------------------" << endl;
                cout << "Expense ID: " << expense->expenseId << " Amount: " << expense->amount << " Payer: " << expense->payer->name << endl;

                switch (expense->splitType)
                {
                case EQUAL:
                    cout << "Split Type: EQUAL" << endl;
                    break;
                case EXACT:
                    cout << "Split Type: EXACT" << endl;
                    break;
                case PERCENTAGE:
                    cout << "Split Type: PERCENTAGE" << endl;
                    break;
                }

                cout << "User: " << user->name << " Amount: " << expense->splits[user] << endl;
                cout << "--------------------------------" << endl;
            }
        }
    }
};

int main()
{
    SplitWise splitwise;

    User *user1 = splitwise.addUser("Alice");
    User *user2 = splitwise.addUser("Bob");
    User *user3 = splitwise.addUser("Charlie");

    // Equal split
    splitwise.splitExpense(300, user1, SplitType::EQUAL, {user1, user2, user3});

    // Exact split
    splitwise.splitExpense(1000, user2, SplitType::EXACT, {user1, user2, user3}, {200, 300, 500});

    // Percentage split
    splitwise.splitExpense(500, user3, SplitType::PERCENTAGE, {user1, user2, user3}, {20, 30, 50});

    cout << "All Expenses:" << endl;
    splitwise.showExpenses();

    // Show expenses for a specific user
    cout << "\nExpenses for Alice:" << endl;
    splitwise.showExpenseForUser(user1);

    return 0;
}