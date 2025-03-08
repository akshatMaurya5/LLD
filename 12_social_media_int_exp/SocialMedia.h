#ifndef SOCIALMEDIA_H
#define SOCIALMEDIA_H

#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include "User.h"
#include "Post.h"

class SocialMedia
{
private:
    unordered_map<int, User> users;
    unordered_map<int, set<Post>> userPosts;
    vector<Post> posts;
    int postIdCounter;

public:
    SocialMedia();

    void createUser(int userId, string username);
    void createPost(int userId, string content);
    void deletePost(int userId, int postId);
    void followUser(int followerId, int foloweeId);
    void unfollowUser(int followerId, int foloweeId);
    vector<Post> getFeed(int userId);
    vector<Post> getFeedPaginated(int userId, int page, int pageSize);
    void likePost(int postId);
    void commentPost(int postId, string comment);
};

#endif
