#include "loopqueue.h"
#include <stdlib.h>

void LQueueInit(LQueue* pq, int size)
{
	pq->start = (LQDataType*)malloc((size + 1) * sizeof(LQDataType));
	pq->front = pq->rear = 0;
	pq->N = size + 1;
}

void LQueueDestory(LQueue* pq)
{
	free(pq->start);
}

int LQueuePush(LQueue* pq, LQDataType x)
{
	if (LQueueFull(pq))
	{
		return 0;
	}
	pq->start[pq->rear] = x;
	pq->rear++;
	pq->rear %= pq->N;
	return 1;
}

int LQueuePop(LQueue* pq)
{
	if (LQueueEmpty(pq))
	{
		return 0;
	}
	pq->front++;
	pq->front %= pq->N;
	return 1;
}

LQDataType LQueueFront(LQueue* pq)
{
	return pq->start[pq->front];
}

LQDataType LQueueBack(LQueue* pq)
{
	return pq->start[(pq->rear - 1 + pq->N) % pq->N];
}

int LQueueEmpty(LQueue* pq)
{
	return pq->front == pq->rear;
}

int LQueueFull(LQueue* pq)
{
	return (pq->rear + 1) % pq->N == pq->front;
}

int LQueueSize(LQueue* pq)
{
	return (pq->rear - pq->front + pq->N) % pq->N;
}
