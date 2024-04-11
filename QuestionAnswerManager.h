using namespace std;

class QuestionAnswerManager {
public:
    std::unordered_map<std::string, std::vector<std::string>> QuestionAnswers;

    void AddQuestion(const std::string& input) {
        if (input.empty()) return;
        std::istringstream iss(input);
        std::string question, answers;
        std::getline(iss, question, '?');
        std::getline(iss, answers);

        if (question.length() > 255) {
            std::cout << "Question exceeds maximum length of 255 characters." << std::endl;
            return;
        }

        std::vector<std::string> validAnswers;
        std::string answer;
        std::istringstream answerStream(answers);
        while (std::getline(answerStream, answer, '"')) {
            if (!answer.empty()) {
                if (answer.length() > 255) {
                    std::cout << "Answer exceeds maximum length of 255 characters." << std::endl;
                    return;
                }
                std::string trimmedAnswer;
                for (char c : answer) {
                    if (c != ' ') {
                        trimmedAnswer.push_back(c);
                    }
                }
                if (!trimmedAnswer.empty()) {
                    validAnswers.emplace_back(std::move(trimmedAnswer));
                }
            }
        }

        if (validAnswers.empty()) {
            std::cout << "At least one answer is required." << std::endl;
            return;
        }

        if (QuestionAnswers.find(question) == QuestionAnswers.end()) {
            QuestionAnswers[question] = std::move(validAnswers);
            std::cout << "Question and answers added successfully." << std::endl;
        } else {
            std::cout << "Question already exists. Adding answers to existing question." << std::endl;
            QuestionAnswers[question].insert(QuestionAnswers[question].end(), validAnswers.begin(), validAnswers.end());
        }
    }

    std::vector<std::string> GetAnswers(const std::string& question) {
        std::string questionWithoutMark = question;
        size_t pos = questionWithoutMark.find("?");
        if (pos != string::npos) {
            questionWithoutMark.replace(pos, 1, "");
        }
        if (QuestionAnswers.find(questionWithoutMark) != QuestionAnswers.end()) {
            return QuestionAnswers[questionWithoutMark];
        } else {
            return { "The answer to life, universe and everything is 42" };
        }
    }
};
