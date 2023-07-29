#include <iostream>
using namespace std;

void swapArgs(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	//cout << "int" << endl;
}

void swapArgs(float& a, float& b)
{
	float tmp;
	tmp = a;
	a = b;
	b = tmp;
	//cout << "float" << endl;
}
/*
void swapArgs(char& a, char& b)
{
	char tmp;
	tmp = a;
	a = b;
	b = tmp;
	cout << "char" << endl;
}*/
template <class T>
void swapArgs(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
	cout << "template" << endl;
}

inline bool cmp(int a, int b)
{
	return a > b;
}

void bubbleSort(int *arr, int n, bool(*c)(int, int) = cmp)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (c(arr[j], arr[j + 1]))
			{
				swapArgs(arr[j], arr[j + 1]);
			}
		}
	}
}

bool mycmp(int a, int b)
{
	return a < b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	swapArgs(a, b);
	cout << a << ' ' << b << endl;

	int arr[9] = { 8,7,4,1,2,5,9,6,3 };
	bubbleSort(arr, 9, mycmp);

	int i;
	for (i = 0; i < 9; i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}