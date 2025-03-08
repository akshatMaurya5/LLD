#include "SocialMedia.h"
#include <iostream>
using namespace std;

int main()
{
    SocialMedia app;

    app.createUser(1, "Alice");
    app.createUser(2, "Bob");

    app.followUser(1, 2);

    app.createPost(2, "Bob's first post!");
    app.createPost(2, "Bob's second post!");

    app.likePost(1);
    app.commentPost(1, "Nice post!");
    app.commentPost(1, "Great!");

    vector<Post> feed = app.getFeed(1);
    for (auto &p : feed)
    {
        cout << "Post ID: " << p.id << " Content: " << p.content << " Likes: " << p.likes << endl;
        for (auto &c : p.comments)
        {
            cout << " - Comment: " << c << endl;
        }
    }

    return 0;
}
