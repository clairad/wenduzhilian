#include "vector.h"

void VectorInit(Vector* psl, size_t capacity)
{
	psl->capicity = capacity;
	psl->array = (VTDataType*)malloc(psl->capicity * sizeof(VTDataType));
	psl->size = 0;
}

void VectorDestory(Vector* psl)
{
	free(psl->array);
	psl->array = NULL;
	psl->size = 0;
	psl->capicity = 0;
}

void CheckCapacity(Vector* psl)
{
	if (psl->size == psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = (VTDataType*)realloc(psl->array, psl->capicity * sizeof(VTDataType));
	}
}

void VectorPushBack(Vector* psl, VTDataType x)
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}

void VectorPopBack(Vector* psl)
{
	if (VectorEmpty(psl))
	{
		return;
	}
	psl->size--;
}

void VectorPushFront(Vector* psl, VTDataType x)
{
	VectorInsert(psl, 0, x);
}

void VectorPopFront(Vector* psl)
{
	VectorErase(psl, 0);
}

int VectorFind(Vector* psl, VTDataType x)
{
	int i;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void VectorInsert(Vector* psl, size_t pos, VTDataType x)
{
	CheckCapacity(psl);
	int i;
	for (i = psl->size; i > pos; i--)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
	psl->size++;
}

void VectorErase(Vector* psl, size_t pos)
{
	if (VectorEmpty(psl))
	{
		return;
	}
	int i;
	for (i = pos; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void VectorRemove(Vector* psl, VTDataType x)
{
	int ret = VectorFind(psl, x);
	if (ret >= 0)
	{
		VectorErase(psl, ret);
	}
}

void VectorModify(Vector* psl, size_t pos, VTDataType x)
{
	psl->array[pos] = x;
}

void VectorPrint(Vector* psl)
{
	int i;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}

int VectorEmpty(Vector* psl)
{
	return psl->size == 0;
}

void VectorClear(Vector* psl)
{
	psl->size = 0;
}

void VectorSort(Vector* psl, int(*cmp)(VTDataType* a, VTDataType* b))
{
	int i, j;
	VTDataType tmp;
	for (i = 1; i < psl->size; i++)
	{
		tmp = psl->array[i];
		for (j = i; j > 0 && cmp(&tmp, &psl->array[j - 1]); j--)
		{
			psl->array[j] = psl->array[j - 1];
		}
		psl->array[j] = tmp;
	}
}

void VectorSearch(Vector* psl, VTDataType x)
{
	int left = 0;
	int right = psl->size - 1;
	int mid;
	while (left <= right)
	{
		mid = left + right >> 1;
		if (psl->array[mid] < x)
		{
			left = mid + 1;
		}
		else if (psl->array[mid] > x)
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

void VectorRemoveAll(Vector* psl, VTDataType x)
{
	int i, j = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] != x)
		{
			psl->array[j] = psl->array[i];
			j++;
		}
	}
	psl->size = j;
}

void VectorMerge(Vector* src, Vector* val)
{
	int a, b, c;
	a = b = c = 0;
	VTDataType* newsp = (VTDataType*)malloc((src->capicity + val->capicity) * sizeof(VTDataType));

	while (a < src->size && b < val->size)
	{
		if (src->array[a] < val->array[b])
		{
			newsp[c] = src->array[a];
			a++, c++;
		}
		else
		{
			newsp[c] = val->array[b];
			b++, c++;
		}
	}

	while (a < src->size)
	{
		newsp[c] = src->array[a];
		a++, c++;
	}

	while (b < val->size)
	{
		newsp[c] = val->array[b];
		b++, c++;
	}

	free(src->array);
	src->array = newsp;
	src->size += val->size;
	src->capicity += val->capicity;
}

Vector VectorMergeNew(Vector* val1, Vector* val2)
{
	int a, b, c;
	a = b = c = 0;
	VTDataType* newsp = (VTDataType*)malloc((val1->capicity + val2->capicity) * sizeof(VTDataType));

	while (a < val1->size && b < val2->size)
	{
		if (val1->array[a] < val2->array[b])
		{
			newsp[c] = val1->array[a];
			a++, c++;
		}
		else
		{
			newsp[c] = val2->array[b];
			b++, c++;
		}
	}

	while (a < val1->size)
	{
		newsp[c] = val1->array[a];
		a++, c++;
	}

	while (b < val2->size)
	{
		newsp[c] = val2->array[b];
		b++, c++;
	}

	Vector ret;
	ret.size = val1->size + val2->size;
	ret.capicity = val1->capicity + val2->capicity;
	ret.array = newsp;
	return ret;
}
