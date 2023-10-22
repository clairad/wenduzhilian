#pragma once

#include <iostream>
#include <vector>
#include <set>
using std::vector;
using std::set;
using std::pair;

class _hash_func
{
public:
	size_t operator()(int n, size_t p)
	{
		return n % p;
	}

	size_t operator()(char* str, size_t p)
	{
		size_t ret = 0;
		int i;
		for (i = 0; str[i]; i++)
		{
			ret = ret * 67 + (str[i] - 'A');
			if (i > 20)
			{
				break;
			}
		}
		return ret % p;
	}
};

class primeTable
{
	size_t pos;
	static const size_t primeList[28];
public:
	primeTable() : pos(0) {}

	size_t getPrime()
	{
		if (pos >= 28)
		{
			pos = 27;
		}
		return primeList[pos];
	}

	size_t getPrime(size_t p)
	{
		if (p >= 28)
		{
			return primeList[27];
		}
		return primeList[p];
	}

	size_t getNext()
	{
		pos++;
		return primeList[pos];
	}
};

size_t const primeTable::primeList[28] =
{
	53ul,         97ul,         193ul,       389ul,       769ul,
	1543ul,       3079ul,       6151ul,      12289ul,     24593ul,
	49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
	1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
	50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};

template<typename T, typename HF = _hash_func>
class unordered_set
{
	vector<set<T> > _val;
	size_t _size;
	primeTable _pos;

	void checkCapacity()
	{
		vector<set<T> > oldval(_pos.getNext());

		_val.swap(oldval);

		int i;
		_size = 0;
		for (i = 0; i < oldval.size(); i++)
		{
			for (auto& e : oldval[i])
			{
				insert(e);
			}
		}
	}
public:
	unordered_set() : _size(0)
	{
		_val.resize(_pos.getPrime());
	}

	bool insert(const T& data)
	{
		HF hashFunc;
		if ((_size == _val.size())
		{
			checkCapacity();
		}
		int pos = hashFunc(data, _val.size());
		pair<set<T>::iterator, bool> ret = _val[pos].insert(data);
		if (ret.second)
		{
			_size++;
		}
		return ret.second;
	}

	bool erase(const T& data)
	{
		HF hashFunc;
		int pos = hashFunc(data, _val.size());
		bool ret = _val[pos].erase(data);
		if (ret)
		{
			_size--;
		}
		return ret;
	}

	int count(const T& data)
	{
		HF hashFunc;
		int pos = hashFunc(data, _val.size());
		return _val[pos].count(data);
	}
};