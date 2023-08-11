//单链栈。
/*
标准：
1.定义加基本操作，判空，进栈，出栈。
2.栈顶在链头，入栈出栈均在链头。
3.采用带头结点单链表，故不需要再来一个top指针了。
*/
#include<stdio.h>
#include<malloc.h>
typedef struct{
    int value;
}ElemType;
//一般ElemType就是int，直接写就行，这是用户所操作的最底层，其他均封装起来
typedef struct SNode{
    ElemType data;
    SNode *next;
}SNode,*Stack; //这个就是简洁表示，要是更规范点可以再定义个Stack结构体。
bool InitStack(Stack &s){
    SNode *p=(SNode*)malloc(sizeof(SNode));//头结点
    p->next=NULL;
    s=p; 
    return true;
}
bool StackEmpty(Stack s){
    return s->next==NULL;
}
bool push(Stack &s,ElemType x){
    SNode *p=(SNode *)malloc(sizeof(SNode));//插入结点
    p->data=x;
    p->next=s->next;
    s->next=p;
    return true;
}
bool pop(Stack &s,ElemType &x){ //&x是为了x接受输出
    if(StackEmpty(s)) return false;
    SNode *p=s->next;
    x=p->data;
    s->next=p->next;
    free(p);
    return true;
}

