#include <iostream>
#include <typeinfo>
#include <algorithm>
using namespace std;

template <class T>
void func(T f)
{
	f();
}

int main()
{
	int a = 5, b = 8;
	func([=] {std::cout << a << b << endl; });

	auto fun1 = [=, &a] {a = b + 2; };
	cout << typeid(fun1).name() << endl;
	std::cout << a << b << endl;
	return 0;
}



class cmpint
{
public:
	bool operator()(const int& a, const int& b)
	{
		return a > b;
	}
};

bool funccmpint(const int& a, const int& b)
{
	return a > b;
}

int sortex()
{
	int a[9] = { 1,7,4,8,5,9,6,2,3 };

	sort(a, a + 9, 
		[](const int& a, const int& b)->bool
		{
			return a > b; 
		}
	);

	for (auto& e : a)
	{
		cout << e << ' ';
	}
	return 0;
}