#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

//map      set
//multimap multiset

//C++11
//unordered_set      unordered_map
//unordered_multiset unordered_multimap

int main()
{
	map<int, int> mis;
	                          //key value
	/*mis.insert(pair<int, string>(1, "abc"));
	mis.insert(pair<int, string>(2, "def"));
	mis.insert(pair<int, string>(3, "ghi"));
	mis.insert(pair<int, string>(2, "ttt"));
	mis[4] = "xyz";
	mis[2] = "ttt";

	mis.erase(1);*/
	//81 978564 20 1 9875 9742014 6 978564 9875 5 6 6 98885 412 22 81
	int tmp;
	int i;
	for (i = 0; i < 16; i++)
	{
		cin >> tmp;
		mis[tmp]++;
	}
	
	for (auto& e : mis)
	{
		cout << e.first << ' ' << e.second << endl;
	}
	return 0;
}

int multisetTest()
{
	multiset<int> msi;

	int i, tmp;
	for (i = 0; i < 10; i++)
	{
		cin >> tmp;
		msi.insert(tmp);
	}
	//msi.find(8);
	cout << msi.count(8) << endl;

	for (auto& e : msi)
	{
		cout << e << ' ';
	}
	return 0;
}


int setTest()
{
	set<int> msi;
	pair<set<int>::iterator, bool> ps;

	int tmp;
	int i;
	for (i = 0; i < 10; i++)
	{
		cin >> tmp;
		ps = msi.insert(tmp);
		if (!ps.second)
		{
			cout << tmp << "²åÈëÊ§°Ü" << endl;
		}
	}
	//pair<set<T>::iterator, bool>
	//8 7 5 4 9 5 7 4 2 8
	//msi.find(8);
	cout << msi.count(8) << endl;

	for (auto& e : msi)
	{
		cout << e << ' ';
	}

	vector<int> vi(msi.size());

	copy(msi.begin(), msi.end(), vi.begin());
	cout << endl;
	for (auto& e : vi)
	{
		cout << e << ' ';
	}
	cout << endl;

	pair<int, int> p(1, 2);

	cout << p.first << ' ' << p.second;
	return 0;
}