#include "BTree.h"
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

BTNode* buyBTreeNode(BTDataType ch)
{
    BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
    cur->data = ch;
    cur->lChild = cur->rChild = NULL;
    return cur;
}

static int pos = 0;
BTNode* BinaryTreeMakeRoot(BTDataType* a, BTDataType end)
{
    if (a[pos] == end)
    {
        pos++;
        return NULL;
    }
    BTNode* cur = buyBTreeNode(a[pos]);
    pos++;

    cur->lChild = BinaryTreeMakeRoot(a, end);
    cur->rChild = BinaryTreeMakeRoot(a, end);
    return cur;
}

BTNode* BinaryTreeCreate(BTDataType* a, BTDataType end)
{
    pos = 0;
    return BinaryTreeMakeRoot(a, end);
}

void BinaryTreeDestory(BTNode* root)
{
    if (root)
    {
        BinaryTreeDestory(root->lChild);
        BinaryTreeDestory(root->rChild);
        free(root);
    }
}

void BinaryTreePrevOrder(BTNode* root)
{
    if (root)
    {
        putchar(root->data);
        BinaryTreePrevOrder(root->lChild);
        BinaryTreePrevOrder(root->rChild);
    }
}

void BinaryTreeInOrder(BTNode* root)
{
    if (root)
    {
        BinaryTreeInOrder(root->lChild);
        putchar(root->data);
        BinaryTreeInOrder(root->rChild);
    }
}

void BinaryTreePostOrder(BTNode* root)
{
    if (root)
    {
        BinaryTreePostOrder(root->lChild);
        BinaryTreePostOrder(root->rChild);
        putchar(root->data);
    }
}

void BinaryTreeLevelOrder(BTNode* root)
{
    Queue qu;
    QueueInit(&qu);
    QueuePush(&qu, root);
    BTNode* cur = root;
    while (!QueueEmpty(&qu))
    {
        cur = QueueFront(&qu);
        putchar(cur->data);
        if (cur->lChild)
        {
            QueuePush(&qu, cur->lChild);
        }
        if (cur->rChild)
        {
            QueuePush(&qu, cur->rChild);
        }
        QueuePop(&qu);
    }
}

void BinaryTreePrevOrderNonR(BTNode* root)
{
    Stack st;
    StackInit(&st);
    BTNode* cur = root;
    while (cur || !StackEmpty(&st))
    {
        putchar(cur->data);
        if (cur->rChild)
        {
            StackPush(&st, cur->rChild);
        }
        if (cur->lChild)
        {
            cur = cur->lChild;
        }
        else
        {
            cur = NULL;
            if (!StackEmpty(&st))
            {
                cur = StackTop(&st);
                StackPop(&st);
            }
        }
    }
}

void BinaryTreeInOrderNonR(BTNode* root)
{
    Stack st;
    StackInit(&st);
    BTNode* cur = root;
    while (cur || !StackEmpty(&st))
    {
        for (; cur; cur = cur->lChild)
        {
            StackPush(&st, cur);
        }
        
        cur = StackTop(&st);
        putchar(cur->data);
        StackPop(&st);
        cur = cur->rChild;
    }
}

void BinaryTreePostOrderNonR(BTNode* root)
{
    BTNode* stN[50] = { 0 };
    int stD[50] = { 0 };
    int size = 0;
    BTNode* cur = root;
    do {
        for (; cur; cur = cur->lChild)
        {
            stN[size] = cur;
            stD[size] = 0;
            size++;
        }

        while (size && stD[size - 1])
        {
            putchar(stN[size - 1]->data);
            size--;
        }

        if (size)
        {
            stD[size - 1] = 1;
            cur = stN[size - 1];
            cur = cur->rChild;
        }
    } while (size);
}


int BinaryTreeGetDeep(BTNode* root)
{
    BTNode* stN[50] = { 0 };
    int stD[50] = { 0 };
    int size = 0;
    BTNode* cur = root;
    int max = 0;
    do {
        for (; cur; cur = cur->lChild)
        {
            stN[size] = cur;
            stD[size] = 0;
            size++;
        }

        while (size && stD[size - 1])
        {
            //max = max > size ? max : size;
            if (stN[size - 1]->lChild == NULL && stN[size - 1]->rChild == NULL)
            {
                max++;
            }
            size--;
        }

        if (size)
        {
            stD[size - 1] = 1;
            cur = stN[size - 1];
            cur = cur->rChild;
        }
    } while (size);
    return max;
}

BTNode* BinaryTreeGetCp(int n)
{
    if (n == 0)
    {
        return NULL;
    }
    BTNode* cur = buyBTreeNode('A');
    int c = 1;
    BTNode* root = cur;
    n--;
    BTNode* tmp;
    Queue qu;
    QueueInit(&qu);
    QueuePush(&qu, cur);
    while (n)
    {
        cur = QueueFront(&qu);
        tmp = BuyListNode('A' + c);
        c++;
        QueuePush(&qu, tmp);
        cur->lChild = tmp;
        n--;
        if (n)
        {
            tmp = BuyListNode('A' + c);
            c++;
            QueuePush(&qu, tmp);
            cur->rChild = tmp;
            n--;
        }
        QueuePop(&qu);
    }
    return root;
}