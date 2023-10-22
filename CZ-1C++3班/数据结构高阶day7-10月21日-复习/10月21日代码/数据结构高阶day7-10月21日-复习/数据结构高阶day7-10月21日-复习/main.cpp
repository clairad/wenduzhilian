#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define PRIMENUM 126
int primeList[PRIMENUM] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701 };

int getSum(int n)
{
	int tmp2 = 1;
	int tmp = 1, sum = 0;
	int sqrn = sqrt(n);
	int count = 0;
	while (n != primeList[count] && count < PRIMENUM)
	{
		tmp = primeList[count];
		if (n % tmp == 0)
		{
			n /= tmp;
			tmp2 *= tmp;
			sum += n + tmp2;
			//cout << n << ' ' << tmp2 << endl;
		}
		else
		{
			count++;
		}
	}

	return sum + 1;
}

int main()
{
	int n;
	cin >> n;
	int i;
	int count = 0;
	for (i = 2; i <= n; i++)
	{
		if (getSum(i) == i)
		{
			count++;
			cout << i << endl;
		}
	}

	cout << count;
	return 0;
}