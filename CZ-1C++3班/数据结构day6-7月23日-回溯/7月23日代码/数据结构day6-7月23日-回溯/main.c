#include <stdio.h>
#include <math.h>
int n;
int arr[22];

int isPrime(int n)
{
	int tmp = sqrt(n); 
	int i;
	for (i = 2; i <= tmp; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int primeArr[200000] = {0};
int pi = 0;
int countPrime(int start, int sum, int k)
{
	if (k == 0)
	{
		if (isPrime(sum))
		{
			int i;
			for (i = 0; i < pi; i++)
			{
				if (primeArr[pi] == sum)
				{
					return pi;
				}
			}

			primeArr[pi] = sum;
			pi++;
		}
		return pi;
	}
	int i;
	for (i = start; i < n; i++)
	{
		countPrime(start, sum + arr[i], k - 1);
	}
}

int main()
{
	int k;
	scanf("%d%d", &n, &k);
	countPrime(0, 0, k);
	return 0;
}
