//用单链表实现的队列
/*
标准：
1.入队在链尾，需要维持一个队尾指针。
2.出队在链头，使用带头结点的单链表，自动有一个队头指针。
总结：头删尾插。
*/
#include<stdio.h>
#include<malloc.h>
typedef struct{
    int value;
}ElemType;
//一般ElemType就是int，直接写就行，这是用户所操作的最底层，其他均封装起来
typedef struct QNode{
    ElemType data;
    QNode *next;
}QNode;
typedef struct {
    QNode *head,*rear;//head指向头结点，rear队尾指针。
}*Queue;
bool InitQueue(Queue &q){
    QNode *p=(QNode *)malloc(sizeof(QNode));
    p->next=NULL;
    q=(Queue)malloc(sizeof(Queue));
    q->head=p;
    q->rear=p;
    return true;
}
bool QueueEmpty(Queue q){
    return q->head==q->rear;
}
bool EnQueue(Queue &q,ElemType x){
    QNode *p=(QNode*)malloc(sizeof(QNode));
    p->data=x;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
    return true;
}
bool DeQueue(Queue &q,ElemType &x){
    if (QueueEmpty(q)) return false;
    QNode *p=q->head->next;
    x=p->data;
    q->head->next=p->next;
    if(q->rear==p) q->rear=q->head;//这句话容易忘，如果只有一个元素记得改rear。
    free(p);
    return true;
}

