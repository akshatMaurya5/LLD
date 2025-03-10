#include <bits/stdc++.h>
using namespace std;

class Option
{
public:
    string text;
    int voteCount;

    Option(string optionContent) : text(optionContent), voteCount(0) {}

    void setOptionText(string newText)
    {
        text = newText;
    }
};

class Poll
{
public:
    string pollId;
    string question;
    vector<Option> options;
    time_t creationTime;
    set<string> voters;
    bool isBeingUpdated;
    string creatorId;

    Poll(string &id, string &question, vector<string> &optionTexts, string &creator)
    {
        this->pollId = id;
        this->question = question;
        this->creationTime = time(0);
        this->voters.clear();
        this->creatorId = creator;
        this->isBeingUpdated = false;

        for (auto &text : optionTexts)
        {
            this->options.emplace_back(text);
        }
    }

    bool vote(string &userId, int optionIndex)
    {
        if (isBeingUpdated)
            return false;

        if (optionIndex < 0 || optionIndex >= options.size())
        {
            cout << "Invalid option index\n";
            return false;
        }

        if (voters.count(userId))
        {
            cout << "User has already voted" << endl;
            return false;
        }

        isBeingUpdated = true;

        options[optionIndex].voteCount++;
        voters.insert(userId);

        isBeingUpdated = false;
        return true;
    }

    void displayResults() const
    {
        cout << "Poll ID: " << pollId << "\nQuestion: " << question << "\nCreation Time: " << ctime(&creationTime) << "Results:\n";
        for (const auto &option : options)
        {
            cout << option.text << ": " << option.voteCount << " votes\n";
        }
    }
};

class PollManager
{
private:
    map<string, Poll> polls;

public:
    string createPoll(string &question, vector<string> &options, string &creatorId)
    {
        string pollId = "poll_" + to_string(polls.size() + 1);
        polls.emplace(pollId, Poll(pollId, question, options, creatorId));
        return pollId;
    }

    bool deletePoll(string &pollId, string &userid)
    {
        auto it = polls.find(pollId);
        if (it == polls.end())
        {
            cout << "Invalid poll id.\n";
            return false;
        }

        if (it->second.creatorId != userid)
        {
            return false;
        }

        polls.erase(it);

        return true;
    }

    Poll getPoll(string pollId)
    {
        auto it = polls.find(pollId);

        return it->second;
    }
};

class User
{
public:
    string userId;

    User() {}
    User(string id) : userId(id) {}

    string createPoll(PollManager &pollmanager, string question, vector<string> options)
    {
        return pollmanager.createPoll(question, options, userId);
    }

    bool deletePoll(PollManager &pollmanager, string &pollId)
    {
        return pollmanager.deletePoll(pollId, userId);
    }

    bool vote(Poll &poll, int optionIndex)
    {
        return poll.vote(userId, optionIndex);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    PollManager pollManager;

    // Create users
    User user1("user1");
    User user2("user2");

    // User1 creates a poll
    std::string pollId = user1.createPoll(pollManager, "What is your favorite color?", {"Red", "Blue", "Green", "Yellow"});
    std::cout << "User1 created Poll with ID: " << pollId << std::endl;

    // User2 tries to delete the poll (should fail)
    bool deleteResult = user2.deletePoll(pollManager, pollId);
    std::cout << "User2 tried to delete the poll. Success: " << (deleteResult ? "Yes" : "No") << std::endl;

    // User1 deletes the poll (should succeed)
    deleteResult = user1.deletePoll(pollManager, pollId);
    std::cout << "User1 tried to delete the poll. Success: " << (deleteResult ? "Yes" : "No") << std::endl;

    // Try to get a deleted poll (should throw an error)
    try
    {
        Poll poll = pollManager.getPoll(pollId);
        poll.displayResults();
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}