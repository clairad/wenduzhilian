#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, i;
	cin >> n;

	int count = 0;
	int t = 0;
	for (i = n; i; i /= 2)
	{
		count += i % 2;
		t++;
	}

	cout << count + t - 1;
	return 0;
}

int q1()
{
	long long m, n;
	cin >> m >> n;

	long long left = 1;
	long long right = sqrt(m);
	long long mid;

	while (left <= right)
	{
		mid = left + right >> 1;
		
		if (m / mid - mid < n)
		{
			right = mid - 1;
		}
		else if (m / mid - mid > n)
		{
			left = mid + 1;
		}
		else
		{
			cout << mid << ' ' << m / mid << endl;
			return 0;
		}
	}
	return 0;
}