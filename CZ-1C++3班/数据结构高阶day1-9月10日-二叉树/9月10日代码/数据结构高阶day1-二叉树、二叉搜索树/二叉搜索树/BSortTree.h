#pragma once

namespace Cpang
{
	template <typename T>
	class SetNode {
		T data;
		SetNode<T>* lChild;
		SetNode<T>* rChild;
		SetNode<T>* Parent;
	public:
		SetNode(const T& o = T()) :data(o)
		{
			lChild = rChild = Parent = nullptr;
		}

		template <typename X>
		friend class _set_iterator;
		template <typename X>
		friend class Set;
	};

	template <typename T>
	class _set_iterator
	{
		SetNode<T>* _ptr;

		SetNode<T>* getNext()
		{
			SetNode<T>* ptr = _ptr;
			if (ptr)
			{
				SetNode<T>* cur;
				if (ptr->rChild)
				{
					for (cur = ptr->rChild; cur->lChild; cur = cur->lChild);
					ptr = cur;
				}
				else
				{
					while (ptr->Parent->Parent != ptr)
					{
						if (ptr == ptr->Parent->lChild)
						{
							ptr = ptr->Parent;
							return ptr;
						}
						else
						{
							ptr = ptr->Parent;
						}
					}
					ptr = ptr->Parent;
				}
			}
			return ptr;
		}

		SetNode<T>* getPrev()
		{
			SetNode<T>* ptr = _ptr;
			if (ptr)
			{
				SetNode<T>* cur;
				if (ptr->lChild)
				{
					for (cur = ptr->lChild; cur->rChild; cur = cur->rChild);
					ptr = cur;
				}
				else
				{
					while (ptr->Parent->Parent != ptr)
					{
						if (ptr == ptr->Parent->rChild)
						{
							ptr = ptr->Parent;
							return ptr;
						}
						else
						{
							ptr = ptr->Parent;
						}
					}
					ptr = ptr->Parent;
				}
			}
			return ptr;
		}

	public:
		_set_iterator() : _ptr(nullptr) {}
		_set_iterator(SetNode<T>* p) : _ptr(p) {}
		_set_iterator(const _set_iterator<T>& o) : _ptr(o._ptr) {}

		_set_iterator<T>& operator=(const _set_iterator<T>& o)
		{
			_ptr = o._ptr;
			return *this;
		}

		_set_iterator<T> operator++()
		{
			_ptr = getNext();
			return *this;
		}

		_set_iterator<T> operator++(int)
		{
			_set_iterator<T> tmp = *this;
			_ptr = getNext();
			return tmp;
		}

		_set_iterator<T> operator--()
		{
			_ptr = getPrev();
			return *this;
		}

		_set_iterator<T> operator--(int)
		{
			_set_iterator<T> tmp = *this;
			_ptr = getPrev();
			return tmp;
		}

		T& operator*()
		{
			return _ptr->data;
		}

		T* operator->()
		{
			return &_ptr->data;
		}

		bool operator==(const _set_iterator<T>& o) const
		{
			return _ptr == o._ptr;
		}

		bool operator!=(const _set_iterator<T>& o) const
		{
			return _ptr != o._ptr;
		}

		template <typename X>
		friend class Set;
	};

	template <typename T>
	class Set {
		SetNode<T>* _head;
		size_t _size;

		typedef _set_iterator<T> iterator;

		void deleteOneChildsNode(SetNode<T>* cur, SetNode<T>* pos)
		{
			if (cur->Parent->lChild == cur)
			{
				cur->Parent->lChild = pos;
			}
			else if(cur->Parent->rChild == cur)
			{
				cur->Parent->rChild = pos;
			}
			else
			{
				cur->Parent->Parent = pos;
			}
		}
	public:
		Set() : _size(0)
		{
			_head = new SetNode<T>;
		}

		iterator begin() const
		{
			return _head->lChild;
		}

		iterator end() const
		{
			return _head;
		}

		iterator find(const T& f)
		{
			SetNode<T>* cur = _head->Parent;

			while (cur)
			{
				if (cur->data > f)
				{
					cur = cur->lChild;
				}
				else if (cur->data < f)
				{
					cur = cur->rChild;
				}
				else
				{
					return cur;
				}
			}
			return end();
		}

		bool insert(const T& o)
		{
			SetNode<T>* cur = _head->Parent;
			SetNode<T>* tmp = cur;

			if (cur)
			{
				while (cur)
				{
					tmp = cur;
					if (cur->data > o)
					{
						cur = cur->lChild;
					}
					else if (cur->data < o)
					{
						cur = cur->rChild;
					}
					else
					{
						return false;
					}
				}
				cur = new SetNode<T>(o);
				if (tmp->data > o)
				{
					tmp->lChild = cur;
				}
				else
				{
					tmp->rChild = cur;
				}
				cur->Parent = tmp;

				if (cur->data < _head->lChild->data)
				{
					_head->lChild = cur;
				}
				else if (cur->data > _head->rChild->data)
				{
					_head->rChild = cur;
				}
			}
			else
			{
				cur = new SetNode<T>(o);
				_head->lChild = _head->rChild = _head->Parent = cur;
				cur->Parent = _head;
			}
			_size++;
			return true;
		}

		bool erase(const T& o)
		{
			iterator it = find(o);
			SetNode<T>* cur= it._ptr;

			if (cur != _head)
			{
				if (cur->lChild == nullptr && cur->rChild == nullptr)
				{
					deleteOneChildsNode(cur, nullptr);
					delete cur;
				}
				else if (cur->lChild && cur->rChild)
				{
					++it;
					SetNode<T>* nxt = it._ptr;
					deleteOneChildsNode(nxt, nxt->rChild);
					nxt->lChild = cur->lChild;
					nxt->rChild = cur->rChild;
					nxt->Parent = cur->Parent;
					if (cur->lChild)
					{
						cur->lChild->Parent = nxt;
					}
					if (cur->rChild)
					{
						cur->rChild->Parent = nxt;
					}
					deleteOneChildsNode(cur, nxt);
					delete cur;
				}
				else if (cur->lChild)
				{
					cur->lChild->Parent = cur->Parent;
					deleteOneChildsNode(cur, cur->lChild);
					delete cur;
				}
				else
				{
					cur->rChild->Parent = cur->Parent;
					deleteOneChildsNode(cur, cur->rChild);
					delete cur;
				}
				_size--;
				return true;
			}
			return false;
		}
	};



};