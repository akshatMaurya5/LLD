#include "PollManager.cpp"
#include <unordered_map>

using namespace std;

class User
{
public:
    int userId;
    unordered_map<int, pair<int, int>> votedPolls;

    User(int userId) : userId(userId) {}

    void voteOnPoll(PollManager &manager, int pollId, int questionIndex, int optionIndex)
    {
        if (votedPolls.find(pollId) == votedPolls.end())
        {
            // means user does not have access to this poll, so give him access

            manager.vote(pollId, questionIndex, optionIndex);
            votedPolls[pollId] = {questionIndex, optionIndex};
        }
        else
        {
            cout << "You have already voted on this poll" << endl;
        }
    }
};