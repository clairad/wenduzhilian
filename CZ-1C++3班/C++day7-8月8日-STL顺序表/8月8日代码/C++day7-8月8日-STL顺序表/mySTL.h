#pragma once

namespace Cpang
{
	template <class T>
	class _reverse_iterator
	{
		T* m_ptr;
	public:
		_reverse_iterator() : m_ptr(nullptr) {}
		_reverse_iterator(T* str) : m_ptr(str) {}
		_reverse_iterator(const _reverse_iterator& o) : m_ptr(o.m_ptr) {}

		_reverse_iterator& operator=(const _reverse_iterator& o)
		{
			m_ptr = o.m_ptr;
			return *this;
		}

		//+ - 6���Ƚ� -> ++ -- * [] =
		//-> ++ -- * = 
		_reverse_iterator operator++() //����ǰ��++
		{
			m_ptr--;
			return *this;
		}

		_reverse_iterator operator++(int) //���غ���++
		{
			_reverse_iterator tmp = *this;
			m_ptr--;
			return tmp;
		}

		_reverse_iterator operator--()
		{
			m_ptr++;
			return *this;
		}

		_reverse_iterator operator--(int)
		{
			_reverse_iterator tmp = *this;
			m_ptr++;
			return tmp;
		}

		T operator*()
		{
			return *m_ptr;
		}

		_reverse_iterator operator+(size_t size)
		{
			return _reverse_iterator(m_ptr - size);
		}

		_reverse_iterator operator-(size_t size)
		{
			return _reverse_iterator(m_ptr + size);
		}

		size_t operator-(const _reverse_iterator& o)
		{
			return m_ptr - o.m_ptr;
		}

		T& operator[](int i)
		{
			return m_ptr[-i];
		}

		bool operator<(const _reverse_iterator& o) { return m_ptr > o.m_ptr; }
		bool operator>(const _reverse_iterator& o) { return m_ptr < o.m_ptr; }
		bool operator<=(const _reverse_iterator& o) { return m_ptr >= o.m_ptr; }
		bool operator>=(const _reverse_iterator& o) { return m_ptr <= o.m_ptr; }
		bool operator==(const _reverse_iterator& o) { return m_ptr == o.m_ptr; }
		bool operator!=(const _reverse_iterator& o) { return m_ptr != o.m_ptr; }

		T* operator->()
		{
			return m_ptr;
		}
	};

	template<typename T>
	void swapArgs(T& a, T& b)
	{
		T tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
};