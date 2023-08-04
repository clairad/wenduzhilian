#include <iostream>
#include "array.hpp"
using namespace std;
/*
template <typename T = int>
class Test
{
	T a;
	T* arr;
public:
	Test(const T& n = T()) : a(n) {}

	T& getA();
};

template<typename T>
T& Test<T>::getA()
{
	return a;
}
*/

bool cdt(const int& n)
{
	return n >= 5 && n <= 8;
}

int main()
{
	Array<int, 10> ai{1,2,3,4,5,6,7,8,9,10};

	ai.insert(5, 11);
	ai.erase(3, 100);
	ai.lRound(2);
	cout << ai << endl;
	cout << count_if((const int *)ai, 10, cdt);
	return 0;
}


