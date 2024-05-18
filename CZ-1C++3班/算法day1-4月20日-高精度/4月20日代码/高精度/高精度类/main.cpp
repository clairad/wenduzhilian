#include <iostream>
#include "HighAcc.h"
using namespace std;

int main()
{
	int i, n;
	HighAcc ha1("12");
	HighAcc ha2("12244896");

	cout << ha1 << endl << ha2 << endl;
	cout << ha2 / ha1 << endl;
	cout << ha2 % ha1 << endl;
	return 0;
}