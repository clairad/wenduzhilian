#include <iostream>
using namespace std;

class Test
{
	int m_a;
	int m_b;
public:
	Test(int a = 0, int b = 0) : m_a(a), m_b(b)
	{}

	friend ostream& operator<<(ostream& os, Test& t);
	friend istream& operator>>(istream& is, Test& t);
	friend class Test2;
};

istream& operator>>(istream& is, Test& t)
{
	is >> t.m_a >> t.m_b;
	return is;
}

ostream& operator<<(ostream& os, Test& t)
{
	os << t.m_a << ' ' << t.m_b;
	return os;
}

class Test2
{
	int testPlus(Test& o)
	{
		o.m_a++;
		o.m_b++;
	}
};

int main()
{
	Test t, t1;
	cin >> t >> t1;
	cout << t << endl << t1 << endl;
	return 0;
}