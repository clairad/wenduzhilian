#include <stdio.h>
#include "list.h"

int main()
{
	List ls;

	ListInit(&ls);

	ListPushFront(&ls, 1);
	ListPushFront(&ls, 3);
	ListPushBack(&ls, 5);
	ListPushBack(&ls, 4);
	ListPushFront(&ls, 2);

	ListRemove(&ls, 3);

	ListPrint(&ls);
	return 0;
}
