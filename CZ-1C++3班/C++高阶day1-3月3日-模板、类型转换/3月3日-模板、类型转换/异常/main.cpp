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
		cout << "double �쳣" << endl;
	}*/
}


int main()
{
	try {
		func();
	}
	catch (int i)
	{
		cout << i << "int �쳣";
	}
	catch (float i)
	{
		cout << "float �쳣";
	}
	catch (Test i)
	{
		cout << "Test �쳣";
	}
	catch (Base i)
	{
		cout << "Base �쳣";
	}
	catch (int * pa)
	{
		cout << "�ѿռ䲻��";
	}
	catch (...)
	{
		cout << "�����쳣";
	}

	cout << "1aaaa";
	return 0;
}