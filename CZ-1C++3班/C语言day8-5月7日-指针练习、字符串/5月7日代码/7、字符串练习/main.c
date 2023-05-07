#include <stdio.h>
#include <string.h>
#include <ctype.h>

//字符串的反复查找模板
//输入一个字符串，寻找指定字符出现的次数
int countChr(const char* src, char f)
{
	int count = 0;
	char* tmp = src;

	tmp = strchr(src, f);
	while (tmp)
	{
		count++;
		tmp = strchr(tmp + 1, f);
	}
	return count;
}

//输入一个字符串，寻找指定子串出现的次数
int countStr(const char* src, const char* f)
{
	int count = 0;
	char* tmp = src;

	int len = strlen(f);
	tmp = strstr(src, f);
	while (tmp)
	{
		count++;
		//tmp = strstr(tmp + 1, f);
		tmp = strstr(tmp + len, f);
	}
	return count;
}

int getNumSign(char* str, int* num, char* sign)
{
	int i = 1;
	num[0] = atoi(str);
	char* tmp = strpbrk(str, "+-*/");
	while (tmp)
	{
		sign[i - 1] = *tmp;
		num[i] = atoi(tmp + 1);
		i++;
		tmp = strpbrk(tmp + 1, "+-*/");
	}
	return i;
}

int caculator(char* str)
{
	int num[100] = { 0 };
	char sign[100] = "";

	int len = getNumSign(str, num, sign);

	int i;
	for (i = 0; i < len - 1; i++)
	{
		if (sign[i] == '*' || sign[i] == '/')
		{
			if(sign[i] == '*')
			{
				num[i + 1] *= num[i];
			}
			else
			{
				num[i + 1] = num[i] / num[i + 1];
			}
			num[i] = 0;
			if (i == 0)
			{
				sign[i] = '+';
			}
			else
			{ 
				sign[i] = sign[i - 1];
			}
		}
	}

	for (i = 0; i < len - 1; i++)
	{
		if (sign[i] == '+')
		{
			num[i + 1] += num[i];
		}
		else
		{
			num[i + 1] = num[i] - num[i + 1];
		}
	}

	return num[i];
}

int getSum(char* str)
{
	int i;
	int sum = 0;
	for (i = 0; str[i]; i++)
	{
		if (isdigit(str[i]))
		{
			sum += str[i] - '0';
		}
	}
	return sum;
}

int main()
{
	/*char str[] = "87-16/8+2*2*6-7+9";

	printf("%d", caculator(str));*/

	/*char str[] = "h4io1nrf98uin2g919hfohioa";

	printf("%d", getSum(str));*/


	//如何读取一段带空格的字符
	char str[100] = "1999-12-31";

	//scanf("%99s", str);
	//fgets(str, 99, stdin);
	/*while (1)
	{ 
		scanf("%99[^\n]%*c", str);
		puts(str);
	}*/

	int y, m, d;
	sscanf(str, "%d-%d-%d", &y, &m, &d);
	sprintf(str, "%x", y);

	puts(str);
	return 0;
}
