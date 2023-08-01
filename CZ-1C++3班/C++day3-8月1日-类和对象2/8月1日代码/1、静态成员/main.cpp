#include <iostream>
using namespace std;

class Test
{
	int m_b;
public:
	static int m_s_a;
	static void func(Test &o)
	{
		o.m_b = 8;
		m_s_a = 8;
	}
};
int Test::m_s_a = 0;

class Oob
{
	char* str;
	static Oob* t;

	Oob() : str(NULL) {}
	Oob(Oob& o) {}
public:
	static Oob* getObject();
};
Oob* Oob::t = NULL;

Oob* Oob::getObject()
{
	if (t == NULL)
	{
		Oob* t = new Oob;
	}
	
	return t;
}

int main()
{
	Test t1, t2;
	Test::m_s_a = 9;
	t1.m_s_a = 5;
	cout << t2.m_s_a;
	return 0;
}