#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

template<size_t N>
class Test
{
	int arr[N];
};

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

int main()
{
	const int N = 1000;
	bitset<N> bts(0);

	bts.set();
	bts[0] = 0;
	bts[1] = 0;
	int i, j;
	int tmp = sqrt(bts.size());
	for (i = 2; i <= tmp; i++)
	{
		if (bts[i] == 0)
		{
			continue;
		}

		for (j = i + i; j < bts.size(); j += i)
		{
			bts[j] = 0;
		}
	}

	for (i = 2; i < N; i++)
	{
		if (bts[i])
		{
			cout << i << ' ';
		}

		if (isPrime(i))
		{
			cout << i << endl;
		}
	}

	return 0;
}