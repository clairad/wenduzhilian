#include <stdio.h>
#define ARR "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

//n位数乘以m位数结果一定是n+m-1或n+m位 
char *itostr(int res, int n, char *tmp)
{
	int a, b;
	a = res % n;
	b = res / n;
	if(b == 0)
	{
		tmp[1] = 0;
		tmp[0] = ARR[a];
	}
	else
	{
		tmp[1] = ARR[a];
		tmp[0] = ARR[b];
	}
	return tmp;
}

int main()
{
	int n;
	scanf("%d", &n);
	char tmp[3];
	
	int i, j;
	for(i = 1; i < n; i++)
	{
		for(j = 1; j <= i; j++)
		{
			printf("%c*%c=%s ", ARR[i], ARR[j], itostr(i * j, n, tmp));
		}
		putchar('\n');
	}
	
	return 0;
}
