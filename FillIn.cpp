#include "FillIn.h"

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

