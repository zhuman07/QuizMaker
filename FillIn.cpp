#include "FillIn.h"

FillIn::FillIn()
{
	std::cout << "FillIn constructor" << endl;
}

FillIn::~FillIn()
{
	std::cout << "FillIn destructor" << endl;
}

const std::string FillIn::toString() const
{
	string str = m_description;
	return str;
}

std::ostream& operator<< (std::ostream& out, const FillIn& fill_in)
{
	out << fill_in.m_description << endl;
	return out;
}

