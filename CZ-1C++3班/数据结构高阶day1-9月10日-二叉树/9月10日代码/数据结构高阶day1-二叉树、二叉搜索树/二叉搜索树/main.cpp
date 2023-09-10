#include <iostream>
#include "BSortTree.h"
using namespace std;

int main()
{
	Cpang::Set<int> si;

	si.insert(4);
	si.insert(2);
	si.insert(3);
	si.insert(1);
	si.insert(7);
	si.insert(6);
	si.erase(1);

	for (auto& e : si)
	{
		cout << e << ' ' ;
	}
	return 0;
}