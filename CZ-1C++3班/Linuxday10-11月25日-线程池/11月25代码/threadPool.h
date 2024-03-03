#ifndef _PTHREADPOOL_H_
#define _PTHREADPOOL_H_

#include <pthread.h>
#include <stdio.h>

typedef void *(*TASKFUNC)(void *);

typedef struct TaskNode
{
    int taskId;
    TASKFUNC pTakeFunc;
    struct TaskNode *next;
}Task;

typedef struct TaskQueue
{
    Task *front;
    Task *rear;
    pthread_mutex_t mutex;
    pthread_cond_t cv;
}TaskQueue;

typedef struct ThreadPool
{
    int thread_num;
    pthread_t *threads;
    TaskQueue taskqu;
    char flag;
}ThreadPool;

Task* createTask(int taskId, TASKFUNC tf);

void initQueue(TaskQueue* qu);
void pushQueue(TaskQueue* qu, Task* tk);
void popQueue(TaskQueue* qu, Task* tk);
void destroyQueue(TaskQueue* qu);

void initThreadPool(ThreadPool *tp, int num);
void pushTask(ThreadPool *tp, Task* tk);
void destroyThreadPool(ThreadPool *tp);

#endif //_PTHREADPOOL_H_