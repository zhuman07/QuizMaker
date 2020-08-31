#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>
#include "Question.h"
#include "Test.h"
#include "FillIn.h"
#include "SmartPointer.h"

using namespace std;

class Quiz
{
private:
	std::string m_name;
	std::vector<SmartPointer<Question>> m_questions;

public:
	void setName(const std::string& name);
	const std::string& getName() const;

	void addQuestion(SmartPointer<Question> question);

	void start();
	static SmartPointer<Quiz> loadFromFile(const std::string& file_name);
};

