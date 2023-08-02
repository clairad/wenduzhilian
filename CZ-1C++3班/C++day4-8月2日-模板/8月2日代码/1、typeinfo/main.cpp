#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T1, typename T2>
bool test(T1 a, T2 b)
{
	return typeid(a) == typeid(b);
}

int main()
{
	int a;
	char b;
	a = b = 0;
	cout << typeid(b).name();
	
	return 0;
}