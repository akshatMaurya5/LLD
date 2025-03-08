#include "user.h"

User::User(int id, string username) : id(id), username(username) {}

void User::follow(int userId)
{
    following.insert(userId);
}

void User::unfollow(int userId)
{
    following.erase(userId);
}
