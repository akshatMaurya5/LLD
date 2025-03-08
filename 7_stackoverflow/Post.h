#ifndef POST_H
#define POST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Post
{
protected:
    static int nextPostId;
    int postId;
    int userId;
    string content;
    int votes;

public:
    Post(int userId, string content);

    int getPostId() const;
    int getUserId() const;
    string getContent() const;
    int getVotes() const;

    void upvote();
    void downvote();
    virtual void displayInfo() const;
};

#endif // POST_H