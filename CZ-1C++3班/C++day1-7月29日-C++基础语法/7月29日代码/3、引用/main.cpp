#include <iostream>
using namespace std;

int& func(int& a)
{
	a = 5;
	return a;
}

int main()
{
	int a = 8;
	int& b = a;

	cout << b << endl;
	 
	func(a) = 9;
	cout << a << endl;
	return 0;
}