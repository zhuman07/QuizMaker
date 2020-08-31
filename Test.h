#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <assert.h>
#include "Question.h"

class Question;

using namespace std;

class Test :
	public Question
{
private:
	map<char, string> m_options;
	int m_num_of_options;
	char* m_labels;
public:
	Test();
	//Test(int num_of_options);
	~Test() override;
	void setNumOfOptions(int num_of_options);
	void setOptions(const vector<string> options);
	const std::string& getOptionAt(char index) const;
	virtual bool isRight(const string& user_answer) override final;

	virtual const std::string toString() const;
	//friend std::ostream& operator<< (std::ostream& out, const Test& test);
};

