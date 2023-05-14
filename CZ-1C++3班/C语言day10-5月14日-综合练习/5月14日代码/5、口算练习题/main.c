#include <stdio.h>

int printCa(int a, int b, char sign)
{
	char res[100];
	int ret;
	switch (sign)
	{
	case 'a': ret = sprintf(res, "%d+%d=%d", a, b, a + b); break;
	case 'b': ret = sprintf(res, "%d-%d=%d", a, b, a - b); break;
	case 'c': ret = sprintf(res, "%d*%d=%d", a, b, a * b); break;
	default:;
	}
	puts(res);
	return ret;
}

int main()
{
	int n;
	char s[32];
	scanf("%d", &n);
	getchar();
	char sign = 0;
	int a, b;

	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%[^\n]%*c", s);
		if (isalpha(s[0]))
		{
			sign = s[0];
			sscanf(s, "%*c%d%d", &a, &b);
			printf("%d\n", printCa(a, b, sign));
		}
		else
		{
			sscanf(s, "%d%d", &a, &b);
			printf("%d\n", printCa(a, b, sign));
		}
	}

	return 0;
}
