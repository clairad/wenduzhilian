#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

volatile int g_allvalue = 100000000;
pthread_mutex_t g_mutex;

void *thread_func(void *arg)
{
    int count = 0;
    while(1)
    {
        pthread_mutex_lock(&g_mutex);
        if(g_allvalue <= 0)
        {
            pthread_mutex_unlock(&g_mutex);
            break;
        }
        g_allvalue--;
        count++;
        pthread_mutex_unlock(&g_mutex);
        //usleep(100);
    }
    *(int *)arg = count;
    return arg;
}

int main()
{
    pthread_t tid[20];
    int count[20];
    int i;
    pthread_mutex_init(&g_mutex, NULL);
    for(i = 0; i < 20; i++)
    {
        int ret = pthread_create(tid + i, NULL, thread_func, (void *)(count + i));
        if(ret)
        {
            printf("%d号线程创建失败\n", i);
            return 0;
        }
    }

    for(i = 0; i < 20; i++)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&g_mutex);
    int sum = 0;
    for(i = 0; i < 20; i++)
    {
        printf("%d号线程抢到了%d个资源\n", i, count[i]);
        sum += count[i];
    }
    printf("%d\n", sum);
    return 0;
}