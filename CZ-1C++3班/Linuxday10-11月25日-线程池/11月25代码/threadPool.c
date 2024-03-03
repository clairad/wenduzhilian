#include "threadPool.h"
#include <stdlib.h>

void initQueue(TaskQueue* qu)
{
    qu->front = qu->rear = NULL;
    pthread_mutex_init(&qu->mutex, NULL);
    pthread_cond_init(&qu->cv, NULL);
}

void pushQueue(TaskQueue* qu, Task* tk)
{
    pthread_mutex_lock(&qu->mutex);
    if(qu->front == NULL)
    {
        qu->front = qu->rear = tk;
    }
    else
    {
        qu->rear->next = tk;
        qu->rear = tk;
    }
    pthread_mutex_unlock(&qu->mutex);
    pthread_cond_signal(&qu->cv);
}

void popQueue(TaskQueue* qu, Task* tk)
{
    pthread_mutex_lock(&qu->mutex);
    while(qu->front == NULL)
    {
        pthread_cond_wait(&qu->cv, &qu->mutex);
    }
    *tk = *(qu->front);

    Task * cur = qu->front;
    qu->front = cur->next;
    if(qu->front == NULL)
    {
        qu->rear = NULL;
    }
    free(cur);
    pthread_mutex_unlock(&qu->mutex);
}

void destroyQueue(TaskQueue* qu)
{
    pthread_mutex_destroy(&qu->mutex);
    pthread_cond_destroy(&qu->cv);

    Task *cur = qu->front;
    Task *tmp;
    while(cur)
    {
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
}

Task* createTask(int taskId, TASKFUNC tf)
{
    Task* cur = (Task *)malloc(sizeof(Task));
    cur->next = NULL;
    cur->taskId = taskId;
    cur->pTakeFunc = tf;
    return cur;
}

void pushTask(ThreadPool *tp, Task* tk)
{
    pushQueue(&tp->taskqu, tk);
}

void initThreadPool(ThreadPool *tp, int num)
{
    tp->thread_num = num;
    tp->threads = (pthread_t *)malloc(num * sizeof(pthread_t));
    tp->flag = 0;
    initQueue(&tp->taskqu);
}

void destroyThreadPool(ThreadPool *tp)
{
    destroyQueue(&tp->taskqu);
    free(tp->threads);
}