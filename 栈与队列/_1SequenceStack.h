//顺序栈，用数组存储的栈。
/*
标准：
1.定义加基本操作，判空，判满，进栈，出栈。
2.top指针(伪指针，就是一个int变量)一般有俩种，一个指向栈顶元素，初始化为-1(本次使用这个)
一个指向栈顶元素的下一个位置，初始化为0.
*/
#include<stdio.h>
#include<malloc.h>
#define maxSize 50
typedef struct{
    int value;
}ElemType;
//一般ElemType就是int，直接写就行，这是用户所操作的最底层，其他均封装起来
typedef struct{
    ElemType data[maxSize];
    int top;//栈顶指针指向栈顶元素
}Stack;
bool InitStack(Stack &s){
    s.top=-1;
    return true;
}
bool StackEmpty(Stack s){
    return s.top==-1;
}
bool StackFull(Stack s){
    return s.top==maxSize-1;
}
bool push(Stack &s,ElemType x){
    if(StackFull(s)) return false;
    s.data[++s.top]=x;
    return true;
}
bool pop(Stack &s,ElemType &x){ //&x是为了x接受输出
    if(StackEmpty(s)) return false;
    x=s.data[s.top--];
    return true;
}

