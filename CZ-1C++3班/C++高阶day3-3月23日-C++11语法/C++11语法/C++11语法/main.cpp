#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <string>
using namespace std;

class test
{
	string name;
public:
	explicit test()
	{
		name[0] = 0;
		cout << "test()" << endl;
	}

	test(const char * s)
	{
		name = s;
		cout << "test(const char * s)" << endl;
	}

	test(const test &o)
	{
		cout << "test(const test &o)" << endl;
	}

	test(test&& o)
	{
		cout << "test(test&& o)" << endl;
	}

	~test()
	{
		cout << "~test():" << name << endl;
	}

	void setname(const char* s)
	{
		cout << name << "->" << s << endl;
		name = s;
	}
};

test func(const char * s)
{
	test st(s);
	st.setname("st");
	return st;
}

test&& func(test &a)
{
	return test(a);
}

void func(const int& a)
{
	cout << "const int &" << endl;
}

void func(int&& a)
{
	cout << "int &&" << endl;
}

int main()
{
	const int& x = 6;
	func(6);
	func(x);

	test a;
	a.setname("a");
	test tt(func("a"));
	tt.setname("tt");

	test&& o = func(tt);
	return 0;
}

int q1()
{
	int a;
	auto *i = &a; //不属于RTTI 编译时行为

	int* pa = &a;
	int& o = a;

	decltype(pa) pb; //属于RTTI dynamic_cast  typeid 运行时类型识别
	cout << typeid(pb).name() << endl;

	return 0;
}