#include <iostream>
using namespace std;

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
	// TODO: �ڴ˴����� return ���
}

int main()
{
	Test<float> t(6.8);
	Test<> a;

	cout << t.getA();
	return 0;
}


