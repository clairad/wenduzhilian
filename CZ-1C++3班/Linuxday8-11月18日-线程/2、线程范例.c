#include <stdio.h>  
#include <stdlib.h>  
#include <pthread.h>  
#include <windows.h>

void *print_thread_id(void *data)
{  
    //pthread_t tid = pthread_self();  
    //printf("�߳� %lu ��������...%d\n", (unsigned long)tid, **(int **)data); 
	*(volatile int *)data = 9;
	Sleep(10);
	printf("�����߳�%d��data��ֵ��%d\n", pthread_self(), *(volatile int *)data);
    return data;
}  

void *print_thread_id2(void *data)
{  
    //pthread_t tid = pthread_self();  
    //printf("�߳� %lu ��������...%d\n", (unsigned long)tid, **(int **)data); 
	*(volatile int *)data = 8;
	printf("�����߳�%d��data��ֵ��%d\n", pthread_self(), *(volatile int *)data);
    return data;
} 
  
int main()
{  
    pthread_t thread1, thread2;  
    int rc;  
	
	void* pmem = malloc(4);
    rc = pthread_create(&thread1, NULL, print_thread_id, pmem);  
    if (rc) {  
        printf("�����߳�1ʧ��: %d\n", rc);  
        exit(-1);  
    }  
      
    rc = pthread_create(&thread2, NULL, print_thread_id2, pmem);  
    if (rc) {  
        printf("�����߳�2ʧ��: %d\n", rc);  
        exit(-1);  
    }  
    
    int *pa;
    pthread_join(thread1, (void **)&pa);  
   // printf("�߳�%d�Ѿ�������%d\n", thread1, **pa);  
    pthread_join(thread2, (void **)&pa);  
    //printf("�߳�%d�Ѿ�������%d\n", thread2, **pa);  
    return 0;  
}
