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
	Test(int num_of_options);
	~Test() override;
	void setOptions(const vector<string> options);
	const std::string& getOptionAt(char index) const;
	const std::string toString() const final;
	bool isRight(const string& user_answer) final;
	//friend std::ostream& operator<< (std::ostream& out, const Test& test);
};

