#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "User.cpp"
#include "Post.h"
#include "Question.cpp"
#include "Answer.cpp"
#include "Comment.cpp"

using namespace std;

class Stackoverflow
{
private:
    map<int, User *> users;
    map<int, Question *> questions;
    map<int, Answer *> answers;
    map<int, vector<Comment *>> comments;

public:
    ~Stackoverflow()
    {
        for (auto it = users.begin(); it != users.end(); ++it)
            delete it->second;
        for (auto it = questions.begin(); it != questions.end(); ++it)
            delete it->second;
        for (auto it = answers.begin(); it != answers.end(); ++it)
            delete it->second;
        for (auto it = comments.begin(); it != comments.end(); ++it)
            for (auto comment : it->second)
                delete comment;
    }

    User *registerUser(string username, string email)
    {
        User *user = new User(username, email);
        users[user->getUserId()] = user;
        return user;
    }

    void displayUserProfile(int userId)
    {
        if (users.find(userId) == users.end())
        {
            cout << "User not found" << endl;
            return;
        }
        users[userId]->displayProfile();
    }

    Post *addQuestion(int userId, string content, vector<string> tags)
    {
        Question *question = new Question(userId, content, tags);
        questions[question->getPostId()] = question;
        return question;
    }

    Post *addAnswer(int userId, int questionId, string content)
    {
        if (questions.find(questionId) == questions.end())
            return nullptr;
        Answer *answer = new Answer(userId, questionId, content);
        answers[answer->getPostId()] = answer;
        return answer;
    }

    void addComment(int userId, int postId, std::string content)
    {
        Comment *comment = new Comment(userId, postId, content);
        comments[postId].push_back(comment);
    }

    void votePost(int userId, int postId)
    {
        if (questions.find(postId) != questions.end())
            questions[postId]->upvote();
        else if (answers.find(postId) != answers.end())
            answers[postId]->upvote();
        users[userId]->updateReputation(10);
    }

    void acceptAnswer(int userId, int postId)
    {
        if (answers.find(postId) != answers.end())
        {
            answers[postId]->acceptAnswer();
            users[answers[postId]->getUserId()]->updateReputation(50);
        }
    }

    void displayQuestion(int questionId)
    {
        if (questions.find(questionId) == questions.end())
            return;
        questions[questionId]->displayInfo();
        for (auto answer : answers)
        {
            int answerId = answer.first;
            Answer *ans = answer.second;
            if (ans->getPostId() == questionId)
                ans->displayInfo();
        }
    }

    std::vector<Question *> searchQuestions(std::string keyword)
    {
        std::vector<Question *> result;
        for (auto question : questions)
        {
            int id = question.first;
            Question *q = question.second;
            if (q->getPostId() == id)
                result.push_back(q);
        }
        return result;
    }
};
