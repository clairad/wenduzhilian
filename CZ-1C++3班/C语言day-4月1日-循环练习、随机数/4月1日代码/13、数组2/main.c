#include <stdio.h>

int main()
{
	int a[] = { 7,4,1,8,5,4,1,9,6,2,3,6,9,5,2,3,6,3,3,6,9,8,7,4,1,0,1,5,8,2,0,2,3,6,9,8 };
	printf("%lld", sizeof(a) / sizeof(a[0]));
	return 0;
}
