#include <iostream>
using namespace std;

int g_count = 0;
void getSum(int n)
{
	g_count++;
	if (n == 1)
	{
		return;
	}

	int i;
	for (i = 1; i <= n / 2; i++)
	{
		getSum(i);
	}
}

int main()
{
	/*int i;
	for (i = 1; i <= 100; i++)
	{
		g_count = 0;
		getSum(i);
		cout << i << ' ' << g_count << endl;
	}*/
	

	int i;
	int a[1003] = {0, 1};
	int n;
	cin >> n;
	for (i = 2; i <= n; i += 2)
	{
		a[i + 1] = a[i] = a[i - 1] + a[i / 2];
	}
	cout << a[n] << endl;
	getSum(n);
	cout << g_count << endl;
	return 0;
}