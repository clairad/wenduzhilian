#pragma once
#include "mySTL.h"
#include <iostream>
#define DEFSIZE 15

namespace Cpang
{
	template <typename T>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef _reverse_iterator<T> reverse_iterator;

		Vector()
		{
			_finish = _start = new T[DEFSIZE];
			_end_of_storage = _start + DEFSIZE;
		}

		Vector(const Vector<T>& o)
		{
			_start = new T[o.capacity()];
			_finish = _start + o.size();
			_end_of_storage = _start + o.capacity();
			int i;
			for (i = 0; i < size(); i++)
			{
				_start[i] = o._start[i];
			}
		}

		Vector(size_t n, const T& o = T())
		{
			int cap = get_capacity(n);
			_start = new T[cap];
			_finish = _start  + n;
			_end_of_storage = _start + cap;
			int i;
			for (i = 0; i < size(); i++)
			{
				_start[i] = o;
			}
		}

		Vector(iterator s, iterator e)
		{
			int size = e - s;
			int cap = get_capacity(size);
			_start = new T[cap];
			_finish = _start + size;
			_end_of_storage = _start + cap;
			int i;
			for (i = 0; i < size; i++)
			{
				_start[i] = s[i];
			}
		}

		Vector(std::initializer_list<T> li)
		{
			int cap = get_capacity(li.size());
			_start = new T[cap];
			_finish = _start;
			_end_of_storage = _start + cap;
			for (auto& e : li)
			{
				push_back(e);
			}
			/*int i;
			for (i = 0; i < size(); i++)
			{
				_start[i] = it[i];
			}*/
		}

		~Vector()
		{
			if (_start)
			{
				delete[]_start;
				_start = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		reverse_iterator rbegin()
		{
			return _finish - 1;
		}

		reverse_iterator rend()
		{
			return _start - 1;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		void clear()
		{
			_finish = _start;
		}

		bool empty()
		{
			return _finish == _start;
		}

		void resize(size_t n)
		{
			_finish = _start + n;
			check_capacity();
		}

		void resize(size_t n, const T& o)
		{
			int oldsize = size();
			_finish = _start + n;
			check_capacity();
			int i;
			for (i = oldsize; i < size(); i++)
			{
				_start[i] = o;
			}
		}

		void reserve(size_t n)
		{
			int oldsize = size();
			resize(n);
			_finish = _start + oldsize;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		void push_back(const T& o)
		{
			_finish++;
			check_capacity();
			_finish[-1] = o;
		}

		void pop_back()
		{
			_finish--;
		}

		iterator find(const T& f)
		{
			iterator it;
			for (it = begin(); it != end(); it++)
			{
				if (*it == f)
				{
					return it;
				}
			}
			return nullptr;
		}

		void swap(Vector<T>& o)
		{
			swapArgs(_start, o._start);
			swapArgs(_finish, o._finish);
			swapArgs(_end_of_storage, o._end_of_storage);
		}

		iterator insert(iterator pos, const T& val)
		{
			_finish++;
			int len = pos - _start;
			check_capacity();
			int i = size() - 1;
			for (; i > len; i--)
			{
				_start[i] = _start[i - 1];
			}
			_start[i] = val;
			return _start + len;
		}

		iterator insert(iterator pos, size_t n, const T& val)
		{
			int oldsize = size();
			_finish += n;
			int len = pos - _start;
			check_capacity();
			int i = size() - 1;
			for (; i > oldsize - len; i--)
			{
				_start[i] = _start[i - n];
			}

			for (i = len; i < n + len; i++)
			{
				_start[i] = val;
			}
			
			return _start + len;
		}

		iterator insert(iterator pos, iterator s, iterator e)
		{
			int len = e - s;
			int ipos = pos - _start;
			int ist, ied;
			Vector<T> tmp(s, e);
			_finish += len;
			check_capacity();
			pos = _start + ipos;
			int i;
			for (i = size() - 1; i >= ipos + len; i--)
			{
				_start[i] = _start[i - len];
			}

			for (i = ipos; i < ipos + tmp.size(); i++)
			{
				_start[i] = tmp[i - ipos];
			}
			return pos;
		}

		iterator earse(iterator pos)
		{
			int i;
			for (i = pos - _start; i < size() - 1; i++)
			{
				_start[i] = _start[i + 1];
			}
			_finish--;
			return pos;
		}

		iterator earse(iterator s, iterator e)
		{
			int len = e - s;
			int i;
			for (i = s - _start; i < size() - len; i++)
			{
				_start[i] = _start[i + len];
			}
			_finish -= len;
			return s;
		}

		Vector<T>& operator=(const Vector<T>& o)
		{
			_start = new T[o.capacity()];
			_finish = _start + o.size();
			_end_of_storage = _start + o.capacity();
			int i;
			for (i = 0; i < size(); i++)
			{
				_start[i] = o._start[i];
			}
			return *this;
		}

		T& operator[](int i)
		{
			return _start[i];
		}
	private:
		void check_capacity()
		{
			if (size() >= capacity())
			{
				int s = size();
				int cap = get_capacity(s, capacity());
				T* newsp = new T[cap];
				int i;
				for (i = 0; i < capacity(); i++)
				{
					newsp[i] = _start[i];
				}
				delete _start;
				_start = newsp;
				_finish = _start + s;
				_end_of_storage = _start + cap;
			}
		}

		static size_t get_capacity(size_t size, size_t capa = DEFSIZE)
		{
			while (capa <= size)
			{
				capa *= 2;
			}
			return capa;
		}

	private:
		T* _start;
		T* _finish;
		T* _end_of_storage;
	};


};