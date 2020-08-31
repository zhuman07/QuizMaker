#pragma once
#include <iostream>

using namespace std;

template <typename _Ty>
class SmartPointer
{
private:
	_Ty* m_ptr;

public:
	SmartPointer(_Ty* ptr)
	{
		m_ptr = ptr;
		cout << "SP 1 construct" << endl;
	};

	SmartPointer(const SmartPointer& another_ptr) = delete;
	/*{
		cout << "SP copy construct" << endl;
		m_ptr = new _Ty;
		*m_ptr = *another_ptr.m_ptr;
	};*/
	
	SmartPointer(SmartPointer &&another_ptr) noexcept
	{
		cout << "SP move construct" << endl;
		m_ptr = another_ptr.m_ptr;
		another_ptr.m_ptr = nullptr;
	};

	~SmartPointer()
	{
		cout << "SP destruct" << endl;
		delete m_ptr;
	};

	_Ty* operator->() const
	{
		return m_ptr;
	};

	_Ty& operator*() const
	{
		return *m_ptr;
	};

	SmartPointer& operator=(const SmartPointer& another_ptr) = delete;
	/*{
		cout << "SP operator copy =" << endl;
		if (this == &another_ptr) {
			return *this;
		}
		delete m_ptr;
		m_ptr = new _Ty;
		*m_ptr = *another_ptr.m_ptr;
		return *this;
	};*/

	SmartPointer& operator=(SmartPointer &&another_ptr) noexcept
	{
		cout << "SP operator move =" << endl;
		if (this == &another_ptr) {
			return *this;
		}
		delete m_ptr;
		m_ptr = another_ptr.m_ptr;
		another_ptr.m_ptr = nullptr;
		return *this;
	};

	bool isNull() const
	{
		return m_ptr == nullptr;
	};
};