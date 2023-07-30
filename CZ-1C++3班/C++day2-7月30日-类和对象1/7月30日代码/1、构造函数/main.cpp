#include <iostream>
using namespace std;

class Test {
	int a;
public:
	Test() : a(0)
	{
		cout << "默认构造" << endl;
	}
	explicit Test(int n) : a(n)
	{
		cout << "一般构造" << endl;
	}
	Test(Test& o) : a(o.a)
	{
		cout << "拷贝构造" << endl;
	}

	Test& operator()(int n)
	{
		a = n;
		return *this;
	}

	~Test()
	{
		cout << "析构函数" << endl;
	}
};

int main()
{
	Test t1;
	Test t2(6);
	Test t3 = t2(7);
	return 0;
}