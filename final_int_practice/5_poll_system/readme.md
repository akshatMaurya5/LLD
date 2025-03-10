
### Problem Statement
You are required to design and implement an online polling system. The system should allow users to create, manage, and participate in polls. Each poll consists of a question and multiple options for answers. Users can vote on polls and view the results.

### Requirements
1. Create Polls:
- Users should be able to create a new poll with a question and multiple answer options.
- Each poll must have a unique identifier, a question, a list of options, and a timestamp of creation.

2. Manage Polls:
- Users should be able to update the question or options of an existing poll.
- Users should be able to delete a poll.

3. Vote in Polls:
- Users should be able to cast a vote for one of the options in a poll.
- Each user can only vote once per poll.

4. View Poll Results:
- Users should be able to view the current results of a poll, including the number of votes for each option.

5. Poll Data:
- Store polls, options, and votes in a way that allows efficient retrieval and updates.
- Ensure data integrity and consistency, especially when multiple users are voting simultaneously.

### Implementation Details
- Functions/Methods:
1. createPoll:
- Input: question (string), options (array of strings)
- Output: pollId (string), message (string)
- Example: createPoll("What is your favorite color?", ["Red", "Blue", "Green", "Yellow"]) returns {"pollId": "123", "message": "Poll created successfully."}

2. updatePoll:
- Input: pollId (string), question (string), options (array of strings)
- Output: message (string)
- Example: updatePoll("123", "Updated question?", ["Option1", "Option2"]) returns {"message": "Poll updated successfully."}

3. deletePoll:
- Input: pollId (string)
- Output: message (string)
- Example: deletePoll("123") returns {"message": "Poll deleted successfully."}




- Classes:

- Poll Class:
    - string pollid, string questions, vector<string> options