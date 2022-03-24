#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int top;
} SqStack; // 顺序栈

void InitStack(SqStack &S) // 初始化栈
{
    S.top = -1; // top指向当前栈顶，另一种实现方式是top指向下一个可以插入的位置
}

bool StackEmpty(SqStack S) // 判断栈空
{
    if (S.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Push(SqStack &S, int x) // 新元素入栈
{
    if (S.top == MaxSize - 1)
    {
        return false;
    }
    S.top = S.top + 1;
    S.data[S.top] = x;
    return true;
}

bool Pop(SqStack &S, int &x) //出栈操作
{
    if (S.top == -1)
    {
        return false;
    }
    x = S.data[S.top];
    S.top = S.top - 1;
    return true;
}

bool GetTop(SqStack &S, int &x) // 读栈顶元素
{
    if (S.top == -1)
    {
        return false;
    }
    x = S.data[S.top];
    return true;
}

int main()
{
    SqStack S;
    InitStack(S);
    return 0;
}
