#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <algorithm>
using namespace std;

class Post
{
public:
    int postid;
    string content;
    time_t timestamp;
    int userId;

    Post(int postid, string content)
    {
        this->postid = postid;
        this->content = content;
        this->timestamp = time(0);
    }
};

class User
{
public:
    int userId;
    string username;
    vector<Post> posts;
    set<int> followers;
    set<int> following;

    User(int id, string name)
    {
        this->userId = id;
        this->username = name;
    }

    void createPost(int postId, string content)
    {
        posts.push_back(Post(postId, content));
    }

    void deletePost(int postId)
    {
        vector<Post>::iterator it;
        for (it = posts.begin(); it != posts.end(); it++)
        {
            if (it->postid == postId)
            {
                posts.erase(it);
                break;
            }
        }
    }

    void followUser(int userId)
    {
        following.insert(userId);
    }

    void unfollowUser(int userId)
    {
        following.erase(userId);
    }
};

class SocialMediaManager
{
private:
    map<int, User *> users;
    int postCounter = 1;
    int userIdCounter = 1;

public:
    int addUser(string username)
    {
        User *user = new User(userIdCounter, username);
        users[userIdCounter++] = user;
        return userIdCounter - 1;
    }

    User *getUser(int userId)
    {
        return users[userId];
    }

    void createPost(int userId, string content)
    {
        if (!users.count(userId))
        {
            cout << "User does not exist" << endl;
            return;
        }

        users[userId]->createPost(postCounter++, content);
        cout << "Post created successfully" << endl;
        return;
    }

    void deletePost(int userId, int postId)
    {
        if (!users.count(userId))
        {
            cout << "User does not exist" << endl;
            return;
        }

        users[userId]->deletePost(postId);
        cout << "Post deleted successfully" << endl;
        return;
    }

    void followUser(int userId, int followerId)
    {
        if (!users.count(userId) || !users.count(followerId))
        {
            cout << "User does not exist" << endl;
            return;
        }

        users[userId]->followUser(followerId);
        cout << "User followed successfully" << endl;
        return;
    }

    void unfollowUser(int userId, int followerId)
    {
        if (!users.count(userId) || !users.count(followerId))
        {
            cout << "User does not exist" << endl;
            return;
        }

        users[userId]->unfollowUser(followerId);
        cout << "User unfollowed successfully" << endl;
        return;
    }

    vector<Post> getFeed(int userId)
    {
        if (!users.count(userId))
        {
            cout << "User does not exist" << endl;
            return vector<Post>();
        }

        vector<Post> feed;

        User *user = users[userId];

        // pushing back user's own posts first;
        for (auto post : user->posts)
        {
            feed.push_back(post);
        }

        set<int> following = user->followers;

        for (auto followerId : following)
        {
            User *followedUser = users[followerId];
            for (auto post : followedUser->posts)
            {
                feed.push_back(post);
            }
        }

        sort(feed.begin(), feed.end(), [](Post a, Post b)
             { return a.timestamp > b.timestamp; });

        return feed;
    }

    vector<Post> getPaginated(int userId, int page, int pageSize)
    {
        if (!users.count(userId))
        {
            cout << "User does not exist" << endl;
            return vector<Post>();
        }

        vector<Post> feed = getFeed(userId);

        int start = page * pageSize;
        int end = start + pageSize;

        if (start >= feed.size())
        {
            return {};
        }
        if (end > feed.size())
        {
            end = feed.size();
        }

        return vector<Post>(feed.begin() + start, feed.begin() + end);
    }
};

int main()
{
    SocialMediaManager smm;

    int aliceId = smm.addUser("Alice");
    int bobId = smm.addUser("Bob");
    int charlieId = smm.addUser("Charlie");

    // creating posts
    smm.createPost(aliceId, "hello world from alice");
    smm.createPost(bobId, "hello world from bob");
    smm.createPost(charlieId, "hello world from charlie");

    // folowing user
    smm.followUser(aliceId, bobId);
    smm.followUser(aliceId, charlieId);

    // getting feed
    vector<Post> feed = smm.getFeed(aliceId);

    cout << "Feed for Alice:" << std::endl;
    for (const Post &post : feed)
    {
        cout << "Post ID: " << post.postid << ", Content: " << post.content << ", Timestamp: " << post.timestamp << endl;
    }

    vector<Post> paginatedFeed = smm.getPaginated(aliceId, 0, 2);
    cout << "\nPaginated Feed for Alice (Page 0, PageSize 2):" << endl;
    for (const Post &post : paginatedFeed)
    {
        cout << "Post ID: " << post.postid << ", Content: " << post.content << ", Timestamp: " << post.timestamp << endl;
    }

    smm.unfollowUser(aliceId, charlieId); // Alice unfollows Charlie

    // Get updated feed for Alice
    feed = smm.getFeed(aliceId);
    cout << "\nUpdated Feed for Alice after unfollowing Charlie:" << endl;
    for (const Post &post : feed)
    {
        cout << "Post ID: " << post.postid << ", Content: " << post.content << ", Timestamp: " << post.timestamp << endl;
    }

    return 0;
}