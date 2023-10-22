#include <iostream>
#include "hash.h"
using namespace std;

int main()
{
	set<int> a;
	pair<set<int>::iterator, bool> ret = a.insert(2);
	cout << a.erase(3);
	return 0;
}