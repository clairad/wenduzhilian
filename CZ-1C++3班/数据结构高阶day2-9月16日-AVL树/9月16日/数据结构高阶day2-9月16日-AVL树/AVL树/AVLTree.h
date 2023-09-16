#pragma once

namespace Cpang
{
	template <typename T>
	class SetNode {
		T data;
		int _bf;
		SetNode<T>* lChild;
		SetNode<T>* rChild;
		SetNode<T>* Parent;
	public:
		SetNode(const T& o = T()) :data(o), _bf(0)
		{
			lChild = rChild = Parent = nullptr;
		}

		template <typename X>
		friend class _set_iterator;
		template <typename X, typename Cmp>
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

		template <typename X, typename Cmp>
		friend class Set;
	};

	template <typename T>
	class less
	{
	public:
		bool operator()(const T& a, const T& b)
		{
			return a < b;
		}
	};

	template <typename T>
	class greater
	{
	public:
		bool operator()(const T& a, const T& b)
		{
			return a > b;
		}
	};

	template <typename T, typename Cmp = less<T> >
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

		void setLeftRight()
		{
			SetNode<T>* cur;
			if (_head->Parent == nullptr)
			{
				_head->rChild = _head->lChild = nullptr;
				return;
			}
			for (cur = _head->Parent; cur->lChild; cur = cur->lChild);
			_head->lChild = cur;
			for (cur = _head->Parent; cur->rChild; cur = cur->rChild);
			_head->rChild = cur;
		}

		void destroy(SetNode<T>* cur)
		{
			if (cur)
			{
				destroy(cur->lChild);
				destroy(cur->rChild);
				delete cur;
			}
		}
		
		void lRound(SetNode<T>* par)
		{
			SetNode<T>* grand = par->Parent;
			SetNode<T>* subR = par->rChild;

			subR->Parent = grand;
			if (grand != _head)
			{
				if (par == grand->lChild)
				{
					grand->lChild = subR;
				}
				else
				{
					grand->rChild = subR;
				}
			}
			else
			{
				_head->Parent = subR;
			}

			par->rChild = subR->lChild;
			if (subR->lChild)
			{
				subR->lChild->Parent = par;
			}

			subR->lChild = par;
			par->Parent = subR;

			par->_bf = subR->_bf = 0;
		}

		void rRound(SetNode<T>* par)
		{
			SetNode<T>* grand = par->Parent;
			SetNode<T>* subL = par->lChild;

			subL->Parent = grand;
			if (grand != _head)
			{
				if (par == grand->lChild)
				{
					grand->lChild = subL;
				}
				else
				{
					grand->rChild = subL;
				}
			}
			else
			{
				_head->Parent = subL;
			}

			par->lChild = subL->rChild;
			if (subL->rChild)
			{
				subL->rChild->Parent = par;
			}

			subL->rChild = par;
			par->Parent = subL;

			par->_bf = subL->_bf = 0;
		}
		
		void lrRound(SetNode<T>* par)
		{
			SetNode<T>* subL = par->lChild;
			SetNode<T>* subLR = subL->rChild;

			int tmp = subLR->_bf;
			lRound(subL);
			rRound(par);

			if (tmp == 1)
			{
				subL->_bf = -1;
			}
			else
			{
				par->_bf = 1;
			}
		}
		
		void rlRound(SetNode<T>* par)
		{
			SetNode<T>* subR = par->rChild;
			SetNode<T>* subRL = subR->lChild;

			int tmp = subRL->_bf;
			rRound(subR);
			lRound(par);

			if (tmp == 1)
			{
				par->_bf = -1; 
			}
			else
			{
				subR->_bf = 1;
			}
		}
	public:
		Set() : _size(0)
		{
			_head = new SetNode<T>;
		}

		~Set()
		{
			destroy(_head->Parent);
			delete _head;
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
			Cmp cp;

			while (cur)
			{
				if (cp(f, cur->data))
				{
					cur = cur->lChild;
				}
				else if (cp(cur->data, f))
				{
					cur = cur->rChild;
				}
				else
				{
					return iterator(cur);
				}
			}
			return end();
		}

		int count(const T& o)
		{
			return find(o) != end();
		}

		bool insert(const T& o)
		{
			SetNode<T>* cur = _head->Parent;
			SetNode<T>* tmp = cur;
			Cmp cp;

			if (cur)
			{
				while (cur)
				{
					tmp = cur;
					if (cp(o, cur->data))
					{
						cur = cur->lChild;
					}
					else if (cp(cur->data, o))
					{
						cur = cur->rChild;
					}
					else
					{
						return false;
					}
				}
				cur = new SetNode<T>(o);
				if (cp(o, tmp->data))
				{
					tmp->lChild = cur;
				}
				else
				{
					tmp->rChild = cur;
				}
				cur->Parent = tmp;

				if (cp(cur->data, _head->lChild->data))
				{
					_head->lChild = cur;
				}
				else if (cp(_head->lChild->data, cur->data))
				{
					_head->rChild = cur;
				}

				SetNode<T>* pre = cur->Parent;

				while (pre != _head)
				{
					if (pre->lChild == cur)
					{
						pre->_bf--;
					}
					else
					{
						pre->_bf++;
					}

					if (pre->_bf == 0)
					{
						break;
					}
					else if (pre->_bf == -1 || pre->_bf == 1)
					{
						cur = pre;
						pre = pre->Parent;
					}
					else
					{
						if (pre->_bf = 2)
						{
							if (cur->_bf = 1)
							{
								lRound(pre);
							}
							else
							{
								rlRound(pre);
							}
						}
						else
						{
							if (cur->_bf = 1)
							{
								lrRound(pre);
							}
							else
							{
								rRound(pre);
							}
						}
						break;
					}
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
				}
				else if (cur->lChild)
				{
					cur->lChild->Parent = cur->Parent;
					deleteOneChildsNode(cur, cur->lChild);
				}
				else
				{
					cur->rChild->Parent = cur->Parent;
					deleteOneChildsNode(cur, cur->rChild);
				}
				delete cur;
				setLeftRight();
				_size--;
				return true;
			}
			return false;
		}

		size_t size()
		{
			return _size;
		}

		bool empty()
		{
			return _head->Parent == nullptr;
		}

		void clear()
		{
			destroy(_head->Parent);
			_head->Parent = _head->rChild = _head->lChild = nullptr;
			_size = 0;
		}
	};

};