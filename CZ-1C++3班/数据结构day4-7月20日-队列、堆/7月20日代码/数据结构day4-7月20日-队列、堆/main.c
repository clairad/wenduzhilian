#include <stdio.h>
#include "loopqueue.h"

int main()
{
	LQueue lq;

	LQueueInit(&lq, 5);

	LQueuePush(&lq, 1);
	printf("%d", LQueueSize(&lq));
	LQueuePush(&lq, 2);
	printf("%d", LQueueSize(&lq));
	LQueuePush(&lq, 3);
	printf("%d", LQueueSize(&lq));
	LQueuePush(&lq, 4);
	printf("%d", LQueueSize(&lq));
	LQueuePush(&lq, 5);
	printf("%d", LQueueSize(&lq));
	LQueuePush(&lq, 6);
	printf("%d", LQueueSize(&lq));

	printf("\n%d\n", LQueueFront(&lq));
	LQueuePop(&lq);
	printf("%d\n", LQueueFront(&lq));
	LQueuePop(&lq);
	printf("%d\n", LQueueFront(&lq));
	LQueueDestory(&lq);
	return 0;
}
