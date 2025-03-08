
#include <iostream>
#include <string>
using namespace std;

class Comment
{
private:
    static int nextCommentId;
    int commentId;
    int userId;
    int postId;
    string content;

public:
    Comment(int userId, int postId, string content) : commentId(nextCommentId++), userId(userId), postId(postId), content(content) {}

    void displayInfo() const
    {
        cout << "Comment by User " << userId << " on Post " << postId << ": " << content << "\n";
    }
};
int Comment::nextCommentId = 1;