#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	int num;

	scanf("%s%d", str, &num);
	
	int tmp = 0;
	int i;
	int len = strlen(str);
	char res[100] = "";
	int pos = 0;
	int zeroFlag = 0;
	for (i = 0; i < len; i++)
	{
		tmp = tmp * 10 + str[i] - '0';
		if (tmp < num)
		{
			if (zeroFlag)
			{
				res[pos] = '0';
				pos++;
			}
		}
		else
		{
			zeroFlag = 1;
			res[pos] = tmp / num + '0';
			pos++;
			tmp %= num;
		}
	}

	puts(res);
	printf("%d", tmp);
	return 0;
}