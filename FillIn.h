#pragma once
#include <iostream>
#include <string>
#include "Question.h"

using namespace std;

class Question;

class FillIn :
	public Question
{
public:
	FillIn();
	~FillIn() override;

	virtual const std::string toString() const;

	//friend std::ostream& operator<< (std::ostream& out, const FillIn& fill_in);
};

