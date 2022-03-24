#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;

} LNode, *LinkList; // 带头结点的单链表

bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    L->next = NULL;
    return true;
}

LNode *GetElem(LinkList L, int i) //按位查找
{
    if (i < 0)
    {
        return NULL;
    }
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

bool InsertNextNode(LNode *p, int e) //指定节点的后插操作
{
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
    {
        return false;
    }
    LNode *p = GetElem(L, i - 1);
    // LNode *p = L;
    // int j = 0;
    // while (p != NULL && j < i - 1)
    // {
    //     p = p->next;
    //     j++;
    // }
    return InsertNextNode(p, e);
    // if (p == NULL)
    // {
    //     return false;
    // }
    // LNode *s = (LNode *)malloc(sizeof(LNode));
    // s->data = e;
    // s->next = p->next;
    // p->next = s;
    // return true;
}

bool InsertPriorNode(LNode *p, int e) // 指定节点的前插操作
{
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false;
    }
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool ListDelete(LinkList &L, int i, int &e) // 按位序删除
{
    if (i < 1)
    {
        return false;
    }
    LNode *p = GetElem(L, i - 1);
    // LNode *p = L;
    // int j = 0;
    // while (p != NULL && j < i - 1)
    // {
    //     p = p->next;
    //     j++;
    // }
    if (p == NULL)
    {
        return false;
    }
    if (p->next == NULL)
    {
        return false;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    // p->next = p->next->next;
    free(q);
    return true;
}

bool DeleteNode(LNode *p) // 删除指定节点p
{
    if (p == NULL)
    {
        return false;
    }
    // 如果p是最后一个节点，只能从表头开始依次寻找p的前驱。
    if (p->next == NULL)
    {
        //不提供链表LinkList的话，无法实现
    }
    LNode *q = p->next; //将p->next的值给p，然后删除p->next;
    p->data = p->next->data;
    p->next = q->next;
    // p->next = p->next->next;
    free(q);
    return true;
}

LNode *LocateElem(LinkList L, int e) //按值查找
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

int Length(LinkList L) // 求表的长度
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

bool Empty(LinkList L) // 判断有头节点的单链表是否为空
{
    return (L->next == NULL);
}

LinkList List_TailInsert(LinkList &L) // 尾插法建立单链表
{
    int x;
    // 若LinkList未初始化，需下面一句方可运行
    // L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

LinkList List_HeadInsert(LinkList &L) // 头插法建立单链表
{
    LNode *s;
    int x;
    // 若LinkList未初始化，需下面两句方可运行
    // L = (LinkList)malloc(sizeof(LNode));
    // L->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

void PrintfLinkList(LinkList L) //按顺序打印链表LinkList的值
{
    printf("head->");
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL");
}

int main()
{
    LinkList L;
    InitList(L);
    // for (int i = 0; i < 5; i++)
    // {
    //     ListInsert(L, i + 1, i + 1);
    // }
    List_TailInsert(L);
    // List_HeadInsert(L);
    PrintfLinkList(L);
    return 0;
}