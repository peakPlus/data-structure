#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int front, rear;
    // int size; // 队列当前长度
    // int tag; //最近执行的是删除/插入操作,只有删除操作，才可能导致队空，只有插入操作，才可能导致队满。
} SqQueue;

void InitQueue(SqQueue &Q) // 初始化队列
{
    Q.rear = Q.front = 0; // 队尾指针指向队尾元素的后一个位置(下一个应该插入的位置)
}

bool QueueEmpty(SqQueue Q)
{
    if (Q.rear == Q.front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool EnQueue(SqQueue &Q, int x) // 入队
{
    if ((Q.rear + 1) % MaxSize == Q.front) // 牺牲1一个数据单元
    {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, int &x) // 出队
{
    if (Q.rear == Q.front)
    {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

bool GetHead(SqQueue Q, int &x) // 获取队头元素
{
    if (Q.rear == Q.front)
    {
        return false;
    }
    x = Q.data[Q.front];
    return true;
}

int main()
{

    return 0;
}