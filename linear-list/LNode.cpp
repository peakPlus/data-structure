#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;

} LNode, *LinkList; // 不带头结点的单链表

bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}

LNode *GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
    {
        return L;
    }
    if (i < 1)
    {
        return NULL;
    }
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
    {
        return false;
    }
    if (i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L->next;
        L->next = s;
        return true;
    }
    LNode *p = L;
    int j = 1;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool Empty(LinkList L)
{
    return (L == NULL);
}

int main()
{
    LinkList L;
    InitList(L);
    return 0;
}