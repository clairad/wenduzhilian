#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "stack.h"
#include <algorithm>
#include <queue>
#include <deque>
#include <functional>
using namespace std;

//ÈİÆ÷ µü´úÆ÷ Åä½ÓÆ÷ Ëã·¨ ·Âº¯Êı ¿Õ¼äÅäÖÃÆ÷

class Test
{
	int _a;
	int _b;
	int _c;
public:
	Test(int a = 0, int b = 0, int c = 0) :
		_a(a), _b(b), _c(c)
	{}

	friend class TestFunc;
	friend ostream& operator<<(ostream& os, const Test& v);
};

ostream& operator<<(ostream& os, const Test& v)
{
	os << v._a << ' ' << v._b << ' ' << v._c;
	return os;
}

class TestFunc {
public:
	bool operator()(const Test& a, const Test& b)
	{
		return a._a < b._a ||
			a._b < b._b && a._a == b._a ||
			a._c < b._c && a._a == b._a && a._b == b._b;
	}
};

int main()
{
	Cpang::PriorityQueue<Test, vector<Test>, TestFunc> pqi{
		Test(5,2,3),
		Test(7,4,8),
		Test(7,2,1),
		Test(5,2,9),
		Test(3,6,8),
		Test(1,2,3),
	};

	cout << pqi.top() << endl;
	pqi.pop();
	cout << pqi.top() << endl;
	pqi.pop();
	pqi.push(Test(11,8,9));
	cout << pqi.top() << endl;
	pqi.pop();
	cout << pqi.top() << endl;
	pqi.pop();
	cout << pqi.top() << endl;
	pqi.pop();
	cout << pqi.top() << endl;
	pqi.pop();
	return 0;
}

int mystacktest()
{
	Cpang::Stack<int> si;
	si.push(5);
	si.push(9);
	cout << si.top() << endl;
	si.pop();
	cout << si.top() << endl;
	return 0;
}