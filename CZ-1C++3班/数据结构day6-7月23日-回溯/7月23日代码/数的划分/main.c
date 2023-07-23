#include <stdio.h>

int printRes[20];
int count = 0;
void divideNum(int n, int start)
{
	if (n == 0)
	{
		int i;
		for (i = 0; i < count; i++)
		{
			printf("%d ", printRes[i]);
		}
		printf("\n");
		return;
	}

	int i;
	for (i = start; i > 0; i--)
	{
		printRes[count] = i;
		count++;
		divideNum(n - i, (n - i < i ? n - i: i));
		count--;
	}
}

int main()
{
	divideNum(10, 10);
	return 0;
}
