#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
typedef struct
{
    int *data;
    int MaxSize;
    int length;
} SeqList; // 动态分配 顺序表

void InitList(SeqList &L)
{
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

bool ListInsert(SeqList &L, int i, int e) // 在第i个位置上插入指定元素e
{
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    if (L.length >= L.MaxSize)
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

bool ListDelete(SeqList &L, int i, int &e) // 在第i个位置上删除指定元素，并用e返回删除元素的值。
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

int GetElem(SeqList L, int i) // 获取表L中第i个位置的元素的值
{
    return L.data[i - 1];
}

int LocateElem(SeqList L, int e) // 在顺序表L中查找第一个元素值等于e的元素，并返回其位序
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

void printfSeqList (SeqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("data[%d]=%d\n" , i , GetElem(L, i + 1));
    }
}

int main()
{
    SeqList L;

    InitList(L);
    for (int i = 0; i < InitSize; i++)
    {
        ListInsert(L, i + 1, i);
    }
    int e;
    ListDelete(L, 7, e);
    printfSeqList(L); 
    printf("------------------%d", LocateElem(L,2));
    return 0;
}
