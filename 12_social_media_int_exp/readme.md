# Design Social Media with following functionalities

- Create Post
- Delete Post
- Get Feed (Latest of the user & their followers)
- Get Feed Paginated
- Follow user
- Unfollow user

## Approach:
- **User class** (id, username, followers, following) 
  - Methods: 
    - `follow(user)`
    - `unfollow(user)`
- **Post class** (id, authorId, content, timestamp) 
  - Methods: 
    - `display()`
- **Social Media** 
  - Attributes: 
    - `user`
    - `posts`
    - `userPosts`
  - Methods:
    - `createPost(userId, content)`
    - `deletePost(userId, postId)`
    - `getFeed(userId)`
    - `getFeedPaginated(userId, page, pageSize)`
    - `followUser(followerId, followeeId)`
    - `unfollowUser(followerId, followeeId)`
