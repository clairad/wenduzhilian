#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b)
{
	if (a < 0)
	{
		a = -a;
	}
	int c = a % b;
	while (c)
	{
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

void dealfraction(int* pnum, int* pden)
{
	if (*pnum < 0 && *pden < 0 || *pnum >= 0 && *pden < 0)
	{
		*pnum *= -1;
		*pden *= -1;
	}
}

void fadd(int numA, int denA, int numB, int denB, int* pNumAns, int* pDenAns)
{
	int tmpansNUM = numA * denB + numB * denA;
	int tmpansDen = denA * denB;
	int gc = gcd(tmpansNUM, tmpansDen);
	*pNumAns = tmpansNUM / gc;
	*pDenAns = tmpansDen / gc;
}

void fsub(int numA, int denA, int numB, int denB, int* pNumAns, int* pDenAns)
{
	int tmpansNUM = numA * denB - numB * denA;
	int tmpansDen = denA * denB;
	int gc = gcd(tmpansNUM, tmpansDen);
	*pNumAns = tmpansNUM / gc;
	*pDenAns = tmpansDen / gc;
}

void fmul(int numA, int denA, int numB, int denB, int* pNumAns, int* pDenAns)
{
	int tmpansNUM = numA * numB;
	int tmpansDen = denA * denB;
	int gc = gcd(tmpansNUM, tmpansDen);
	*pNumAns = tmpansNUM / gc;
	*pDenAns = tmpansDen / gc;
}

void fdiv(int numA, int denA, int numB, int denB, int* pNumAns, int* pDenAns)
{
	int tmpansNUM = numA * denB;
	int tmpansDen = denA * numB;
	dealfraction(&tmpansNUM, &tmpansDen);
	int gc = gcd(tmpansNUM, tmpansDen);
	*pNumAns = tmpansNUM / gc;
	*pDenAns = tmpansDen / gc;
}

int fraction(int numA, int denA, int numB, int denB, char ch, int* pNumAns, int* pDenAns)
{
	if (denA == 0 || denB == 0)
	{
		return -1;
	}
	dealfraction(&numA, &denA);
	dealfraction(&numB, &denB);

	switch (ch)
	{
	case '+': fadd(numA, denA, numB, denB, pNumAns, pDenAns); break;
	case '-': fsub(numA, denA, numB, denB, pNumAns, pDenAns); break;
	case '*': fmul(numA, denA, numB, denB, pNumAns, pDenAns); break;
	case '/': 
		if (numB == 0)
		{
			return -1;
		}
		fdiv(numA, denA, numB, denB, pNumAns, pDenAns); break;
	default:;
	}

	return 0;
}

void printFraction(int num, int den)
{
	printf("%d", num);
	if (num == 0 || den == 1)
	{
		return;
	}
	printf("/%d", den);
}

int main()
{
	int num, den;

	fraction(-12, 19, 4, 8, '/', &num, &den);

	printFraction(num, den);
	return 0;
}
