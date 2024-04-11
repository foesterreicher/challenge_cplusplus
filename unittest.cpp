#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include "QuestionAnswerManager.h"

void testAddQuestion() {
    std::cout << " - testAddQuestion" << std::endl;
    QuestionAnswerManager manager;
    manager.AddQuestion("What is your favourite programming language? \"Phyton\" \"C#\" \"C++\"");

    std::vector<std::string> expectedAnswers = {"Phyton", "C#", "C++"};
    std::vector<std::string> actualAnswers = manager.GetAnswers("What is your favourite programming language?");
    assert(actualAnswers == expectedAnswers);

    std::cout << "Actual answers: ";
    for (const auto& answer : actualAnswers) {
        std::cout << answer << " ";
    }
    std::cout << std::endl;
}

void testAddQuestionMaxLengthExceeded() {
    std::cout << " - testAddQuestionMaxLengthExceeded" << std::endl;
    QuestionAnswerManager manager;
    std::string longQuestion(300, 'Q');
    manager.AddQuestion(longQuestion + "? \"Answer\"");

    assert(manager.QuestionAnswers.find(longQuestion) == manager.QuestionAnswers.end());
    std::cout << "Maximum length exceeded message: Question exceeds maximum length of 255 characters." << std::endl;
}

void testAddQuestionNoAnswers() {
    std::cout << " - testAddQuestionNoAnswers" << std::endl;
    QuestionAnswerManager manager;
    manager.AddQuestion("What is the capitol of Austria?");

    assert(manager.QuestionAnswers.find("What is the capitol of Austria?") == manager.QuestionAnswers.end());

    std::cout << "No answers message: At least one answer is required." << std::endl;
}

void testGetAnswers() {
    std::cout << " - testGetAnswers" << std::endl;
    QuestionAnswerManager manager;
    manager.AddQuestion("What is a prime number? \"2\" \"3\" \"5\" \"7\"");

    std::vector<std::string> expectedAnswers = {"2", "3", "5", "7"};
    std::vector<std::string> actualAnswers = manager.GetAnswers("What is a prime number?");
    assert(actualAnswers == expectedAnswers);

    std::cout << "Actual answers: ";
    for (const auto& answer : actualAnswers) {
        std::cout << answer << " ";
    }
    std::cout << std::endl;
}

void testGetAnswersDefault() {
    std::cout << " - testGetAnswersDefault" << std::endl;
    QuestionAnswerManager manager;

    std::vector<std::string> expectedAnswers = {"The answer to life, universe and everything is 42"};
    std::vector<std::string> actualAnswers = manager.GetAnswers("Is the answer to life, universe and everything 42?")
    assert(actualAnswers == expectedAnswers);

    std::cout << "Default answers: The answer to life, universe and everything is 42" << std::endl;
}

int main() {
    testAddQuestion();
    testAddQuestionMaxLengthExceeded();
    testAddQuestionNoAnswers();
    testGetAnswers();
    testGetAnswersDefault();

    std::cout << "All unittests executed successfully." << std::endl;

    return 0;
}
