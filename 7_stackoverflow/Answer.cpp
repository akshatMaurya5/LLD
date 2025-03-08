#include "Post.h"

class Answer : public Post
{
private:
    int questionId;
    bool isAccepted;

public:
    Answer(int userId, int questionId, string content) : Post(userId, content), questionId(questionId), isAccepted(false) {}

    void acceptAnswer()
    {
        isAccepted = true;
    }

    void displayInfo() const override
    {
        cout << "Answer to Question ID: " << questionId << (isAccepted ? " (Accepted)" : "") << "\n";
        Post::displayInfo();
    }
};
