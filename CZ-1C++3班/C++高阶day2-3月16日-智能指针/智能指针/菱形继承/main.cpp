#include <iostream>
using namespace std;

class Base {
	int all;
public:
	virtual void printBase()
	{
		cout << "Base" << endl;
	}
};

//¶àÖØ¼Ì³Ð
class BaseA : virtual public Base {
	int a;
public:
	int getA()
	{
		return a;
	}

	void setA(int i)
	{
		a = i;
	}

	virtual void print()
	{
		cout << "BaseA" << endl;
	}

	void printA()
	{
		cout << "BaseAA" << endl;
	}
};

class BaseB : virtual public Base {
	int b;
public:
	int getB()
	{
		return b;
	}

	void setB(int i)
	{
		b = i;
	}

	virtual void print()
	{
		cout << "BaseB" << endl;
	}

	virtual void printB()
	{
		cout << "BaseBB" << endl;
	}
};

class Test : public BaseA, virtual public BaseB
{
public:
	void print()
	{
		cout << "Test" << endl;
	}

	virtual void next()
	{
		cout << "next" << endl;
	}
};

int main()
{
	Test t;
	t.printBase();
	cout << sizeof(t) << endl;
	return 0;
}
