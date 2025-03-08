#include <vector>
#include <iostream>
#include "Post.h"

using namespace std;

class Question : public Post
{
private:
    vector<string> tags;

public:
    Question(int userId, string content, vector<string> tags) : Post(userId, content), tags(tags) {}

    void displayInfo() const override
    {
        cout << "Question ID: " << postId << "\nTags: ";
        for (const auto &tag : tags)
            cout << tag << " ";
        cout << "\n";
        Post::displayInfo();
    }
};