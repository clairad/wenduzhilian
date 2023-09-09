#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
	fraction a(4, 2);
	fraction b(18, 9);

	cout << a * b;
	return 0;
}