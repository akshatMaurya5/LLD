#include "SocialMedia.h"
#include <string>
#include <iostream>
using namespace std;
SocialMedia::SocialMedia() : postIdCounter(1) {}

void SocialMedia::createUser(int userId, std::string username)
{
    // users[userId] = User(userId, username);
    users.emplace(userId, User(userId, username));
}

void SocialMedia::createPost(int userId, string content)
{

    if (users.find(userId) == users.end())
    {
        cout << "User does not exist" << endl;
        return;
    }

    Post newPost = Post(postIdCounter++, userId, content);

    userPosts[userId].insert(newPost);

    cout << "User " << userId << " created a post with id " << newPost.getPostId() << endl;
}

void SocialMedia::deletePost(int userId, int postid)
{
    if (userPosts.find(userId) == userPosts.end())
    {
        cout << "User does not exist" << endl;
        return;
    }

    auto &posts = userPosts[userId];
    auto it = posts.find(Post(postid, userId, ""));
    if (it == posts.end())
    {
        cout << "Post does not exist" << endl;
        return;
    }
    else
    {
        posts.erase(it);
        cout << "Post deleted successfully" << endl;
    }
}

void SocialMedia::followUser(int myId, int toFollowId)
{
    if (users.find(myId) == users.end() || users.find(toFollowId) == users.end())
    {
        cout << "User does not exist" << endl;
        return;
    }

    users[myId].follow(toFollowId);
    users[toFollowId].followers.insert(myId);
}

void SocialMedia::unfollowUser(int myId, int toUnfollowId)
{
    if (users.find(myId) == users.end() || users.find(toUnfollowId) == users.end())
    {
        cout << "User does not exist" << endl;
        return;
    }
    users[myId].unfollow(toUnfollowId);
    users[toUnfollowId].followers.erase(myId);
}

vector<Post> SocialMedia::getFeed(int userId)
{
    if (users.find(userId) == users.end())
    {
        cout << "User does not exist" << endl;
        return vector<Post>();
    }
    vector<Post> feed;

    auto followingOfUser = users[userId].following;

    priority_queue<std::pair<time_t, Post>> pq;

    for (auto followeeId : followingOfUser)
    {
        for (auto post : userPosts[followeeId])
        {
            pq.push({post.timestamp, post});
        }
    }

    while (!pq.empty() && feed.size() < 10)
    {
        feed.push_back(pq.top().second);
        pq.pop();
    }
    return feed;
}

vector<Post> SocialMedia::getFeedPaginated(int userId, int page, int pageSize)
{
    vector<Post> feed = getFeed(userId);
    int start = page * pageSize;
    int end = std::min((int)feed.size(), start + pageSize);
    return std::vector<Post>(feed.begin() + start, feed.begin() + end);
}
void SocialMedia::likePost(int postId)
{
    for (auto &post : posts)
    {
        if (post.id == postId)
        {
            post.likePost();
            cout << "Post liked successfully" << endl;
            return;
        }
    }
    cout << "Post does not exist" << endl;
}
void SocialMedia::commentPost(int postId, string comment)
{
    for (auto &post : posts)
    {
        if (post.id == postId)
        {
            post.addComment(comment);
            cout << "Comment added successfully" << endl;
            return;
        }
    }
    cout << "Post does not exist" << endl;
}
