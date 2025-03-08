## Poll API/Methods

### Tasks
- **Create poll**
- **Delete poll**
- **Update poll**
- **Vote on a poll**
- **Print the final results of the poll**

The poll object is expected to contain a list of questions. In the update poll method, the user can update a question for a certain poll ID.

### Classes and Methods

#### User Class
- **Attributes**: 
  - `userId`
  - `votedPolls` (map<int, pair<int, int>>) → (pollId → (questionIndex, optionIndex))
- **Methods**: 
  - `voteOnPoll()`

#### Poll Class
- **Attributes**: 
  - `id`
  - `title`
  - `list of questions`
  - `votes` (map<int, map<int, int>>) → questionIndex → optionIndex → voteCount

#### Poll Manager
- **Methods**: 
  - `createPoll()`
  - `updatePoll()`
  - `deletePoll()`
  - `voteOnPoll()`

### Additional Information
- The user class is responsible for managing user-related data and actions.
- The poll manager handles the creation, updating, deletion, and voting processes for polls.