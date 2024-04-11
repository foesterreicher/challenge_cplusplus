#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "QuestionAnswerManager.h"

int main() {
    QuestionAnswerManager manager;

    while (true) {
        std::cout << "CGM - Challenge" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Options:" << std::endl;
        std::cout << "1. Ask a specific question" << std::endl;
        std::cout << "2. Add a question and its answers" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            std::cout << "Ask Question: ";
            std::string question;
            std::getline(std::cin, question);
            auto answers = manager.GetAnswers(question);
            for (const auto& answer : answers) {
                std::cout << answer << std::endl;
            }
        } else if (choice == "2") {
            std::cout << "Enter the question and its answers in the format '<question>? \"<answer1>\" \"<answer2>\" ...': ";
            std::string input;
            std::getline(std::cin, input);
            manager.AddQuestion(input);
        } else if (choice == "3") {
            break;
        } else {
            std::cout << "Invalid input. Please enter 1, 2, or 3." << std::endl;
        }
    }

    return 0;
}
