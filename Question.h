#pragma once
#include <string>
#include <iostream>

using namespace std;

class Question
{
protected:
	std::string m_description;
	std::string m_answer;

public:
	void setDescription(const std::string description);
	void setAnwer(const std::string answer);
	const std::string& getDescription() const;
	const std::string& getAnswer() const;
	virtual const std::string toString() const;
	virtual bool isRight(const string& user_answer);
	friend std::ostream& operator<< (std::ostream& out, const Question& question);
};

