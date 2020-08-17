#include "SmartPointer.h"

/*template <typename _Ty>
SmartPointer<_Ty>::SmartPointer(_Ty* ptr)
{
	m_ptr = ptr;
	cout << "SP 1 construct" << endl;
}

template <typename _Ty>
SmartPointer<_Ty>::SmartPointer(const SmartPointer &another_ptr)
{
	cout << "SP copy construct" << endl;
	m_ptr = new _Ty;
	*m_ptr = *another_ptr.m_ptr;
}

template <typename T>
SmartPointer<T>::SmartPointer(SmartPointer<T> &&another_ptr)
	: m_ptr(another_ptr.m_ptr)
{
	cout << "SP move construct" << endl;
	another_ptr.m_ptr = nullptr;
}

template <typename _Ty>
SmartPointer<_Ty>::~SmartPointer()
{
	cout << "SP destruct" << endl;
	delete m_ptr;
}

template <typename _Ty>
_Ty* SmartPointer<_Ty>::operator->() const
{
	return m_ptr;
}

template <typename _Ty>
_Ty& SmartPointer<_Ty>::operator*() const
{
	return *m_ptr;
}

template <typename _Ty>
SmartPointer<_Ty>& SmartPointer<_Ty>::operator=(const SmartPointer& another_ptr)
{
	cout << "SP operator =" << endl;
	if (this == &another_ptr) {
		return *this;
	}
	delete m_ptr;
	m_ptr = new _Ty;
	*m_ptr = *another_ptr.m_ptr;
	return *this;
}

template <typename T>
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
}

template <typename _Ty>
bool SmartPointer<_Ty>::isNull() const
{
	return m_ptr == nullptr;
}*/