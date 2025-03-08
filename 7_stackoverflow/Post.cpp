#include <iostream>
#include <string>
#include <vector>
#include "Post.h"

using namespace std;

Post::Post(int userId, string content) : postId(nextPostId++), userId(userId), content(content), votes(0) {}

int Post::getPostId() const { return postId; }
int Post::getUserId() const { return userId; }
string Post::getContent() const { return content; }
int Post::getVotes() const { return votes; }

void Post::upvote() { votes++; }
void Post::downvote() { votes--; }

void Post::displayInfo() const
{
    cout << "Post ID: " << postId << " | Votes: " << votes << "\n";
    cout << content << "\n";
}

int Post::nextPostId = 1;
