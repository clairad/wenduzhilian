#include <stdio.h>

void func(int *pa)
{
	int a = *pa; //���Բ���ת��
	a = 8;
}
                                     //���           ����
void func2(int ***pppa, int **ppb) //��ȥ���ô��������ҸĸĴ���ַ
{
	*pppa = ppb; //�������κ�ʱ���Ӻ�������ʱ�����ĵ�ַ����û�������
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
