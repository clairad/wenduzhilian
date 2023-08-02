#pragma once
#include <cstring>
#include <iostream>
#define DEF_SIZE 10

namespace Cpang {


class String
{
	char* m_val;
	int m_size;
	int m_capacity;

	void check_capacity()
	{
		if (m_size >= m_capacity)
		{
			int oldcapa = m_capacity;
			while (m_capacity <= m_size)
			{
				m_capacity *= 2;
			}
			char* newval = new char[m_capacity];
			int i;
			for (i = 0; i < oldcapa; i++)
			{
				newval[i] = m_val[i];
			}
			delete[]m_val;
			m_val = newval;
		}
	}

	int Strcmp(const String& o) const
	{
		int i;
		for (i = 0; i < m_size && i < o.m_size; i++)
		{
			if (m_val[i] != o.m_val[i])
			{
				return m_val[i] - o.m_val[i];
			}
		}

		if (i < m_size)
		{
			return m_val[i];
		}
		else if(i < o.m_size)
		{
			return -o.m_val[i];
		}
		return 0;
	}
public:
	String() : m_capacity(DEF_SIZE), m_size(0)
	{
		m_val = new char[m_capacity];
	}

	String(int n, char ch = 0) : m_capacity(n), m_size(n)
	{
		m_val = new char[m_capacity];
		int i;
		for (i = 0; i < m_size; i++)
		{
			m_val[i] = ch;
		}
	}

	String(const char* str) : m_size(strlen(str)), m_capacity(m_size)
	{
		m_val = new char[m_capacity];
		int i;
		for (i = 0; i < m_size; i++)
		{
			m_val[i] = str[i];
		}
	}

	String(const String& o) : m_capacity(o.m_capacity), m_size(o.m_size)
	{
		m_val = new char[m_capacity];
		int i;
		for (i = 0; i < m_size; i++)
		{
			m_val[i] = o.m_val[i];
		}
	}

	~String()
	{
		if (m_val)
		{
			delete[]m_val;
			m_val = NULL;
		}
	}

	int size()
	{
		return m_size;
	}

	int size() const
	{
		return m_size;
	}

	char& operator[](int i)
	{
		return m_val[i];
	}

	char& operator[](int i) const
	{
		return m_val[i];
	}

	void push_back(char ch)
	{
		check_capacity();
		m_val[m_size] = ch;
		m_size++;
	}

	void pop_back()
	{
		m_size--;
	}

	String& operator=(const String& o)
	{
		m_capacity = o.m_capacity;
		m_size = o.m_size;
		delete[]m_val;
		m_val = new char[m_capacity];
		int i;
		for (i = 0; i < m_size; i++)
		{
			m_val[i] = o.m_val[i];
		}
		return *this;
	}

	String& operator+=(const String& o)
	{
		int oldsize = m_size;
		m_size += o.m_size;
		check_capacity();
		int i;
		for (i = 0; i < o.m_size; i++)
		{
			m_val[oldsize + i] = o.m_val[i];
		}
		return *this;
	}

	void insert(int pos, char ch)
	{
		check_capacity();
		int i;
		for (i = size(); i > pos; i--)
		{
			m_val[i] = m_val[i - 1];
		}
		m_val[pos] = ch;
		m_size++;
	}

	void insert(int pos, const char* str)
	{
		int len = strlen(str);
		m_size += len;
		check_capacity();
		int i;
		for (i = size() - 1; i >= pos + len; i--)
		{
			m_val[i] = m_val[i - len];
		}

		for (i = 0; i < len; i++)
		{
			m_val[i + pos] = str[i];
		}
	}

	void erase(int pos)
	{
		int i;
		for (i = pos; i < m_size; i++)
		{
			m_val[i] = m_val[i + 1];
		}
		m_size--;
	}

	bool operator>(const String& o) const { return Strcmp(o) > 0; }
	bool operator<(const String& o) const { return Strcmp(o) < 0; }
	bool operator==(const String& o) const { return Strcmp(o) == 0; }
	bool operator>=(const String& o) const { return Strcmp(o) >= 0; }
	bool operator<=(const String& o) const { return Strcmp(o) <= 0; }
	bool operator!=(const String& o) const { return Strcmp(o) != 0; }

	String operator+(const String &o) const
	{
		String res(*this);
		res += o;
		return res;
	}

	String operator+(const char* str) const
	{
		String res(*this);
		res += String(str);
		return res;
	}

	const char* c_str()
	{
		check_capacity();
		m_val[m_size] = 0;
		return m_val;
	}

	operator const char* ()
	{
		check_capacity();
		m_val[m_size] = 0;
		return m_val;
	}

	int find(char ch, int pos = 0)
	{
		const char* tmp = strchr(c_str() + pos, ch);
		if (tmp)
		{
			return tmp - m_val;
		}
		return -1;
	}

	int find(const char* str, int pos = 0)
	{
		const char* tmp = strstr(c_str() + pos, str);
		if (tmp)
		{
			return tmp - m_val;
		}
		return -1;
	}

	int rfind(char ch, int pos = 0)
	{
		int i;
		for (i = pos - 1; i >= 0; i--)
		{
			if (m_val[i] == ch)
			{
				return i;
			}
		}
		return -1;
	}

	String substr(int pos, int n = -1) const
	{
		if (n < 0)
		{
			n = size() - pos;
		}
		String res(n);
		int i;
		for (i = 0; i < n; i++)
		{
			res.m_val[i] = m_val[pos + i];
		}
		return res;
	}
};

String operator+(const char* str, const String &o)
{
	String res(str);
	res += o;
	return res;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	int i;
	for (i = 0; i < s.size(); i++)
	{
		os << s[i];
	}
	return os;
}


};

