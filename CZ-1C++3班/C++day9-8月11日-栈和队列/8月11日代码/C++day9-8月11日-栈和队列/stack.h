#pragma once
#include <deque>
#include <vector>
#include <algorithm>
#include <functional>

namespace Cpang {

	template <typename T, typename _type = std::deque<T> >
	class Stack
	{
		_type _val;
	public:
		void push(const T& v)
		{
			_val.push_back(v);
		}

		void pop()
		{
			_val.pop_back();
		}

		T& top()
		{
			return _val.back();
		}

		bool empty()
		{
			return _val.empty();
		}

		size_t size()
		{
			return _val.size();
		}
	};

	template <typename T, typename _type = std::deque<T> >
	class Queue
	{
		_type _val;
	public:
		void push(const T& v)
		{
			_val.push_back(v);
		}

		void pop()
		{
			_val.pop_front();
		}

		T& front()
		{
			return _val.front();
		}

		T& back()
		{
			return _val.back();
		}

		bool empty()
		{
			return _val.empty();
		}

		size_t size()
		{
			return _val.size();
		}
	};

	template <typename T, typename Cmp>
	void pushHeap(T start, T end, Cmp cp = T())
	{
		int size = end - start;
		int n = size - 1;

		while (n > 0)
		{
			if (cp(start[(n - 1) / 2], start[n]))
			{
				std::swap(start[n], start[(n - 1) / 2]);
				n = (n - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

	template <typename T, 
			  typename _type = std::vector<T>,
			  typename cmp = std::less<T> >
	class PriorityQueue
	{
		_type _val;
	public:
		PriorityQueue() {}

		PriorityQueue(typename _type::iterator s, typename _type::iterator e)
		{
			_val.resize(e - s);
			std::copy(s, e, _val.begin());
			std::make_heap(_val.begin(), _val.end(), cmp());
		}

		PriorityQueue(std::initializer_list<T> li)
		{
			_val.resize(li.size());
			std::copy(li.begin(), li.end(), _val.begin());
			std::make_heap(_val.begin(), _val.end(), cmp());
		}

		void push(const T& v)
		{
			_val.push_back(v);
			//std::push_heap(_val.begin(), _val.end(), cmp());
			pushHeap(_val.begin(), _val.end(), cmp());
		}

		void pop()
		{
			std::pop_heap(_val.begin(), _val.end(), cmp());
			_val.pop_back();
		}

		T& top()
		{
			return _val.front();
		}

		bool empty()
		{
			return _val.empty();
		}

		size_t size()
		{
			return _val.size();
		}
	};
};