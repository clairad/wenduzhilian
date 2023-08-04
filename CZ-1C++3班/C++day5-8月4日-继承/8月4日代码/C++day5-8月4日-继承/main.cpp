#include <iostream>
using namespace std;

/*
void* operator new(size_t size)
{
	return malloc(size);
}

void* operator new(size_t size, int a, int b, int c)
{
	cout << a << b << c << endl;
	return malloc(size);
}
*/

int main()
{
	//int* pi = new(6, 7, 8) int;
	char* pch = (char *)malloc(512 * sizeof(char));
	int* pi = new(pch) int;

	delete pi;
	return 0; 
}