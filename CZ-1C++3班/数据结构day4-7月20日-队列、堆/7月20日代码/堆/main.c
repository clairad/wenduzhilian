#include <stdio.h>
#include "heap.h"

int main()
{
	int tmp;
	Heap hp;
	Vector vt;
	int n;
	scanf("%d", &n);
	VectorInit(&vt, n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		VectorPushBack(&vt, tmp);
	}
	HeapInitV(&hp, &vt);

	HPDataType a, b;
	int sum = 0;
	while (HeapSize(&hp) > 1)
	{
		a = HeapTop(&hp);
		HeapPop(&hp);
		b = HeapTop(&hp);
		HeapPop(&hp);
		sum += a + b;
		HeapPush(&hp, a + b);
	}

	printf("%d", sum);

	//HeapSort(&vt);

	//VectorPrint(&vt);

	/*Heap hp;

	HeapInit(&hp, a, 10);

	printf("%d\n", HeapTop(&hp));
	HeapPop(&hp);
	printf("%d\n", HeapTop(&hp));
	HeapPop(&hp);
	printf("%d\n", HeapTop(&hp));
	HeapPop(&hp);
	printf("%d\n", HeapTop(&hp));
	HeapPop(&hp);
	printf("%d\n", HeapTop(&hp));
	HeapPop(&hp);
	printf("%d\n", HeapTop(&hp));
	HeapPush(&hp, 3);
	printf("%d\n", HeapTop(&hp));
	HeapPop(&hp);
	printf("%d\n", HeapTop(&hp));


	HeapDestory(&hp);*/
	return 0;
}
