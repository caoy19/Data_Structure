//循环队列，用数组实现。
/*
标准：
1.入队操作在队尾进行，只改变rear。出队操作在队头进行，只改变front。
2.front，rear指向各个教材都不太一样，大致有三种情况
front=0,rear=0 front指向队头元素，rear指向队尾元素的下一个位置(常见)==》本次的定义
front=-1，rear=-1 front指向队头元素的前一个位置，rear指向队尾元素(常见)
front=0, rear=-1 front指向队头元素，rear指向队尾元素(是因为判断不像前面俩个那么简单，稍微复杂点)
3.解决循环队列的队空队满判断，共有三种办法
空出一个位置，常用。==》本次使用这个
增加size标志，easy
增加tag标志，每次入队tag=1，只会队满，每次出队tag=0，只会队空
*/
#include<stdio.h>
#include<malloc.h>
#define maxSize 5
typedef struct{
    int value;
}ElemType;
typedef struct {
    ElemType data[maxSize];
    int front,rear;
}Queue;
bool InitQueue(Queue &q){
    q.front=0;//指向对头元素
    q.rear=0;//指向队尾元素的下一个位置
    return true;
}
bool QueueEmpty(Queue q){
    return q.front==q.rear;
}
bool QueueFull(Queue q){
    return (q.rear+1)%maxSize==q.front;
}
int QueueLength(Queue q){
    return (q.rear+maxSize-q.front)%maxSize;
}
bool EnQueue(Queue &q,ElemType x){
    if (QueueFull(q)) return false;
    q.data[q.rear]=x;
    q.rear=(q.rear+1)%maxSize;//只改变rear
    return true;
}
bool DeQueue(Queue &q,ElemType &x){
    if (QueueEmpty(q)) return false;
    x=q.data[q.front];
    q.front=(q.front+1)%maxSize;
    return true;
}
