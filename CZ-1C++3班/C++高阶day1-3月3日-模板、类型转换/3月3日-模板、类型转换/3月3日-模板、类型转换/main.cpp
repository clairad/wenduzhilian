#include <iostream>
#include "traits.h"
using namespace std;

template <class T>
bool isEqual(T& left, T& right)
{
	return left == right;
}

template <class T>
void swapArgs(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;

	cout << "sawp others" << endl;
}
/*
void swapArgs(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	cout << "sawp int" << endl;
}*/

template <>
void swapArgs<int>(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;

	cout << "sawp others special" << endl;
}


template <class T>
bool isTargetType(T& tmp)
{
	TypeTraits<T> s;
	s.print();
	return TypeTraits<T>::PODType::get();
}

int main()
{
	float tmp;
	cout << isTargetType(tmp) << endl;

	return 0;
}