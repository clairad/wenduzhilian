#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "list.h"

typedef LTDataType QUDataType;
typedef struct Queue {
	List data;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);


#endif //_QUEUE_H_