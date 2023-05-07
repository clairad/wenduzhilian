#include <stdio.h>
#include <ctype.h>

void conutNum(char* str, int* alphaNum, int* numNum)
{
	int i;
	*alphaNum = *numNum = 0;
	for (i = 0; str[i]; i++)
	{
		if (isdigit(str[i]))
		{
			++*numNum;
		}
		else if (isalpha(str[i]))
		{
			++*alphaNum;
		}
	}
}

void mstrcpy(char* dst, char* src)
{
	//while (*dst++ = *src++);
	int i;
	for (i = 0; src[i]; i++)
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
}

int strtoi(char* str)
{
	int sum = 0;
	int i;
	int minusflag = 1;
	if (*str == '-')
	{
		minusflag = -1;
		str++;
	}

	for (i = 0; isdigit(str[i]); i++)
	{
		sum = sum * 10 + str[i] - '0';
	}
	return sum * minusflag;
}

int main()
{
	char str[64];
	scanf("%63s", str);

	int a = 0, b = 0;
	conutNum(str, &a, &b);
	printf("%d %d\n", a, b);

	char str2[64];
	mstrcpy(str2, str);
	puts(str2);
	return 0;
}
