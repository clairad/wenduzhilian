/*#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <string>
using namespace std;

void Fun(int& x) { cout << "lvalue ref" << endl; }
void Fun(int&& x) { cout << "rvalue ref" << endl; }
void Fun(const int& x) { cout << "const lvalue ref" << endl; }
void Fun(const int&& x) { cout << "const rvalue ref" << endl; }
template<typename T>
void PerfectForward(T&& t)
{
	cout << typeid(t).name() << endl;
	Fun(std::forward<T>(t));
}
int main()
{
	PerfectForward(10); // rvalue ref
	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref
	return 0;
}*/

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

	test(const char* s)
	{
		name = s;
		cout << "test(const char * s)" << endl;
	}

	test(const test& o)
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

int main()
{
	test a("a");
	test b(move(a));
	
	return 0;
}
