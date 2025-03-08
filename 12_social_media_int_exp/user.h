#ifndef USER_H
#define USER_H

#include <string>
#include <unordered_set>
using namespace std;

class User
{
public:
    int id;
    string username;
    unordered_set<int> followers;
    unordered_set<int> following;

public:
    User(int id, string username);
    void follow(int userId);
    void unfollow(int userId);
};

#endif
