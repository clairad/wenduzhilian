#include <stdio.h>
#include <string.h>
#define NUMLEN 70

size_t inputNum(char tmp[], char num[])
{
	while (*tmp == '0') //前导0处理
	{
		tmp++;
	}
	int len = strlen(tmp);

	int i;
	for (i = 0; i < len; i++)
	{
		num[len - 1 - i] = tmp[i] - '0';
	}
	return len ? len : 1;
}

void outputNum(char num[], size_t size, int minusFlag)
{
	int i;
	if (minusFlag)
	{
		putchar('-');
	}
	for (i = size - 1; i >= 0; i--)
	{
		printf("%d", num[i]);
	}
}

size_t add(char num1[], size_t size1, char num2[], size_t size2, char ans[])
{
	int len = size1 > size2 ? size1 : size2;
	int i, tmp;

	for (i = 0; i < len; i++)
	{
		tmp = num1[i] + num2[i] + ans[i];
		ans[i] = tmp % 10;
		ans[i + 1] = tmp / 10;
	}

	return len + ans[len];
}

int numCmp(char num1[], size_t size1, char num2[], size_t size2)
{
	if (size1 > size2)
	{
		return 1;
	}
	else if (size1 < size2)
	{
		return -1;
	}
	else
	{
		int i;
		for (i = size1 - 1; i >= 0; i--)
		{
			if (num1[i] > num2[i])
			{
				return 1;
			}
			else if (num1[i] < num2[i])
			{
				return -1;
			}
		}
		return 0;
	}
}

size_t sub(char num1[], size_t size1, char num2[], size_t size2, char ans[], int *minusFlag)
{
	char *sub1 = num1;
	char *sub2 = num2;
	size_t ssize1 = size1;
	size_t ssize2 = size2;
	*minusFlag = 0;

	if (numCmp(num1, size1, num2, size2) < 0)
	{
		sub1 = num2;
		sub2 = num1;

		ssize1 = size2;
		ssize2 = size1;

		*minusFlag = 1;
	}

	int i, tmp;
	for (i = 0; i < ssize1; i++)
	{
		tmp = sub1[i] + 10 - sub2[i] + ans[i];
		ans[i] = tmp % 10;
		ans[i + 1] = tmp / 10 - 1;
	}

	int len = ssize1;
	for (i = ssize1 - 1; i > 0; i--)
	{
		if (ans[i] == 0)
		{
			len--;
		}
		else
		{
			break;
		}
	}
	return len;
}

size_t mul(char num1[], size_t size1, char num2[], size_t size2, char ans[])
{
	if (size1 == 1 && num1[0] == 0 ||
		size2 == 1 && num2[0] == 0)
	{
		ans[0] = 0;
		return 1;
	}

	int i, j, tmp;
	for (i = 0; i < size1; i++)
	{
		for (j = 0; j < size2; j++)
		{
			tmp = num1[i] * num2[j] + ans[i + j];
			ans[i + j] = tmp % 10;
			ans[i + j + 1] += tmp / 10;
		}
	}

	return size1 + size2 - !ans[size1 + size2 - 1];
}

size_t divsub(char sub1[], size_t size1, char sub2[], size_t size2)
{
	int i, tmp;
	char ans[NUMLEN] = { 0 };
	for (i = 0; i < size1; i++)
	{
		tmp = sub1[i] + 10 - sub2[i] + ans[i];
		ans[i] = tmp % 10;
		ans[i + 1] = tmp / 10 - 1;
	}

	memcpy(sub1, ans, size1);
	int count = 0;
	for (i = size1 - 1; i >= 0; i--)
	{
		if (sub1[i] == 0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}

size_t hadiv(char snum1[], size_t size1, char num2[], size_t size2, char ans[])
{
	int i;
	int anslen = 1;
	char num1[NUMLEN] = { 0 };
	memcpy(num1, snum1, size1);
	int count = 0;
	int flag = 0;
	for (i = size1 - 1; i >= 0; i--)
	{
		while (numCmp(num1 + i, size1 - i, num2, size2) >= 0)
		{
			if (flag == 0)
			{
				anslen = i + 1;
				flag = 1;
			}
			size1 -= divsub(num1 + i, size1 - i, num2, size2);
			count++;
		}
		ans[i] = count;
		count = 0;
	}
	return anslen;
}

int main()
{
	char num1[NUMLEN] = { 0 };
	size_t size1;
	char num2[NUMLEN] = { 0 };
	size_t size2;

	char tmp[NUMLEN];
	scanf("%69s", tmp);
	size1 = inputNum(tmp, num1);
	scanf("%69s", tmp);
	size2 = inputNum(tmp, num2);

	char ans[NUMLEN] = { 0 };
	size_t sizeAns = add(num1, size1, num2, size2, ans);
	outputNum(ans, sizeAns, 0);
	putchar('\n');

	memset(ans, 0, sizeof(ans));
	int minusFlag;
	sizeAns = sub(num1, size1, num2, size2, ans, &minusFlag);
	outputNum(ans, sizeAns, minusFlag);

	putchar('\n');
	memset(ans, 0, sizeof(ans));
	sizeAns = mul(num1, size1, num2, size2, ans);
	outputNum(ans, sizeAns, 0);

	putchar('\n');
	memset(ans, 0, sizeof(ans));
	sizeAns = hadiv(num1, size1, num2, size2, ans);
	outputNum(ans, sizeAns, 0);

	return 0;
}