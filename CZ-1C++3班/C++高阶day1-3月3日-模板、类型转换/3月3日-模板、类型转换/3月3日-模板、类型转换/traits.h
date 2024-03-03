#pragma once

class TrueType
{
public:
	static bool get();
};

class FalseType
{
public:
	static bool get();
};

template <class T>
class TypeTraits
{
public:
	void print();
	typedef FalseType PODType;
};

/*需要萃取的类型*/
template <>
class TypeTraits<int>
{
public:
	typedef TrueType PODType;
};

template <>
class TypeTraits<char>
{
public:
	typedef TrueType PODType;
};

template <>
class TypeTraits<long>
{
public:
	typedef TrueType PODType;
};

template <>
class TypeTraits<short>
{
public:
	typedef TrueType PODType;
};

template <>
class TypeTraits<long long>
{
	typedef TrueType PODType;
};


