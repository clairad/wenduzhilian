#include <iostream>
//using namespace std;
//using std::cout;
//using std::endl;

namespace Test {
	int a;
	void test()
	{
		std::cout << "test" << a << std::endl;
	}
};

namespace Test2 {
	int b;
	void test()
	{
		std::cout << "test" << b << std::endl;
	}
};

using namespace Test;
using Test2::b ;
int main()
{
	a = 9;
	b = 10;
	test();
	//cout << "Hello, world!" << endl; //Á÷²Ù×÷ÔËËã·û
	return 0;
}
