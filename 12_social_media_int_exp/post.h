#ifndef POST_H
#define POST_H

#include <string>
#include <time.h>
#include <ctime>
#include <vector>

using namespace std;

class Post
{
public:
    int id;
    int authorId;
    string content;
    time_t timestamp;
    int likes;
    vector<string> comments;

public:
    Post(int postId, int authorId, string content);

    int getPostId() const;
    void likePost();
    void addComment(string comment);

    bool operator<(const Post &other) const
    {
        return this->id < other.id; // Needed for set ordering
    }
};

#endif
