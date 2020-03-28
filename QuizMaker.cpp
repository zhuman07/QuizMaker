#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Quiz.h"

using namespace std;

int main()
{
	//setlocale(LC_ALL, "Rus");
	std::cout << "Enter your file name to start quiz" << std::endl;

	std::string file_name;
	std::cin >> file_name;

	try {
		Quiz quiz = Quiz::loadFromFile(file_name);
		quiz.start();
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	return 0;
}
