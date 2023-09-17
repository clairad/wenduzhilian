#include <iostream>
#include "map.h"
#include <map>
using namespace std;

int main()
{
	Cpang::Map<int, int> mii;
	Cpang::Pair<int, int> pii(3, 5);
	//pii.first = 4;
	//pii.second = 6;

	mii.insert(pii);
	pii.first = 4;
	pii.second = 6;
	mii.insert(pii);

	Cpang::Map<int, int>::iterator it = mii.find(3);
	cout << it->second << endl;
	mii[5] = 2;
	mii[3] = 7;
	mii[1] = 11;
	mii[2] = 66;

	for (auto& e : mii)
	{
		cout << e.first << ' ' << e.second << endl;
	}

	return 0;
}