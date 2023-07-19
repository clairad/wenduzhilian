#include "queue.h"

void QueueInit(Queue* pq)
{
	ListInit(&pq->data);
}

void QueueDestory(Queue* pq)
{
	ListDestory(&pq->data);
}

void QueuePush(Queue* pq, QUDataType x)
{
	ListPushBack(&pq->data, x);
}

void QueuePop(Queue* pq)
{
	ListPopFront(&pq->data);
}

QUDataType QueueFront(Queue* pq)
{
	return pq->data.head->next->data;
}

QUDataType QueueBack(Queue* pq)
{
	return pq->data.head->prev->data;
}

int QueueEmpty(Queue* pq)
{
	return pq->data.head->next == pq->data.head;
}

int QueueSize(Queue* pq)
{
	return pq->data.size;
}
