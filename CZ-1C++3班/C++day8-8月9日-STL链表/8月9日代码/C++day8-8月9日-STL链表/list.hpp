#pragma once
#include <iostream>

namespace Cpang {

	template<typename T>
	void swapArgs(T& a, T& b)
	{
		T tmp;
		tmp = a;
		a = b;
		b = tmp;
	}

	template <typename T>
	class ListNode
	{
		T _val;
		ListNode<T>* _prev;
		ListNode<T>* _next;
	public:
		ListNode(const T& o = T()) : _val(o)
		{
			_prev = _next = nullptr;
		}

		template <typename T>
		friend class List;
		template <typename T>
		friend class _List_iterator;
		template <typename T>
		friend class _List_reverse_iterator;
	};

	template <typename T>
	class _List_iterator
	{
		ListNode<T>* _ptr;
	public:
		_List_iterator() : _ptr(nullptr) {}
		_List_iterator(ListNode<T>* p) : _ptr(p) {}
		_List_iterator(const _List_iterator<T>& o) : _ptr(o._ptr) {}

		_List_iterator<T>& operator=(const _List_iterator<T>& o)
		{
			_ptr = o._ptr;
			return *this;
		}

		_List_iterator<T> operator++()
		{
			_ptr = _ptr->_next;
			return *this;
		}

		_List_iterator<T> operator++(int)
		{
			_List_iterator<T> tmp = *this;
			_ptr = _ptr->_next;
			return tmp;
		}

		_List_iterator<T> operator--()
		{
			_ptr = _ptr->_prev;
			return *this;
		}

		_List_iterator<T> operator--(int)
		{
			_List_iterator<T> tmp = *this;
			_ptr = _ptr->_prev;
			return tmp;
		}

		T& operator*()
		{
			return _ptr->_val;
		}

		T* operator->()
		{
			return &_ptr->_val;
		}

		bool operator==(const _List_iterator<T>& o) const
		{
			return _ptr == o._ptr;
		}

		bool operator!=(const _List_iterator<T>& o) const
		{
			return _ptr != o._ptr;
		}

		template <typename T>
		friend class List;
	};

	template <typename T>
	class _List_reverse_iterator
	{
		ListNode<T>* _ptr;
	public:
		_List_reverse_iterator() : _ptr(nullptr) {}
		_List_reverse_iterator(ListNode<T>* p) : _ptr(p) {}
		_List_reverse_iterator(const _List_iterator<T>& o) : _ptr(o._ptr) {}

		_List_reverse_iterator<T>& operator=(const _List_reverse_iterator<T>& o)
		{
			_ptr = o._ptr;
			return *this;
		}

		_List_reverse_iterator<T> operator--()
		{
			_ptr = _ptr->_next;
			return *this;
		}

		_List_reverse_iterator<T> operator--(int)
		{
			_List_reverse_iterator<T> tmp = *this;
			_ptr = _ptr->_next;
			return tmp;
		}

		_List_reverse_iterator<T> operator++()
		{
			_ptr = _ptr->_prev;
			return *this;
		}

		_List_reverse_iterator<T> operator++(int)
		{
			_List_reverse_iterator<T> tmp = *this;
			_ptr = _ptr->_prev;
			return tmp;
		}

		T& operator*()
		{
			return _ptr->_val;
		}

		T* operator->()
		{
			return &_ptr->_val;
		}

		bool operator==(const _List_reverse_iterator<T>& o) const
		{
			return _ptr == o._ptr;
		}

		bool operator!=(const _List_reverse_iterator<T>& o) const
		{
			return _ptr != o._ptr;
		}

		template <typename T>
		friend class List;
	};

	template <typename T>
	class List
	{
		ListNode<T>* _head;
		size_t _size;
	public:
		typedef _List_iterator<T> iterator;
		typedef _List_reverse_iterator<T> reverse_iterator;

		List() : _size(0)
		{
			_head = new ListNode<T>();
			_head->_next = _head->_prev = _head;
		}

		List(const List<T>& o) : _size(0)
		{
			_head = new ListNode<T>();
			_head->_next = _head->_prev = _head;
			iterator it;
			for (it = o.begin(); it != o.end(); it++)
			{
				push_back(*it);
			}
		}

		List(iterator s, iterator e) : _size(0)
		{
			_head = new ListNode<T>();
			_head->_next = _head->_prev = _head;
			iterator it;
			for (it = s; it != e; it++)
			{
				push_back(*it);
			}
		}

