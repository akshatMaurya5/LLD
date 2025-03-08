#include "user.cpp"

int main()
{
    PollManager pollManager;

    int pollId = pollManager.createPoll("Favorite Programming Language",
                                        {"C++", "Python", "Java", "Go"});

    User user1(1);
    User user2(2);

    user1.voteOnPoll(pollManager, pollId, 0, 1);
    user2.voteOnPoll(pollManager, pollId, 0, 2);

    // Attempt duplicate vote
    user1.voteOnPoll(pollManager, pollId, 0, 2);

    pollManager.printResult(pollId);
}