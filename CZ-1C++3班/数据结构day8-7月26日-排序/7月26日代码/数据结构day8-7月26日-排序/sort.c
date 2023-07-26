#include "sort.h"
#include <stdlib.h>

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void dealMerge(int* arr, int left, int mid, int right, int* tmp)
{
	int a, b, c;
	a = left;
	b = mid + 1;
	c = left;

	while (a <= mid && b <= right)
	{
		if (arr[a] < arr[b])
		{
			tmp[c] = arr[a];
			a++, c++;
		}
		else
		{
			tmp[c] = arr[b];
			b++, c++;
		}
	}

	while (a <= mid)
	{
		tmp[c] = arr[a];
		a++, c++;
	}

	while (b <= right)
	{
		tmp[c] = arr[b];
		b++, c++;
	}

	int i;
	for (i = left; i <= right; i++)
	{
		arr[i] = tmp[i];
	}
}

void dealMergeSort(int* arr, int left, int right, int* tmp)
{
	if (left == right)
	{
		return;
	}

	int mid = (left + right) / 2;
	dealMergeSort(arr, left, mid, tmp);
	dealMergeSort(arr, mid + 1, right, tmp);

	dealMerge(arr, left, mid, right, tmp);
}

void mergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	dealMergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

void dealQuickSort(int *arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;
	int end = right;
	if (arr[mid] > arr[left]) 
	{
		swap(&arr[mid], &arr[left]);
	}

	if (arr[left] > arr[right])
	{
		swap(&arr[left], &arr[right]);
	}

	if (arr[mid] > arr[left])
	{
		swap(&arr[mid], &arr[left]);
	}

	int pos = left;
	left++;

	while (left < right)
	{
		while (left <= end && arr[left] < arr[pos])
		{
			left++;
		}

		while (right >= pos && arr[right] > arr[pos])
		{
			right--;
		}

		if (left < right)
		{
			swap(arr[left], arr[right]);
		}
	}
	swap(arr[pos], arr[right]);

	dealQuickSort(arr, pos, right - 1);
	dealQuickSort(arr, right + 1, end);
}

void quickSort(int* arr, int n)
{
	dealQuickSort(arr, 0, n - 1);
}


