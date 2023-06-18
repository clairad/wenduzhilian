#include <stdio.h>
#include "vector.h"

int cmp(int* a, int* b)
{
	return *a < *b;
}

int main()
{
	Vector v1, v2;

	VectorInit(&v1, 8);
	VectorInit(&v2, 8);

	VectorPushBack(&v1, 6);
	VectorPushBack(&v1, 2);
	VectorPushBack(&v1, 7);
	VectorPushBack(&v1, 4);
	VectorPushBack(&v1, 1);

	/*VectorErase(&v1, 3);
	VectorPopBack(&v1);
	VectorRemove(&v1, 3);*/

	VectorPushBack(&v2, 0);
	VectorPushBack(&v2, 3);
	VectorPushBack(&v2, 5);
	VectorPushBack(&v2, 8);
	VectorPushBack(&v2, 9);

	VectorSort(&v1, cmp);
	VectorPrint(&v1);
	VectorPrint(&v2);
	Vector v3 = VectorMergeNew(&v1, &v2);
	VectorPrint(&v3);


	VectorDestory(&v1);
	return 0;
}
