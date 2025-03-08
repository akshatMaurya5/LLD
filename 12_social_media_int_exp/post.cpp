#include "post.h"

Post::Post(int postId, int authorId, string content) : id(postId), authorId(authorId), content(content)
{
    timestamp = time(nullptr);
}

void Post::likePost()
{
    likes++;
}

void Post::addComment(string comment)
{
    comments.push_back(comment);
}

int Post::getPostId() const
{
    return id;
}
