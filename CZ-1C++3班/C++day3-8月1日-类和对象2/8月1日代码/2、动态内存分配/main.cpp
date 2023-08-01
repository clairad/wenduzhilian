#include <iostream>
using namespace std;

class Test
{
	int m_a;
	int m_b;
public:
	Test(int a = 0, int b = 0) : m_a(a), m_b(b)
	{
		cout << "我是构造" << endl;
	}
	void print()
	{
		cout << m_a << ' ' << m_b << endl;
	}
	~Test()
	{
		cout << "我是析构" << endl;
	}
};

int main()
{
	int* pa = new int;
	int* parr = new int[10]{1,2,3,4,5,6,7,8,9,10};
	Test* pt = new Test(3, 5);
	pt->print();

	int i;
	for (i = 0; i < 10; i++)
	{
		cout << parr[i] << ' ';
	}

	delete pa;
	delete[]parr;
	delete pt;
	return 0;
}