#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRSIZE 10
#define TOU 10

int main()
{
	int i[5], j;
	char res = 0;
	for (i[0] = 1; i[0] <= 5; i[0]++)
	{
		for (i[1] = 1; i[1] <= 5; i[1]++)
		{
			for (i[2] = 1; i[2] <= 5; i[2]++)
			{
				for (i[3] = 1; i[3] <= 5; i[3]++)
				{
					for (i[4] = 1; i[4] <= 5; i[4]++)
					{
						if ((i[1] == 2) + (i[0] == 3) == 1 &&
							(i[1] == 2) + (i[4] == 4) == 1 &&
							(i[2] == 1) + (i[3] == 2) == 1 &&
							(i[2] == 5) + (i[3] == 3) == 1 &&
							(i[0] == 1) + (i[4] == 4) == 1)
						{
							for (j = 0; j < 5; j++)
							{
								res |= 1 << i[j];
							}

							if(res == 0x3e)
							{ 
								for (j = 0; j < 5; j++)
								{
									printf("%c %d\n", j + 'A', i[j]);
								}
							}
							res = 0;
						}
					}
				}
			}
		}
	}

	return 0;
}

int s_hw2()
{
	int data[200];
	int pos = 1;
	int n;

	scanf("%d", &n);
	data[0] = n;
	while (n > 1)
	{
		if (n % 2)
		{
			n *= 3;
			n++;
		}
		else
		{
			n /= 2;
		}
		data[pos] = n;
		pos++;
	}

	int i;
	for (i = pos - 1; i >= 0; i--)
	{
		printf("%d ", data[i]);
	}
	return 0;
}

int s_hw1()
{
	int src[50];
	int n;

	int num[50] = {0};
	int pos = 0;
	int count[50] = {0};

	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &src[i]);
	}

	int j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < pos; j++)
		{
			if (num[j] == src[i])
			{
				count[j]++;
				break;
			}
		}
		if (j >= pos)
		{
			num[pos] = src[i];
			count[pos]++;
			pos++;
		}
	}

	/*for (i = 0; i < pos; i++)
	{
		printf("%d %d\n", num[i], count[i]);
	}*/

	int max = 0;
	int maxpos = 0;

	for (i = 0; i < pos; i++)
	{
		if (count[i] > max)
		{
			max = count[i];
			maxpos = i;
		}
	}

	if (max > n / 2)
	{
		printf("%d", num[maxpos]);
	}
	else
	{
		printf("-1");
	}
	return 0;
}

int hw3()
{
	int n;

	scanf("%d", &n);
	int nxt = 0x80000000, max = 0x80000000;

	int i;
	int tmp;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		if (tmp > max)
		{
			nxt = max;
			max = tmp;
		}
		else if (tmp > nxt)
		{
			nxt = tmp;
		}
	}

	printf("%d %d", max, nxt);
	return 0;
}

int hw2_b()
{
	srand(time(NULL));
	short res = 0;
	int tmp[25];

	int i;
	for (i = 0; i < 25; i++)
	{
		tmp[i] = rand() % TOU;
		res |= 1 << tmp[i];    //位图  bitset
	}

	for (i = 0; i < 25; i++)
	{
		printf("%d ", tmp[i]);
	}
	putchar('\n');

	if (res == 0x3ff)
	{
		printf("都出现了");
	}
	else
	{
		printf("没有都出现");
	}
	return 0;
}

int hw2_a()
{
	//皆存问题
	srand(time(NULL));
	int a[TOU] = {0};
	int tmp[25];
	int flag = 0;

	int i;
	for (i = 0; i < 25; i++)
	{
		tmp[i] = rand() % TOU;
		a[tmp[i]]++;
	}

	for (i = 0; i < 25; i++)
	{
		printf("%d ", tmp[i]);
	}
	putchar('\n');
	for (i = 0; i < TOU; i++)
	{
		printf("%d ", a[i]);
		if (a[i] == 0)
		{
			flag = 1;
		}
	}

	if (flag)
	{
		printf("没有都出现");
	}
	else
	{
		printf("都出现了");
	}
	return 0;
}

int hw1()
{
	int a[ARRSIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[ARRSIZE] = { 11,12,13,14,15,16,17,18,19,20 };

	int i;
	int tmp;
	for (i = 0; i < ARRSIZE; i++) //一个循环遍历多个数组
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
	return 0;
}
