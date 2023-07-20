#ifndef _HEAP_H_
#define _HEAP_H_
#include "vector.h"

typedef VTDataType HPDataType;
typedef struct Heap {
	Vector data;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapInitV(Heap* hp, Vector* d);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);

void HeapSort(Vector *pv);
#endif //_HEAP_H_