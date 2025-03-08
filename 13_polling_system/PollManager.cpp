#include "poll.cpp"
#include <unordered_map>
using namespace std;

class PollManager
{

private:
    unordered_map<int, Poll> polls;
    int nextPollid = 1;

public:
    int createPoll(string title, vector<string> questions)
    {
        int pollId = nextPollid++;
        polls[pollId] = Poll(pollId, title, questions);
        return pollId;
    }

    void deletePoll(int pollid)
    {
        if (polls.find(pollid) != polls.end())
        {
            polls.erase(pollid);
            cout << "Poll deleted successfully" << endl;
        }
        else
        {
            cout << "Poll not found" << endl;
        }
    }

    void updatePoll(int pollid, int questionIndex, string newQuestion)
    {
        if (polls.find(pollid) != polls.end())
        {
            polls[pollid].updateQuestion(questionIndex, newQuestion);
            cout << "Poll updated successfully" << endl;
        }
        else
        {
            cout << "Poll not found" << endl;
        }
    }

    void vote(int pollid, int questionIndex, int optionIndex)
    {
        if (polls.find(pollid) != polls.end())
        {
            polls[pollid].addVote(questionIndex, optionIndex);
            cout << "Vote added successfully" << endl;
        }
        else
        {
            cout << "Poll not found" << endl;
        }
    }

    void printResult(int pollId)
    {
        if (polls.find(pollId) != polls.end())
        {
            polls[pollId].printResults();
        }
        else
        {
            cout << "Poll not found" << endl;
        }
    }
};
