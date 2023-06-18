#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <stdio.h>
#include <stdlib.h>

//更改类型↓
typedef int VTDataType; 

typedef struct Vector {
	VTDataType* array; // 指向动态开辟的数组
	size_t size ; // 有效数据个数
	size_t capicity ; // 容量空间的大小
}Vector;

void VectorInit(Vector* psl, size_t capacity); //初始化
void VectorDestory(Vector* psl); //销毁
void VectorPushBack(Vector* psl, VTDataType x); //尾插
void VectorPopBack(Vector* psl); //尾删
void VectorPushFront(Vector* psl, VTDataType x); //头插
void VectorPopFront(Vector* psl); //头删
int  VectorFind(Vector* psl, VTDataType x); //查找
void VectorInsert(Vector* psl, size_t pos, VTDataType x); //插入
void VectorErase(Vector* psl, size_t pos); //删除（位置）
void VectorRemove(Vector* psl, VTDataType x); //删除（数据）
void VectorModify(Vector* psl, size_t pos, VTDataType x); //修改
void VectorPrint(Vector* psl);  //打印
int  VectorEmpty(Vector* psl);
void VectorClear(Vector* psl);

void VectorSort(Vector* psl, int (*cmp)(VTDataType *a, VTDataType *b));
void VectorSearch(Vector* psl, VTDataType x);
void VectorRemoveAll(Vector* psl, VTDataType x); //删除
void VectorMerge(Vector* src, Vector* val);
Vector VectorMergeNew(Vector* val1, Vector* val2);

#endif //_VECTOR_H_