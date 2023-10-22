#include <iostream>
#include "hash.h"
using namespace std;

int main()
{
	hashTable<int, int> hii;

	hii[505] = 724;
	hii[18756] = 837;
	cout << hii.capacity() << endl;
	hii[401753] = 120;
	hii[9952] = 726;
	hii.erase(401753);
	hii[506] = 1147;
	hii[509] = 1147;

	cout << hii.capacity() << endl;
	cout << hii[505];

	return 0;
}