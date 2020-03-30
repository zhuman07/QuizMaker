#include "Quiz.h"

void Quiz::setName(const std::string& name)
{
	m_name = name;
}

const std::string& Quiz::getName() const
{
	return m_name;
}

void Quiz::addQuestion(shared_ptr<Question> question)
{
	m_questions.push_back(question);
}

void Quiz::start()
{
	std::cout << "Start quiz '" << m_name << "'" << std::endl;
	int correct_answer_count = 0;
	int j = 1;
	for (const shared_ptr<Question> question : m_questions) {
		cout << j << ") " << question->toString() << endl;
		string user_answer;
		while (user_answer.empty()) {
			cout << "Enter your answer" << endl;
			getline(cin, user_answer);
		}
		try {
			if (question->isRight(user_answer)) {
				cout << "Correct!" << endl;
				correct_answer_count++;
			}
			else
			{
				cout << "Incorrect!" << endl;
			}
		}
		catch (exception e) {
			cout << e.what() << endl;
			cout << "Incorrect!" << endl;
		}
		j++;
	}
}

Quiz& Quiz::loadFromFile(const std::string& file_name)
{
	std::ifstream infile(file_name);
	if (!infile) {
		throw new std::exception("File not found");
	}

	static Quiz quiz;

	quiz.setName(file_name);

	std::vector<std::string> array_of_lines;
	string str_line;
	while (getline(infile, str_line)) {
		array_of_lines.push_back(str_line);
	}

	if (array_of_lines.size() < 2) {
		throw new exception("Incorrect content in file");
	}

	vector<vector<string>> collection_of_questions;

	int count_of_questions = 0;
	vector<string> first_question;
	collection_of_questions.push_back(first_question);
	for (const string& item : array_of_lines) {
		if (item == "") {
			count_of_questions++;
			vector<string> tmp_collection;
			collection_of_questions.push_back(tmp_collection);
			continue;
		}

		collection_of_questions[count_of_questions].push_back(item);
	}

	for (const vector<string> &question : collection_of_questions)
	{
		if (question.size() < 2) {
			throw new exception("Incorrect content in file");
		}

		if (question.size() > 2) {
			int num_of_questions = question.size() - 1;
			shared_ptr<Test> test(new Test(num_of_questions));
			test->setDescription(question[0]);
			test->setAnwer(question[1]);
			vector<string> options;
			int incorrect_answers_count = 0;
			for (const string &answer : question)
			{
				if (incorrect_answers_count > 0) {
					options.push_back(answer);
				}
				incorrect_answers_count++;
			}
			random_shuffle(options.begin(), options.end());
			test->setOptions(options);
			quiz.addQuestion(test);
		}
		else 
		{
			shared_ptr<FillIn> fill_in(new FillIn());
			fill_in->setDescription(question[0]);
			fill_in->setAnwer(question[1]);
			quiz.addQuestion(fill_in);
		}
	}

	random_shuffle(quiz.m_questions.begin(), quiz.m_questions.end());

	return quiz;
}