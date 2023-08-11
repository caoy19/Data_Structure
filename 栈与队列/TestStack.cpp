#include<stdio.h>
#include<malloc.h>
//#include "_1SequenceStack.h"//test1
//#include "_2SingleListStack.h"//test2
#include "_3DoubleDirListStack.h"//test3

//test,实际考试就这么写，定义Stack，init，然后就可以用几个方法
//StackEmpty,StackFull,Push,Pop,GetTop
//可见单链栈和顺序栈的测试一模一样，这是因为封装了具体实现，
//在做数据结构大题的时候，也不用管是怎么样实现的，只用使用即可。
int main(){
    Stack s;
    InitStack(s);
    if (StackEmpty(s)) printf("empty\n");
    else  printf("not empty");
    for (int i = 0; i < 100; i++)
    {
        ElemType a;
        a.value=i;
        if(push(s,a)) printf("%d 进栈成功\n",a.value);
        else  printf("%d 进栈失败\n",a.value);
       
    }
    for (int i = 0; i < 6; i++)
    {
        ElemType a;
        if(pop(s,a)) printf("%d出栈\n",a.value);
        else  printf("出栈失败");
    }  
}