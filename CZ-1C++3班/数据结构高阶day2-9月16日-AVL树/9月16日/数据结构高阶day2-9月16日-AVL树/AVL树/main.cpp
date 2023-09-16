#include <iostream>
#include "AVLTree.h"
using namespace std;

int main()
{
	Cpang::Set<int> si;

	si.insert(1);
	si.insert(2);
	si.insert(3);
	si.insert(4);
	si.insert(5);
	si.insert(6);
	si.insert(7);

	for (auto& e : si)
	{
		cout << e << ' ' ;
	}
	return 0;
}