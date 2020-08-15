#pragma once
#include <iostream>
#include "Question.h"
#include "Test.h"
#include "FillIn.h"

using namespace std;

class Question;

template <typename T>
class SmartPointer
{
private:
	T* m_ptr;

public:
	SmartPointer(T* ptr);
	SmartPointer(const SmartPointer<T>& another_ptr);
	//SmartPointer(SmartPointer<T> &&another_ptr);
	~SmartPointer();
	T* operator->() const;
	T& operator*() const;
	SmartPointer<T>& operator=(const SmartPointer<T>& another_ptr);
	//SmartPointer<T>& operator=(SmartPointer<T> &&another_ptr);
	bool isNull() const;
};