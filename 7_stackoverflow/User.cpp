#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    static int nextId;
    int userId;
    string username;
    string email;
    int reputation;

public:
    User(string username, string email) : userId(nextId++), username(username), email(email), reputation(0) {}

    int getUserId() const { return userId; }

    string getUsername() const
    {
        return username;
    }

    string getEmail() const
    {
        return email;
    }

    int getReputation() const
    {
        return reputation;
    }

    void updateReputation(int change)
    {
        reputation += change;
    }

    void displayProfile() const
    {
        cout << "User: " << username << " (Reputation: " << reputation << ")\n";
    }
};
int User::nextId = 1;
