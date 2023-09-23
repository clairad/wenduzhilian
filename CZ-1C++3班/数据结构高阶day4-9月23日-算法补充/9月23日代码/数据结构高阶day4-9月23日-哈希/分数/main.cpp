#include <iostream>
using namespace std;

int g_count = 0;
void divideNum(int n, int start, int k)
{
	if (k == 1)
	{
		g_count++;
		return;
	}

	int i;
	for (i = start; i <= n / k; i++)
	{
		divideNum(n - i, i, k - 1);
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	int i, j;
	printf("    ");
	for (i = 1; i <= n; i++)
	{
		printf("%3d", i);
	}
	printf("\n----");
	for (i = 1; i <= n; i++)
	{
		printf("---", i);
	}
	putchar(10);
	for (i = 1; i <= k; i++)
	{
		printf("%2d |", i);
		for (j = 1; j <= n; j++)
		{
			g_count = 0;
			divideNum(j, 1, i);
			printf("%3d", g_count);
		}
		cout << endl;
	}
	
	return 0;
}