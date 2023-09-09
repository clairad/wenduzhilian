#include <iostream>
#include "BTree.hpp"
using namespace std;

int main()
{
	int a[] = { 1,2,4,-1,-1,5,8,-1,-1,9,-1,-1,3,6,-1,-1,7,10,-1,-1,-1 };
	Cpang::BTree<int> bt(a, -1);

	bt.printLastOrder();
	cout << endl;
	bt.printLastOrderNR();
	return 0;
}