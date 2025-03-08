#include <iostream>
#include <vector>
#include "Stackoverflow.cpp"

int main()
{
    Stackoverflow stackoverflow;

    // Register users
    User *user1 = stackoverflow.registerUser("john_doe", "john@email.com");
    User *user2 = stackoverflow.registerUser("alice_smith", "alice@email.com");
    User *user3 = stackoverflow.registerUser("bob_wilson", "bob@email.com");

    std::cout << "\n🔹 Initial Users Registered:\n";
    stackoverflow.displayUserProfile(user1->getUserId());
    stackoverflow.displayUserProfile(user2->getUserId());
    stackoverflow.displayUserProfile(user3->getUserId());

    // Add a question
    std::vector<std::string> tags = {"c++", "memory-management"};
    Post *question1 = stackoverflow.addQuestion(user1->getUserId(), "How to use smart pointers?", tags);

    std::cout << "\n✅ Question Added Successfully!\n";

    // Add answers
    Post *answer1 = stackoverflow.addAnswer(user2->getUserId(), question1->getPostId(), "Use shared_ptr or unique_ptr!");
    Post *answer2 = stackoverflow.addAnswer(user3->getUserId(), question1->getPostId(), "Use std::make_shared!");

    std::cout << "\n✅ Answers Added Successfully!\n";

    // Add comment on answer
    stackoverflow.addComment(user1->getUserId(), answer1->getPostId(), "Thanks for the help!");

    // Vote on posts
    stackoverflow.votePost(user2->getUserId(), question1->getPostId()); // User2 upvotes question
    stackoverflow.votePost(user3->getUserId(), answer1->getPostId());   // User3 upvotes answer1
    stackoverflow.votePost(user1->getUserId(), answer2->getPostId());   // User1 upvotes answer2

    std::cout << "\n✅ Votes Recorded Successfully!\n";

    // Accept an answer
    stackoverflow.acceptAnswer(user1->getUserId(), answer1->getPostId());

    std::cout << "\n✅ Answer Accepted!\n";

    // Display question with answers
    std::cout << "\n🔹 Displaying Question with Answers:\n";
    stackoverflow.displayQuestion(question1->getPostId());

    // Display user profiles after activity
    std::cout << "\n🔹 User Profiles After Activity:\n";
    stackoverflow.displayUserProfile(user1->getUserId());
    stackoverflow.displayUserProfile(user2->getUserId());
    stackoverflow.displayUserProfile(user3->getUserId());

    // Search for questions
    std::cout << "\n🔎 Searching for 'C++' Questions:\n";
    auto results = stackoverflow.searchQuestions("c++");
    for (const auto &question : results)
    {
        question->displayInfo();
    }

    return 0;
}
// test