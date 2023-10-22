#pragma once
#include <iostream>
#include <vector>
using std::vector;
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


template <typename K, typename V, typename HF = _hash_func>
class hashTable
{
	vector<pair<K, V> > _val;
	
	primeTable _pos;
	enum _status{
		_EMPTY,
		_EXIST,
		_DELETE
	};
	vector<_status> _sign;
	int _size;

	void checkCapacity()
	{
		vector<pair<K, V> > oldval(_pos.getNext());
		vector<_status> oldsign(oldval.size(), _EMPTY);

		_val.swap(oldval);
		_sign.swap(oldsign);

		int i;
		_size = 0;
		for (i = 0; i < oldsign.size(); i++)
		{
			if (oldsign[i] == _EXIST)
			{
				insert(oldval[i]);
			}
		}
	}
public:
	hashTable() : _size(0)
	{
		_val.resize(_pos.getPrime());
		_sign.resize(_pos.getPrime(), _EMPTY);
	}

	int count(const K& key)
	{
		HF hashfunc;
		size_t pos = hashfunc(key, _val.size());

		while (_sign[pos] != _EMPTY)
		{
			if (_val[pos].first == key)
			{
				return 1;
			}
			pos++;
			pos %= _val.size();
		}
		return 0;
	}

	size_t find(const K& key)
	{
		HF hashfunc;
		size_t pos = hashfunc(key, _val.size());

		while (_sign[pos] != _EMPTY)
		{
			if (_val[pos].first == key)
			{
				return pos;
			}
			pos++;
			pos %= _val.size();
		}
		return -1;
	}

	bool insert(const pair<K, V> &data)
	{
		HF hashfunc;
		if ((double)_size / _val.size() > 0.7)
		{
			checkCapacity();
		}
		size_t pos = hashfunc(data.first, _val.size());

		while (_sign[pos] == _EXIST)
		{
			if (_val[pos].first == data.first)
			{
				return false;
			}
			pos++;
			pos %= _val.size();
		}
		_val[pos] = data;
		_sign[pos] = _EXIST;
		_size++;
		return true;
	}

	bool erase(const K& key)
	{
		int pos = find(key);
		if (pos < 0)
		{
			return false;
		}
		_sign[pos] = _DELETE;
		_size--;
		return true;
	}

	V& operator[](const K& i)
	{
		int pos = find(i);
		if (pos < 0)
		{
			insert(pair<K, V>(i, V()));
			pos = find(i);
		}
		return _val[pos].second;
	}

	size_t capacity()
	{
		return _val.size();
	}

	size_t size()
	{
		return _size;
	}

	size_t empty()
	{
		return _size == 0;
	}

	size_t clear()
	{
		vector<pair<K, V> > oldval(_pos.getPrime());
		vector<_status> oldsign(oldval.size(), _EMPTY);
		_val.swap(oldval);
		_sign.swap(oldsign);
		_size = 0;
	}
};