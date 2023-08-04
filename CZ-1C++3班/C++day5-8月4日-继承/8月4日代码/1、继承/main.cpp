#include <iostream>
using namespace std;

class Base {
	int a;
public:
	int c;
	Base(int _a) { a = _a; }

	virtual void func()
	{
		cout << "I'm Base" << endl;
	}
	friend class Test;
};

class Test : public Base
{
	int b;
public:
	Test() : Base(0), b(0)
	{
		a = 8;
		c = 1;
	}

	void func()
	{
		cout << "I'm Test" << endl;
	}

	friend void func(Test t);
};

class Grandson : public Test
{
public:
	void func()
	{
		cout << "I'm grandson" << endl;
	}
};

void func(Test t)
{
	//t.a = 8;
	t.b = 9;
	t.c = 10;
}

int main()
{
	Test* pt = new Test;
	Base* pb = new Base;
	Grandson* pg = new Grandson;

	pt->func();
	pb->func();
	pg->func();
	cout << endl;
	Base* pb2 = pt;
	Test* pt2 = pg;
	pb2->func();
	pt2->func();
	return 0;
}