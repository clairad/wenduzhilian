#include <iostream>
using namespace std;

class Test
{
public:
	int a;
	int b;
};

Test operator+(const Test& a, const Test& b)
{
	Test res;
	res.a = a.a + b.a;
	res.b = a.b + b.b;
	return res;
}

int main()
{
	Test a = { 1,2 };
	Test b = { 1,2 };
	Test c = a + b;
	cout << c.a << ' ' << c.b;
	return 0;
}