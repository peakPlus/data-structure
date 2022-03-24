#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList; //带头结点的双链表

bool InitDLinkList(DLinkList &L) //初始化带头结点的双链表
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
    {
        return false;
    }
    L->prior = NULL;
    L->next = NULL;
    return true;
}

bool InsertNextDNode(DNode *p, DNode *s) //插入指定节点后
{
    if (p == NULL || s == NULL)
    {
        return false;
    }
    s->next = p->next;
    if (p->next != NULL)
    {

        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

void DestoryList(DLinkList &L)
{
    while (L->next != NULL)
    {
        DestoryList(L->next);
    }
    free(L);
    L = NULL;
}

bool DeleteNextDNode(DNode *p)
{
    if(p == NULL) {return false;}
    DNode *q = p->next;
    if(q == NULL) {return false;}
    p->next = q->next;
    if(q->next != NULL) {
        q->next->prior = p;
    }
    free(q);
    return true;
}

int main()
{
    return 0;
}