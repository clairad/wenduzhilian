#pragma once

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

	T& operator[](int i)
	{
		return m_arr[i];
	}

	int size()
	{
		return m_size;
	}

	//insert erase find sort remove round(旋转) reverse  输出流重载
};
