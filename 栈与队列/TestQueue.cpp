#include<stdio.h>
#include<malloc.h>
//#include "_5CircleQueue.h"
#include "_6ListQueue.h"
int main(){
    Queue q;
    InitQueue(q);
    for (int i = 0; i < 10; i++)
    {
        ElemType x;
        x.value=i;
        if (EnQueue(q,x)) printf("%d入队成功\n",x.value);
        else printf("%d入队失败\n",x.value);
    }
    for (int i = 0; i < 10; i++)
    {
        ElemType x;
        if (DeQueue(q,x)) printf("%d出队成功\n",x.value);
        else printf("%d出队失败\n",x.value);
    }
}