#include <stdio.h>
#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int length;
} SqList; // 静态分配 顺序表

void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}

bool ListInsert(SqList &L, int i, int e) // 在第i个位置上插入指定元素e
{
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    if (L.length >= MaxSize)
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, int &e) // 在第i个位置上删除指定元素，并用e返回删除元素的值。
{
    if (i < 1 || i > L.length)
    {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

int GetElem(SqList L, int i) // 获取表L中第i个位置的元素的值
{
    return L.data[i - 1];
}

int LocateElem(SqList L, int e) // 在顺序表L中查找第一个元素值等于e的元素，并返回其位序
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

void printfSqList (SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("data[%d]=%d\n" , i , GetElem(L, i + 1));
    }
}

int main()
{
    SqList l;
    InitList(l);
    for (int i = 0; i < MaxSize; i++)
    {
        ListInsert(l, i + 1, i);
    }
    printfSqList(l);
    int e;
    ListDelete(l, 7, e);
    printfSqList(l);
    printf("--------%d", LocateElem(l, 2));
    return 0;
}