		List(std::initializer_list<T> li) : _size(0)
		{
			_head = new ListNode<T>();
			_head->_next = _head->_prev = _head;
			typename std::initializer_list<T>::iterator it;
			for (it = li.begin(); it != li.end(); it++)
			{
				push_back(*it);
			}
		}

		~List()
		{
			clear();
			delete _head;
		}

		iterator begin() const
		{
			return _head->_next;
		}

		iterator end() const
		{
			return _head;
		}

		reverse_iterator rbegin() const
		{
			return _head->_prev;
		}

		reverse_iterator rend() const
		{
			return _head;
		}


		List<T>& operator=(const List<T>& o)
		{
			clear();
			iterator it;
			for (it = o.begin(); it != o.end(); it++)
			{
				push_back(*it);
			}

			return *this;
		}

		iterator find(const T& val)
		{
			iterator it;
			for (it = begin(); it != end(); it++)
			{
				if (*it == val)
				{
					return it;
				}
			}
			return end();
		}

		void push_back(const T& val)
		{
			insert(_head->_prev, val);
		}

		void pop_back()
		{
			erase(_head->_prev);
		}

		void push_front(const T& val)
		{
			insert(_head, val);
		}

		void pop_front(const T& val)
		{
			erase(_head->_next);
		}

		iterator insert(iterator pos, const T& val)
		{
			ListNode<T>* cur = new ListNode<T>(val);
			ListNode<T>* p = pos._ptr;
			ListNode<T>* tmp = p->_next;

			p->_next = cur;
			cur->_prev = p;

			cur->_next = tmp;
			tmp->_prev = cur;
			_size++;
			return pos;
		}

		iterator insert(iterator pos, iterator s, iterator e)
		{
			iterator it;
			iterator tmp = pos;
			for (it = s; it != e; it++)
			{
				tmp = insert(tmp, *it);
				tmp++;
			}
			return pos;
		}

		iterator erase(iterator pos)
		{
			ListNode<T>* cur = pos._ptr;
			pos._ptr = pos._ptr->_next;

			cur->_next->_prev = cur->_prev;
			cur->_prev->_next = cur->_next;
			delete cur;
			_size--;
			return pos;
		}

		iterator erase(iterator s, iterator e)
		{
			while (s != e)
			{
				s = erase(s);
			}
			return s;
		}

		void merge(List<T>& o)
		{
			ListNode<T>* self = _head->_next;
			ListNode<T>* other = o._head->_next;
			ListNode<T>* pre, *tmp;

			while (self != _head && other != o._head)
			{
				if (self->_val > other->_val)
				{
					tmp = other->_next;
					pre = self->_prev;

					pre->_next = other;
					other->_prev = pre;
					other->_next = self;
					self->_prev = other;

					other = tmp;
				}
				else
				{
					self = self->_next;
				}
			}

			if (self == _head)
			{
				self = self->_prev;

				self->_next = other;
				other->_prev = self;

				tmp = o._head->_prev;

				tmp->_next = _head;
				_head->_prev = tmp;
			}
			o._head->_next = o._head->_prev = o._head;
			_size += o._size;
			o._size = 0;
		}

		void sort()
		{
			List<T> tl;
			ListNode<T>* cur = _head->_next;
			ListNode<T>* tmp, *tlcur, *tlpre;

			while (cur != _head)
			{
				tmp = cur->_next;
				cur->_next->_prev = cur->_prev;
				cur->_prev->_next = cur->_next;

				for (tlcur = tl._head->_next; tlcur != tl._head; tlcur = tlcur->_next)
				{
					if (tlcur->_val > cur->_val)
					{
						break;
					}
				}
				tlpre = tlcur->_prev;

				cur->_prev = tlpre;
				tlpre->_next = cur;
				cur->_next = tlcur;
				tlcur->_prev = cur;

				cur = tmp;
			}
			tl._size = _size;
			swap(tl);
		}

		void swap(List<T>& o)
		{
			swapArgs(_head, o._head);
			swapArgs(_size, o._size);
		}

		void clear()
		{
			while (_head->_next != _head)
			{
				erase(_head->_next);
			}
		}

		bool empty()
		{
			return _head->_next == _head;
		}

		size_t size()
		{
			return _size;
		}
	};

	
};