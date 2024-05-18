#include <iostream>
#include <thread>
using namespace std;
int main()
{
	int n1 = 500;
	int n2 = 600;
	thread t([&](int addNum1, int addNum2) {
		n1 += addNum1;
		n2 += addNum2;
		}, 500, 600);
	cout << t.joinable() << endl;
	t.join();
	cout << t.joinable() << endl;
	std::cout << n1 << ' ' << n2 << std::endl;
	return 0;
}