#include <iostream>
#include <string>
using namespace std;

class User
{
public:
    string userId;
    string name;
    string email;
    string mobile;

    User(string userId, string name, string email, string mobile) : userId(userId), name(name), email(email), mobile(mobile) {}
};