#include <stdio.h>
//1������ 2����Ҫ�Ĳ����ͷ���ֵ 3��ʵ��/�����޸Ĵ���
int reverseNum(int n, int m)
{
	int i, sum = 0;
	for (i = n; i; i /= m)
	{
		sum = sum * m + i % m;
	}
	return sum;
}

int count_step(int m, int n, int times)
{
	int sum;
	int s;
	for (s = 0; s <= times; s++)
	{
		sum = reverseNum(n, m);
		if (sum == n)
		{
			return s;
		}
		n += sum;
	}
	return -1;
}

//�������������ȳ� LIFO(last in first out)
int main()
{
	int  m, n;

	scanf("%d%d", &m, &n);

	int tmp = count_step(m, n, 30);
	if (tmp < 0)
	{
		printf("Impossible");
	}
	else
	{
		printf("STEP=%d", tmp);
	}
	return 0;
}
