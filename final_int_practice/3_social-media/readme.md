# Design Social Media Network System

The system should allow users to follow friends, add posts, and browse their post feed. It should provide the following functionalities:

## Functionalities

- Create Post
- Delete Post
- Get Feed (Latest of the user & their followers)
- Get Feed Paginated
- Follow User
- Unfollow User

## Plan

### Post Class
- postId
- userId
- content
- timestamp

### User Class
- id
- username
- posts
- followers
- following
- createPost()
- deletePost()
- follow()
- unfollow()

### Social Media Manager