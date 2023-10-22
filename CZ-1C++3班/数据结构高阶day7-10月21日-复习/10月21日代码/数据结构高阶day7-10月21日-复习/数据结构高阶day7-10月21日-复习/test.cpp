#include <iostream>
#include <cmath>
using namespace std;



bool isPrime(int n)
{
	int i;
	int tmp = sqrt(n);
	for (i = 2; i <= tmp; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int test()
{
	int i;
	for (i = 2; i <= 708; i++)
	{
		if (isPrime(i))
		{
			printf("%d, ", i);
		}
	}

	return 0;
}



int answer[4] = { 6, 28, 496, 8128 };