#include "heap.h"

int cmp(HPDataType a, HPDataType b)
{
	return a < b;
}

void adjustDown(Vector *vt, int pos)
{
	int flag = 0;
	int n = pos;
	HPDataType tmp;
	while (2 * n + 1 < vt->size)
	{
		if (2 * n + 2 < vt->size && 
			cmp(vt->array[2 * n + 2], vt->array[2 * n + 1]))
		{
			flag = 1;
		}

		if (cmp(vt->array[2 * n + 1 + flag], vt->array[n]))
		{
			tmp = vt->array[n];
			vt->array[n] = vt->array[2 * n + 1 + flag];
			vt->array[2 * n + 1 + flag] = tmp;
		}
		else
		{
			break;
		}
		n = 2 * n + 1 + flag;
		flag = 0;
	}
}

void adjustUp(Vector* vt)
{
	int n = vt->size - 1;
	HPDataType tmp;
	while (n > 0)
	{
		if (cmp(vt->array[n], vt->array[(n - 1) / 2]))
		{
			tmp = vt->array[n];
			vt->array[n] = vt->array[(n - 1) / 2];
			vt->array[(n - 1) / 2] = tmp;
		}
		else
		{
			break;
		}
		n = (n - 1) / 2;
	}
}

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	VectorInit(&hp->data, n);
	int i;
	for (i = 0; i < n; i++)
	{
		VectorPushBack(&hp->data, a[i]);
	}

	for (i = n / 2 - 1; i >= 0; i--)
	{
		adjustDown(&hp->data, i);
	}
}

void HeapInitV(Heap* hp, Vector *d)
{
	VectorInit(&hp->data, d->size);
	int i;
	for (i = 0; i < d->size; i++)
	{
		VectorPushBack(&hp->data, d->array[i]);
	}

	for (i = d->size / 2 - 1; i >= 0; i--)
	{
		adjustDown(&hp->data, i);
	}
}

void HeapDestory(Heap* hp)
{
	VectorDestory(&hp->data);
}

void HeapPush(Heap* hp, HPDataType x)
{
	VectorPushBack(&hp->data, x);
	adjustUp(&hp->data);
}

void HeapPop(Heap* hp)
{
	hp->data.array[0] = hp->data.array[hp->data.size - 1];
	VectorPopBack(&hp->data);
	adjustDown(&hp->data, 0);
}

HPDataType HeapTop(Heap* hp)
{
	return hp->data.array[0];
}

int HeapSize(Heap* hp)
{
	return hp->data.size;
}

int HeapEmpty(Heap* hp)
{
	return VectorEmpty(&hp->data);
}

void HeapSort(Vector* pv)
{
	int i;
	for (i = pv->size / 2 - 1; i >= 0; i--)
	{
		adjustDown(pv, i);
	}

	VTDataType tmp;
	int len = pv->size;

	while(pv->size > 1)
	{
		tmp = pv->array[0];
		pv->array[0] = pv->array[pv->size - 1];
		pv->array[pv->size - 1] = tmp;

		pv->size--;
		adjustDown(pv, 0);
	}
	pv->size = len;
}
