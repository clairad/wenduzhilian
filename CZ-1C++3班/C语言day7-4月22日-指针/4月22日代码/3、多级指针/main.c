#include <stdio.h>

void func(int *pa)
{
	int a = *pa; //绝对不能转接
	a = 8;
}
                                     //入参           出参
void func2(int ***pppa, int **ppb) //拿去用用传本身，帮我改改传地址
{
	*pppa = ppb; //无论在任何时候，子函数的临时变量的地址都是没有意义的
}

int main()
{
	int a = 9;
	int b = 8;
	int* pa = &a;
	int* pb = &b;
	int** ppa = &pa;

	func2(&ppa, &pb);
	printf("%d", **ppa);

	/*int a = 5;
	func(&a);
	printf("%d", a);*/
	return 0;
}
