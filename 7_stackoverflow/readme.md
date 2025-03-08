# Requirements

1. **User Interactions**
   - Users can post questions, answer questions, and comment on questions and answers.
   - Users can vote on questions and answers.

2. **Question Management**
   - Questions should have tags associated with them.
   - Users can search for questions based on keywords, tags, or user profiles.

3. **Reputation System**
   - The system should assign reputation scores to users based on their activity and the quality of their contributions.

4. **System Performance**
   - The system should handle concurrent access and ensure data consistency.


## IMPORTANT
- Instead of like usual post, we post questions in post.


## My Plan

- **User class**
- **Post class**
- **Questions class** (derived from Post)
- **Answers class** (derived from Post)
- **Comment class**
- **StackOverflow class** (manages users, questions, answers, interactions)