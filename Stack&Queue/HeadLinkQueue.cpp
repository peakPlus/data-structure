#include <stdlib.h>
#include <stdio.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkQueue
{
    LinkNode *front, *rear;
} LinkQueue; // 带头结点的链式队列

void InitQueue(LinkQueue &Q) // 初始化队列
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q) // 判断队列是否为空
{
    if (Q.front == NULL) // if(Q.rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void EnQueue(LinkQueue &Q, int x) //入队
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, int &x) // 出队 
{
    if (Q.front == Q.rear)
    {
        return false;
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
    {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}

int main()
{
    LinkQueue Q;
    InitQueue(Q);
    return 0;
}
