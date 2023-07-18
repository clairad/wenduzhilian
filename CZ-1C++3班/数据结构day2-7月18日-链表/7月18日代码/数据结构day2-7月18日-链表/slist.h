#ifndef _SLIST_H_
#define _SLIST_H_

typedef int SLDataType;
typedef struct SListNode {
	SLDataType data;
	struct SListNode* next;
}SListNode;

typedef struct SList {
	SListNode* head;
	int size;
}SList;

void SListInit(SList* plt); 
void SListDestory(SList *plt); 
SListNode* BuySListNode(SLDataType x);
void SListPushFront(SList *plt, SLDataType x);
void SListPopFront(SList *plt); 
SListNode* SListFind(SList *plt, SLDataType x);
SListNode* SListFindPre(SList* plt, SLDataType x);
void SListInsert(SList* plt, SListNode* pos, SLDataType x);
void SListErase(SList* plt, SListNode* pos);
void SListRemove(SList *plt, SLDataType x); 
void SListModify(SList* plt, SLDataType x1, SLDataType x2 );
void SListPrint(SList *plt);

void SListSort(SList* plt);
void SListReverse(SList* plt);
void SListMerge(SList* plt, SList* plt2);

#endif //_SLIST_H_
