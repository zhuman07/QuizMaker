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

class Question;

using namespace std;

class Quiz
{
private:
	std::string m_name;
	std::vector<shared_ptr<Question>> m_questions;

public:
	void setName(const std::string& name);
	const std::string& getName() const;

	void addQuestion(shared_ptr<Question> question);

	void start();
	static Quiz& loadFromFile(const std::string& file_name);
};

