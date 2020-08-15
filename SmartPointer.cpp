#include "SmartPointer.h"

template <typename T>
SmartPointer<T>::SmartPointer(T* ptr)
	: m_ptr(ptr)
{
	cout << "SP 1 construct" << endl;
}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T> &another_ptr)
{
	cout << "SP 2 construct" << endl;
	m_ptr = new T;
	*m_ptr = *another_ptr.m_ptr;
	//another_ptr.m_ptr = nullptr;
}

/*template <typename T>
SmartPointer<T>::SmartPointer(SmartPointer<T> &&another_ptr)
	: m_ptr(another_ptr.m_ptr)
{
	cout << "SP move construct" << endl;
	another_ptr.m_ptr = nullptr;
}*/

template <typename T>
SmartPointer<T>::~SmartPointer()
{
	cout << "SP destruct" << endl;
	delete m_ptr;
}

template <typename T>
T* SmartPointer<T>::operator->() const
{
	return m_ptr;
}

template <typename T>
T& SmartPointer<T>::operator*() const
{
	return *m_ptr;
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& another_ptr)
{
	cout << "SP operator =" << endl;
	if (this == &another_ptr) {
		return *this;
	}
	delete m_ptr;
	m_ptr = new T;
	*m_ptr = *another_ptr.m_ptr;
	//another_ptr.m_ptr = nullptr;
	return *this;
}

/*template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer<T> &&another_ptr)
{
	cout << "SP operator move =" << endl;
	if (this == &another_ptr) {
		return *this;
	}
	delete m_ptr;
	m_ptr = another_ptr.m_ptr;
	another_ptr.m_ptr = nullptr;
	return *this;
}*/

template <typename T>
bool SmartPointer<T>::isNull() const
{
	return m_ptr == nullptr;
}