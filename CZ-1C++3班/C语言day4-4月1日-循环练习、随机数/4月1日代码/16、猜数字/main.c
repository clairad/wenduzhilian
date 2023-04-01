#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
	srand(time(NULL));
	rand();
	int src[SIZE];

	int i;
	for (i = 0; i < SIZE; i++)
	{
		src[i] = i;
	}

	int dst[4];
	int r;

	for (i = 0; i < 4; i++)
	{
		r = rand() % SIZE;
		while (src[r] < 0)
		{
			r++;
			r %= SIZE; //������ת����
		}
		dst[i] = src[r];
		src[r] = -1;
	}

	int countA = 0;
	int countB = 0;
	int guess[4];
	int n;
	for (n = 1; n <= 8; n++)
	{
		printf("��%d�β²�:", n);
		for (i = 0; i < 4; i++)
		{
			scanf("%d", &guess[i]);
		}

		int j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (dst[i] == guess[j])
				{
					countB++;
					break;
				}
			}
		}

		for (i = 0; i < 4; i++)
		{
			if (dst[i] == guess[i])
			{
				countA++;
			}
		}

		printf("%dA%dB\n", countA, countB - countA);
		if (countA == 4)
		{
			printf("��ϲ�㣬�¶���\n");
			return 0;
		}
		countA = countB = 0;
	}
	printf("�Բ���û�µ������ǣ�\n");
	for (i = 0; i < 4; i++)
	{
		printf("%d ", dst[i]);
	}
	
	return 0;
}
