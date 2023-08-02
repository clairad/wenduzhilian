#include <iostream>
#include "mystring.hpp"
using Cpang::String;
using namespace std;

template <typename T>
bool default_cmp(const T& a, const T& b)
{
	return a < b;
}

template <typename T>
void swapArgs(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
void bubbleSort(T* arr, int n, bool (*cmp)(const T&, const T&) = default_cmp)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (cmp(arr[j + 1], arr[j]))
			{
				swapArgs(arr[j], arr[j + 1]);
			}
		}
	}
}

template <typename T>
void adjustDown(T* arr, int size, int n = 0, bool (*cmp)(const T&, const T&) = default_cmp)
{
	int flag = 0;
	while (n < size / 2)
	{
		if (2 * n + 2 < size && cmp(arr[2 * n + 1], arr[2 * n + 2]))
		{
			flag = 1;
		}

		if (cmp(arr[n], arr[2 * n + 1 + flag]))
		{
			swapArgs(arr[n], arr[2 * n + 1 + flag]);
			n = 2 * n + 1 + flag;
		}
		else
		{
			break;
		}
		flag = 0;
	}
}


template <typename T>
void heapSort(T* arr, int n, bool (*cmp)(const T&, const T&) = default_cmp)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		adjustDown(arr, n, i, cmp);
	}

	for (i = n - 1; i > 0; i--)
	{
		swapArgs(arr[0], arr[i]);
		adjustDown(arr, i, 0, cmp);
	}
}

template <typename T>
int binarySearch(T* arr, int n, const T& f)
{
	int mid;
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		mid = left + right >> 1;
		if (arr[mid] < f)
		{
			left = mid + 1;
		}
		else if(arr[mid] > f)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	String arr[9] = {"fnwig", "afnhuvw", "ejicaj", "popqfj", "oshui", "bfquibv", "udhabuf", "zuifqo", "yfuiwf"};
	heapSort(arr, 9);

	int i;
	for (i = 0; i < 9; i++)
	{
		cout << arr[i] << endl;
	}
	cout << typeid(arr).name() << endl << endl;

	cout << binarySearch(arr, 9, String("popqfj"));
	return 0;
}