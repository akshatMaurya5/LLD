#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Poll
{
public:
    int pollId;
    string title;
    vector<string> questions;
    map<int, map<int, int>> votes; // questionIndex -> optionIndex -> voteCount

    Poll() {}
    Poll(int id, string title, vector<string> questions) : pollId(id), title(title), questions(questions) {}

    void updateQuestion(int index, string newQues)
    {
        if (index >= 0 && index < questions.size())
        {
            questions[index] = newQues;
        }
        else
        {
            cout << "Invalid question index" << endl;
        }
    }

    void addVote(int questionIndex, int optionIndex)
    {
        votes[questionIndex][optionIndex]++;
    }

    void printResults()
    {
        cout << "Results for poll: " << title << endl;

        for (auto &q : votes)
        {
            std::cout << "Question " << q.first << ": " << questions[q.first] << std::endl;
            for (auto &opt : q.second)
            {
                std::cout << "  Option " << opt.first << ": " << opt.second << " votes" << std::endl;
            }
        }
    }
};