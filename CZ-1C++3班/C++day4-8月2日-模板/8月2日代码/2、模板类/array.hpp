#pragma once
#include <iostream>
using std::ostream;

template <typename T, int N = 10>
class Array
{
	T m_arr[N];
	int m_size;
public:
	Array() : m_size(N)
	{
		int i;
		for (i = 0; i < m_size; i++)
		{
			m_arr[i] = T();
		}
	}

	Array(std::initializer_list<T> in) : m_size(in.size())
	{
		auto it = in.begin();
		int i;
		for (i = 0; it != in.end(); it++, i++)
		{
			m_arr[i] = *it;
		}
	}

	T& operator[](int i)
	{
		return m_arr[i];
	}

	const T& operator[](int i) const
	{
		return m_arr[i];
	}

	int size() const
	{
		return m_size;
	}

	void insert(int pos, const T& o)
	{
		int i;
		for (i = size() - 1; i > pos; i--)
		{
			m_arr[i] = m_arr[i - 1];
		}
		m_arr[i] = o;
	}

	void erase(int pos, const T& o = T())
	{
		int i;
		for (i = pos; i < size() - 1; i++)
		{
			m_arr[i] = m_arr[i + 1];
		}
		m_arr[i] = o;
	}

	void sort()
	{
		int i, j;
		T tmp;
		for (i = 1; i < size(); i++)
		{
			tmp = m_arr[i];
			for (j = i; j > 0 && tmp < m_arr[j - 1]; j--)
			{
				m_arr[j] = m_arr[j - 1];
			}
			m_arr[j] = tmp;
		}
	}

	int find(const T& f)
	{
		int i;
		for (i = 0; i < size(); i++)
		{
			if (m_arr[i] == f)
			{
				return i;
			}
		}
		return -1;
	}

	void remove(const T& o)
	{
		int pos = find(o);
		if (pos >= 0)
		{
			erase(pos);
		}
	}

	void reverse(int start = 0, int end = N)
	{
		int i = start, j = end - 1;
		T tmp;
		for (; i < j; i++, j--)
		{
			tmp = m_arr[i];
			m_arr[i] = m_arr[j];
			m_arr[j] = tmp;
		}
	}

	void lRound(int n)
	{
		n %= m_size;
		reverse(0, n);
		reverse(n);
		reverse();
	}

	operator const T* ()
	{
		return m_arr;
	}
};

template <typename T, int N>
ostream& operator<<(ostream& os, const Array<T,N>& o)
{
	int i;
	for (i = 0; i < o.size(); i++)
	{
		os << o[i] << ' ';
	}
	return os;
}

template<typename T>
bool condition(const T& o)
{
	return o > 0;
}

template<typename T>
int count_if(const T* o, int n, bool (*con)(const T&) = condition)
{
	int i;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (con(o[i]))
		{
			count++;
		}
	}
	return count;
}