#include <stdio.h>

int caculator(int a, int b, char ch, int *pres)
{
	switch (ch)
	{
	case '+': *pres = a + b; break;
	case '-': *pres = a - b; break;
	case '*': *pres = a * b; break;
	case '/': 
		if (b == 0)
		{
			return -1;
		}
		*pres = a / b; break;
	default: return -1;
	}
	return 0;
}

int weekday(int src, int* pweeks, int* pdays)
{
	if (src < 0 || pweeks == NULL || pdays == NULL)
	{
		return -1;
	}

	*pweeks = src / 7;
	*pdays = src % 7;
	return 0;
}
//空指针 野指针

int main()
{
	int a, b;
	char ch;
	scanf("%d%c%d", &a, &ch, &b);
	
	int res;
	int ret = caculator(a, b, ch, &res);
	if (ret == -1)
	{
		printf("输入有误");
	}
	else
	{
		printf("%d", res);
	}
	return 0;
}