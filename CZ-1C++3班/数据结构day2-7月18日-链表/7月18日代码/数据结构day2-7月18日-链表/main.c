#include <stdio.h>
#include "slist.h"

int josephs(int m, int n)
{
	SListNode* head = BuySListNode(m);
	SListNode* tail = head;
	SListNode* cur, *tmp;

	int i;
	for (i = m - 1; i > 0; i--)
	{
		cur = BuySListNode(i);
		cur->next = head;
		head = cur;
	}
	tail->next = head;

	/*for (cur = head; cur; cur = cur->next)
	{
		printf("%d->", cur->data);
	}*/
	cur = tail;
	while (m > 1)
	{
		for (i = 1; i < n; i++)
		{
			cur = cur->next;
			printf("%dºÅ±¨%d\n", cur->data, i);
		}
		tmp = cur->next;
		printf("%dºÅ³öÈ¦\n", tmp->data);
		cur->next = tmp->next;
		free(tmp);
		m--;
	}
	int ret = cur->data;
	free(cur);
	return ret;
}

int main()
{
	SList sl;

	//printf("%dºÅÊ¤Àû", josephs(10, 3));
	SListInit(&sl);
	SListPushFront(&sl, 3);
	SListPushFront(&sl, 4);
	SListPushFront(&sl, 4);
	SListPushFront(&sl, 1);
	SListPushFront(&sl, 5);
	//SListRemove(&sl, 5);
	SListModify(&sl, 4, 7);
	SListSort(&sl);
	//SListReverse(&sl);
	SListPrint(&sl);

	SList sl2;
	SListInit(&sl2);
	SListPushFront(&sl2, 2);
	SListPushFront(&sl2, 6);
	SListPushFront(&sl2, 8);
	SListPushFront(&sl2, 9);
	SListPushFront(&sl2, 10);
	SListSort(&sl2);
	SListPrint(&sl2);

	SListMerge(&sl, &sl2);
	SListPrint(&sl);
	SListPrint(&sl2);

	SListDestory(&sl);
	return 0;
}
