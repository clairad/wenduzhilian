#include <stdio.h>
#include <unistd.h>
#include "threadPool.h"

void *taskfunc(void *arg)
{
    printf("My creator is thread %ld\n", *(pthread_t *)arg % 13);
    return NULL;
}

void *threadfunc(void *arg)
{
    ThreadPool* tp = (ThreadPool *)arg;
    while(1)
    {
        Task tk;
        popQueue(&tp->taskqu, &tk);
        if(tp->flag)
        {
            break;
        }

        pthread_t tid = pthread_self();
        printf("task id: %d\n", tk.taskId);
        tk.pTakeFunc((void *)&tid);
        
        sleep(1);
    }
    //printf("exit\n");
    return NULL;
}

int main()
{
    ThreadPool tp;
    initThreadPool(&tp, 5);
    int i;
    for(i = 0; i < tp.thread_num; i++)
    {
        pthread_create(&tp.threads[i], NULL, threadfunc, (void *)&tp);
    }

    for(i = 1; i <= 15; i++)
    {
        pushTask(&tp, createTask(i, taskfunc));
    }
    sleep(4);
    tp.flag = 1;
    
    for(i = 0; i < tp.thread_num; i++)
    {
        pushTask(&tp, createTask(-1, taskfunc));
    }

    for(i = 0; i < tp.thread_num; i++)
    {
        pthread_join(tp.threads[i], NULL);
    }

    destroyThreadPool(&tp);
    return 0;
}
