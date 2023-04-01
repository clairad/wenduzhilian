#include <stdio.h>
#define ARRSIZE 10 //查找替换
#define MAX(a,b)  ((a) > (b) ? (a) : (b))
#define SWAP(a,b,type) {    type tmp;     \
							tmp = a;   \
							a = b;     \
							b = tmp;}
#define DEF(a,b,type) type a##b;
//预编译语句

//C89 C99
//#define XXX1_4
int main()
{
	//int a[ARRSIZE]; //定义时不要在中括号里写变量

	int m, n;
	scanf("%d%d", &m, &n);

	printf("%d\n", 4 + MAX(m, n));
#if 1
	SWAP(m, n, int);
	printf("%d %d", m, n);
#elif 1

#else

#endif

#ifdef DEF
	DEF(a, 1, int);
	a1 = 5;
	printf("%d", a1);
#else
#endif
	return 0;
}
