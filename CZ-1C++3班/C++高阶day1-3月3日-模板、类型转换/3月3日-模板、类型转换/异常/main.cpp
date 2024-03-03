#include <iostream>
using namespace std;

class Base {
public:
	void print()
	{
		cout << "BASE" << endl;
	}
};

class Test : public Base{
public:
	void print()
	{
		cout << "TEST" << endl;
	}
};

void func()
{
	//try
	//{
		throw 6;
		cout << "123";
	/* }
	catch (double d)
	{
		cout << "double 异常" << endl;
	}*/
}


int main()
{
	try {
		func();
	}
	catch (int i)
	{
		cout << i << "int 异常";
	}
	catch (float i)
	{
		cout << "float 异常";
	}
	catch (Test i)
	{
		cout << "Test 异常";
	}
	catch (Base i)
	{
		cout << "Base 异常";
	}
	catch (int * pa)
	{
		cout << "堆空间不足";
	}
	catch (...)
	{
		cout << "其他异常";
	}

	cout << "1aaaa";
	return 0;
}