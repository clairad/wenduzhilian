#include <stdio.h>

void func(int (*a)[3])
{

}

int main()
{
	int a[3][3];

	func(a);

	int arr[3];
	int (*parr)[3] = &arr;
	printf("%p\n%p\n", arr, parr);
	printf("%p\n%p\n", arr + 1, parr + 1);

	return 0;
}
