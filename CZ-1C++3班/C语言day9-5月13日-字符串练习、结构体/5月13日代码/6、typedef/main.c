#include <stdio.h>
#include <string.h>

typedef signed int s32;
typedef unsigned int u32;

typedef struct Pos {
	int x;
	int y;
}Point, * pPoint;

typedef int arr_10[10];

typedef int* pint;
//#define pint int *

int main()
{
	Point p = { 2,3 };
	pPoint pp = &p;
	arr_10 s = { 1,2,3,4,5,6,7,8,9,10 };

	int* a, b;
	b = 5;
	a = &b;
	pint c, d;

	//char (*a)[10];

	printf("%d\n", pp->x);

	printf("%d\n", s[6]);

	char* str1 = "china";
	char* str2 = "student";

	strcpy(str2, str1);
	puts(str2);
	return 0;
}
