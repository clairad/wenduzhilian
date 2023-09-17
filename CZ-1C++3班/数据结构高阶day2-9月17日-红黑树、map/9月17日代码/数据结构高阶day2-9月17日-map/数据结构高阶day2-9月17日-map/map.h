#pragma once

namespace Cpang
{
	template <typename K, typename V>
	class Pair
	{
	public:
		K first;
		V second;

		Pair(const K& _f = K(), const V& _s = V()) :
			first(_f), second(_s)
		{}

		bool operator>(const Pair<K, V>& o) const { return first > o.first; }
		bool operator<(const Pair<K, V>& o) const { return first < o.first; }
		bool operator>=(const Pair<K, V>& o) const { return first >= o.first; }
		bool operator<=(const Pair<K, V>& o) const { return first <= o.first; }
		bool operator==(const Pair<K, V>& o) const { return first == o.first; }
		bool operator!=(const Pair<K, V>& o) const { return first != o.first; }
	};

	template <typename K, typename V>
	class MapNode {
		Pair<K, V> data;
		int _bf;
		MapNode<K, V>* lChild;
		MapNode<K, V>* rChild;
		MapNode<K, V>* Parent;
	public:
		MapNode(const Pair<K, V>& o = Pair<K, V>()) :data(o), _bf(0)
		{
			lChild = rChild = Parent = nullptr;
		}

		template <typename T1, typename T2>
		friend class _Map_iterator;
		template <typename T1, typename T2, typename Cmp>
		friend class Map;
	};

	template <typename K, typename V>
	class _Map_iterator
	{
		MapNode<K, V>* _ptr;

		MapNode<K, V>* getNext()
		{
			MapNode<K, V>* ptr = _ptr;
			if (ptr)
			{
				MapNode<K, V>* cur;
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

		MapNode<K, V>* getPrev()
		{
			MapNode<K, V>* ptr = _ptr;
			if (ptr)
			{
				MapNode<K, V>* cur;
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
		_Map_iterator() : _ptr(nullptr) {}
		_Map_iterator(MapNode<K, V>* p) : _ptr(p) {}
		_Map_iterator(const _Map_iterator<K, V>& o) : _ptr(o._ptr) {}

		_Map_iterator<K, V>& operator=(const _Map_iterator<K, V>& o)
		{
			_ptr = o._ptr;
			return *this;
		}

		_Map_iterator<K, V> operator++()
		{
			_ptr = getNext();
			return *this;
		}

		_Map_iterator<K, V> operator++(int)
		{
			_Map_iterator<K, V> tmp = *this;
			_ptr = getNext();
			return tmp;
		}

		_Map_iterator<K, V> operator--()
		{
			_ptr = getPrev();
			return *this;
		}

		_Map_iterator<K, V> operator--(int)
		{
			_Map_iterator<K, V> tmp = *this;
			_ptr = getPrev();
			return tmp;
		}

		Pair<K, V>& operator*()
		{
			return _ptr->data;
		}

		Pair<K, V>* operator->()
		{
			return &_ptr->data;
		}

		bool operator==(const _Map_iterator<K, V>& o) const
		{
			return _ptr == o._ptr;
		}

		bool operator!=(const _Map_iterator<K, V>& o) const
		{
			return _ptr != o._ptr;
		}

		template <typename T1, typename T2, typename Cmp>
		friend class Map;
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

	template <typename K, typename V, typename Cmp = less<Pair<K, V> > >
	class Map {
		MapNode<K, V>* _head;
		size_t _size;

		void deleteOneChildsNode(MapNode<K, V>* cur, MapNode<K, V>* pos)
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

		void MapLeftRight()
		{
			MapNode<K, V>* cur;
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

		void destroy(MapNode<K, V>* cur)
		{
			if (cur)
			{
				destroy(cur->lChild);
				destroy(cur->rChild);
				delete cur;
			}
		}
		
		void lRound(MapNode<K, V>* par)
		{
			MapNode<K, V>* grand = par->Parent;
			MapNode<K, V>* subR = par->rChild;

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

		void rRound(MapNode<K, V>* par)
		{
			MapNode<K, V>* grand = par->Parent;
			MapNode<K, V>* subL = par->lChild;

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
		
		void lrRound(MapNode<K, V>* par)
		{
			MapNode<K, V>* subL = par->lChild;
			MapNode<K, V>* subLR = subL->rChild;

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
		
		void rlRound(MapNode<K, V>* par)
		{
			MapNode<K, V>* subR = par->rChild;
			MapNode<K, V>* subRL = subR->lChild;

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
		typedef _Map_iterator<K, V> iterator;

		Map() : _size(0)
		{
			_head = new MapNode<K, V>;
		}

		~Map()
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

		iterator find(const K& f)
		{
			MapNode<K, V>* cur = _head->Parent;
			Cmp cp;
			Pair<K, V> p(f);

			while (cur)
			{
				if (cp(p, cur->data))
				{
					cur = cur->lChild;
				}
				else if (cp(cur->data, p))
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

		int count(const K& o)
		{
			return find(o) != end();
		}

		V& operator[](const K& i)
		{
			iterator it = find(i);
			if (it != end())
			{
				return it->second;
			}
			else
			{
				return insert(Pair<K, V>(i)).second->second;
			}
		}

		Pair<bool, iterator> insert(const Pair<K, V>& o)
		{
			MapNode<K, V>* cur = _head->Parent;
			MapNode<K, V>* tmp = cur;
			Cmp cp;
			MapNode<K, V>* ret;

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
						return Pair<bool, iterator>(false);
					}
				}
				cur = new MapNode<K, V>(o);
				if (cp(o, tmp->data))
				{
					tmp->lChild = cur;
				}
				else
				{
					tmp->rChild = cur;
				}
				cur->Parent = tmp;

				ret = cur;
				MapNode<K, V>* pre = cur->Parent;

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
						if (pre->_bf == 2)
						{
							if (cur->_bf == 1)
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
							if (cur->_bf == 1)
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
				cur = new MapNode<K, V>(o);
				_head->lChild = _head->rChild = _head->Parent = cur;
				cur->Parent = _head;
				ret = cur;
			}
			_size++;
			MapLeftRight();
			return Pair<bool, iterator>(true, ret);
		}

		bool erase(const K& o)
		{
			iterator it = find(o);
			MapNode<K, V>* cur= it._ptr;

			if (cur != _head)
			{
				if (cur->lChild == nullptr && cur->rChild == nullptr)
				{
					deleteOneChildsNode(cur, nullptr);
				}
				else if (cur->lChild && cur->rChild)
				{
					++it;
					MapNode<K, V>* nxt = it._ptr;
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
				MapLeftRight();
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