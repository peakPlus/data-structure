#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int top0;
    int top1;
} ShStack; // 共享栈

void InitStack(ShStack &S) // 初始化栈
{
    S.top0 = -1;
    S.top1 = MaxSize;
}
