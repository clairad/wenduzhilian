#include <iostream>
using namespace std;

class Test {
	int a;
public:
	Test() : a(0)
	{
		cout << "Ĭ�Ϲ���" << endl;
	}
	explicit Test(int n) : a(n)
	{
		cout << "һ�㹹��" << endl;
	}
	Test(Test& o) : a(o.a)
	{
		cout << "��������" << endl;
	}

	Test& operator()(int n)
	{
		a = n;
		return *this;
	}

	~Test()
	{
		cout << "��������" << endl;
	}
};

int main()
{
	Test t1;
	Test t2(6);
	Test t3 = t2(7);
	return 0;
}