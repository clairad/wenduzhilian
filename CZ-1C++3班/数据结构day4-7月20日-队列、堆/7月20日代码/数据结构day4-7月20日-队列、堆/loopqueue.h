#ifndef _LOOPQUEUE_H_
#define _LOOPQUEUE_H_

typedef int LQDataType;
typedef struct LoopQueue{
	LQDataType* start;
	int front;
	int rear;
	int N;
}LQueue;

void LQueueInit(LQueue* pq, int size);
void LQueueDestory(LQueue* pq);

int LQueuePush(LQueue* pq, LQDataType x);
int LQueuePop(LQueue* pq);
LQDataType LQueueFront(LQueue* pq);
LQDataType LQueueBack(LQueue* pq);
int LQueueEmpty(LQueue* pq);
int LQueueFull(LQueue* pq);
int LQueueSize(LQueue* pq);


#endif //_LOOPQUEUE_H_