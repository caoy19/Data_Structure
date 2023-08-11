//双向链栈
/*
标准：
1.定义加基本操作，判空，进栈，出栈。
2.栈顶在链尾，需要维持一个top指针指向链尾。
3.采用带头结点双链表。
*/
#include<stdio.h>
#include<malloc.h>
typedef struct{
    int value;
}ElemType;
//一般ElemType就是int，直接写就行，这是用户所操作的最底层，其他均封装起来
typedef struct SNode{
    ElemType data;
    SNode *pior,*next;
}SNode; 
//规范表示，重新定义个结构体Stack：
typedef struct {
    SNode *head,*top;//head头结点，top栈顶在链尾
}*Stack;
bool InitStack(Stack &s){
    s=(Stack)malloc(sizeof(Stack));//分配栈空间
    SNode *p=(SNode*)malloc(sizeof(SNode));//分配头结点空间
    p->pior=NULL;//头结点赋值
    p->next=NULL;//头结点赋值
    s->head=p;
    s->top=p;
    return true;
}
bool StackEmpty(Stack s){
    return s->head==s->top;
}
bool push(Stack &s,ElemType x){
    SNode *p=(SNode *)malloc(sizeof(SNode));//插入结点
    p->data=x;
    p->next=NULL;
    p->pior=s->top;
    s->top->next=p;//这句别忘了，仔细点
    s->top=p;
    return true;
}
bool pop(Stack &s,ElemType &x){ //&x是为了x接受输出
    if(StackEmpty(s)) return false;
    SNode *p=s->top;
    x=p->data;
    s->top=s->top->pior;
    s->top->next=NULL;
    free(p);
    return true;
}
