#include <bits/stdc++.h>
using namespace std;

class Option {
private:
    int nextOptionId = 1;
public:
    string id;
    string text;
    int votes;
    set<string>voters;

    Option(string text)
    {
        this->id = to_string(nextOptionId++);
        this->text = text;
        this->votes = 0;
        this->voters.clear();
    }

    bool vote(string userId)
    {
        votes++;
        voters.insert(userId);
    }

    void printOption()
    {
        cout << "Option: " << text << " Vote count: " << votes << endl;
    }

    void printVoters()
    {
        for (auto userId : voters)
        {
            cout << userId << " ";
        }
        cout << endl;
    }

    bool updateOption(string newText)
    {
        this->text = newText;
        this->voters.clear();
    }
};

class Poll {
public:
    string id;
    string question;
    vector<Option*>options;
    string creatorId;
    set<string>voters;
    bool isBeingUpdated;
    time_t timestamp;

    Poll(string pollId, string question, vector<string>optionReceived, string userId)
    {
        this->id = pollId;
        this->question = question;
        this->creatorId = userId;
        this->isBeingUpdated = false;
        this->timestamp = time(0);
        for (auto option : optionReceived)
        {
            Option* newOption = new Option(option);
            options.emplace_back(newOption);
        }
    }

    bool vote(string userId, int optionIndex)
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
            cout << "User has already voted on this poll\n";
            return false;
        }

        isBeingUpdated = true;


        options[optionIndex]->vote(userId);
        // displayResult();
        voters.insert(userId);

        isBeingUpdated = false;
        return true;
    }


    bool updatePoll(string newQuestion,  vector<string>newOptions)
    {

        if (isBeingUpdated)
            return false;

        isBeingUpdated = true;
        this->question = newQuestion;
        this->options.clear();

        for (int i = 0; i < options.size(); i++)
        {
            string newOption = newOptions[i];
            string oldOption = options[i]->text;

            if (newOption != oldOption)
            {
                options[i]->updateOption(newOption);
            }
        }

        isBeingUpdated = false;
        return true;
    }

    void displayResult() const {
        cout << "Poll id: " << id << endl;
        cout << "Question: " << question << endl;
        cout << "Created By: " << creatorId << endl;

        for (auto &option : options)
        {
            cout << "Option: " << option->text << " has votes: " << option->votes << endl;
        }

        // for (auto option : options)
        // {
        //     option.printOption();
        //     option.printVoters();
        // }
    }
};

class PollingManager {
private:
    map<string, Poll>polls;
    int nextPollId = 1;
public:

    string createPoll(string question, vector<string>options, string userId)
    {
        string pollId = "poll_" + to_string(nextPollId++);

        polls.emplace(pollId, Poll(pollId, question, options, userId));

        return pollId;
    }

    void printPoll(string pollId)
    {
        auto it = polls.find(pollId);
        it->second.displayResult();
    }

    bool deletePoll(string pollId, string userId)
    {
        auto it = polls.find(pollId);

        if (it == polls.end())
        {
            cout << "Invalid poll id\n";
            return false;
        }

        string pollCreator = it->second.creatorId;

        if (userId != pollCreator)
        {
            cout << "Only the creator of the poll can delete the poll" << endl;
            return false;
        }

        polls.erase(it);

        return true;
    }


    bool updatePoll(string pollId, string userId, string newQuestion, vector<string>newOptions)
    {
        auto it = polls.find(pollId);

        if (it == polls.end())
        {
            cout << "Invalid poll id\n";
            return false;
        }

        string pollCreator = it->second.creatorId;

        if (userId != pollCreator)
        {
            cout << "Only the creator of the poll can delete the poll" << endl;
            return false;
        }

        Poll currentPoll = it->second;

        currentPoll.updatePoll(newQuestion, newOptions);

        return true;
    }

    Poll getPoll(string pollId)
    {
        auto it = polls.find(pollId);
        return it->second;
    }
};


class User {
public:
    string userId;


    User(string id) {
        cout << "Creater user with id: " << id << endl;

        this->userId = id;
    }

    Poll createPoll(PollingManager& pollManager, string question, vector<string>options)
    {
        string pollId = pollManager.createPoll(question, options, userId);
        return pollManager.getPoll(pollId);
    }

    bool deletePoll(PollingManager& pollManager, string pollId)
    {
        return pollManager.deletePoll(pollId, userId);
    }

    bool updatePoll(PollingManager& pollManager, string pollId, string newQuestion, vector<string>newOptions)
    {
        return pollManager.updatePoll(pollId, userId, newQuestion, newOptions);
    }


    void displayPoll(PollingManager pollManager, string pollId)
    {
        pollManager.printPoll(pollId);
    }
};


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    PollingManager pollManager;

    User user1("user1");
    User user2("user2");

    Poll poll1 = user1.createPoll(pollManager, "What is ur fav language?", {
        "C++", "Java", "Golang", "Python"
    });

    user1.displayPoll(pollManager, poll1.id);

    poll1.vote("user1", 1);

    poll1.vote("user2", 3);
    poll1.vote("user2", 2);

    user1.displayPoll(pollManager, poll1.id);

    return 0;
}
