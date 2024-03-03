#include <stdio.h>  
#include <stdlib.h>  
#include <pthread.h>  
#include <windows.h>

void *print_thread_id(void *data)
{  
    //pthread_t tid = pthread_self();  
    //printf("线程 %lu 正在运行...%d\n", (unsigned long)tid, **(int **)data); 
	*(volatile int *)data = 9;
	Sleep(10);
	printf("我是线程%d，data的值是%d\n", pthread_self(), *(volatile int *)data);
    return data;
}  

void *print_thread_id2(void *data)
{  
    //pthread_t tid = pthread_self();  
    //printf("线程 %lu 正在运行...%d\n", (unsigned long)tid, **(int **)data); 
	*(volatile int *)data = 8;
	printf("我是线程%d，data的值是%d\n", pthread_self(), *(volatile int *)data);
    return data;
} 
  
int main()
{  
    pthread_t thread1, thread2;  
    int rc;  
	
	void* pmem = malloc(4);
    rc = pthread_create(&thread1, NULL, print_thread_id, pmem);  
    if (rc) {  
        printf("创建线程1失败: %d\n", rc);  
        exit(-1);  
    }  
      
    rc = pthread_create(&thread2, NULL, print_thread_id2, pmem);  
    if (rc) {  
        printf("创建线程2失败: %d\n", rc);  
        exit(-1);  
    }  
    
    int *pa;
    pthread_join(thread1, (void **)&pa);  
   // printf("线程%d已经结束。%d\n", thread1, **pa);  
    pthread_join(thread2, (void **)&pa);  
    //printf("线程%d已经结束。%d\n", thread2, **pa);  
    return 0;  
}
