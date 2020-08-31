#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Question
{
protected:
	std::string m_description;
	std::string m_answer;

public:
	Question();
	virtual ~Question();
	virtual void setDescription(const std::string description);
	virtual void setAnwer(const std::string answer);
	virtual const std::string& getDescription() const;
	virtual const std::string& getAnswer() const;
	
	virtual bool isRight(const string& user_answer);

	virtual const std::string toString() const;
	//virtual void setOptions(const vector<string> options) {};
	//friend std::ostream& operator<< (std::ostream& out, const Question& question);
};

