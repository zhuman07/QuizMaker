#include "Test.h"

/*Test::Test(int num_of_options)
{
	m_num_of_options = num_of_options;
	cout << "Test construct" << endl;
	char first_letter = 'A';
	m_labels = new char[m_num_of_options];
	for (int i = 0; i < m_num_of_options; i++) {
		char next_letter = first_letter + i;
		m_labels[i] = next_letter;
	}
}*/
Test::Test()
	: m_labels(nullptr), m_num_of_options(0)
{
	cout << "Test constructor" << endl;
}

Test::~Test()
{
	cout << "Test destructor" << endl;
	delete[] m_labels;
}

void Test::setNumOfOptions(int num_of_options)
{
	m_num_of_options = num_of_options;
	char first_letter = 'A';
	m_labels = new char[m_num_of_options];
	for (int i = 0; i < m_num_of_options; i++) {
		char next_letter = first_letter + i;
		m_labels[i] = next_letter;
	}
}

void Test::setOptions(const vector<string> options)
{
	for (int i = 0; i < options.size(); i++) {
		m_options.emplace(m_labels[i], options[i]);
	}
}

const std::string& Test::getOptionAt(char index) const
{
	auto el = m_options.find(index);
	if (el != m_options.end()) {
		return el->second;
	}
}

bool Test::isRight(const string& user_answer)
{
	auto el = m_options.find(user_answer[0]);
	if (el == m_options.end()) {
		return false;
	}
	string value = getOptionAt(user_answer[0]);
	return value == m_answer;
}

const std::string Test::toString() const
{
	stringstream str_stream;
	str_stream << m_description << endl << "Answers: " << endl;
	for (const pair<char, string>& option : m_options)
	{
		str_stream << option.first << ") " << option.second << endl;
	}
	string str = str_stream.str();
	return str;
}

/*std::ostream& operator<< (std::ostream& out, const Test& test)
{
	out << test.m_description << endl;
	for (const pair<char, string>& option : test.m_options)
	{
		out << option.first << ") " << option.second << endl;
	}
	return out;
}*/