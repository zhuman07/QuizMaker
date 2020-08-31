#include "Question.h"

Question::Question()
{
	cout << "Question Constructor" << endl;
}

Question::~Question()
{
	cout << "Question Destructor" << endl;
}

void Question::setDescription(const std::string description) {
	m_description = description;
}

void Question::setAnwer(const std::string answer) {
	m_answer = answer;
}

const std::string& Question::getDescription() const
{
	return m_description;
}

const std::string& Question::getAnswer() const
{
	return m_answer;
}

bool Question::isRight(const string& user_answer)
{
	return user_answer == m_answer;
}

const std::string Question::toString() const
{
	std::string str = "Question description: \n\t";
	return str;
}

/*std::ostream& operator<< (std::ostream& out, const Question& question)
{
	out << "Desscription: " << question.m_description << endl << "Answer: " << question.m_answer << endl;
	return out;
}*/