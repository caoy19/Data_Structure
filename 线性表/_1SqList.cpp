#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define Status int
/*
线性表分为顺序表和链表。
顺序表有着随机存取的特性，读特别方便。
而链表的插入删除也极为方便。
*/

/*
一.顺序表(随机存储)，注意顺序表的位置是从1开始，而数组从0开始。用顺序表的位置思考。
总结：取元素O(1), 插入删除都是O(N)
*/

#define List_Init_Size 100
typedef struct{
    int value;
}ElemType;

typedef struct{
    ElemType *elem;
    int length;
}SqList;

//1.初始化
/*
应试：&代表引用类型，就是会改变L的值时候用这个(C++语法)
Status InitList_Sq(SqList &L){
    L.elem=(ElemType*)malloc(List_Init_Size*sizeof(ElemType));
    L.length=0;
    return OK;
}
*/
Status InitList_Sq(SqList &L){
    L.elem=(ElemType*)malloc(List_Init_Size*sizeof(ElemType));
    L.length=0;
    return OK;
}


//2.插入一个元素e，给定位置pos，时间复杂度O(N)
/*
应试：
Status ListInsert(SqList &L,int pos, ElemType e){
    int n=L.length;
    if (pos<1||pos>n+1) return ERROR;
    if (pos==n+1)
    {
        L.elem[n]=e;
        L.length++;
    }
    //这个循环是重点需要理解
    for (int i = n-1; i >= pos-1; i--)
    {
        L.elem[i+1]=L.elem[i];
    }
    L.elem[pos-1]=e;
    L.length++;
    return OK;
}
*/
Status ListInsert_Sq(SqList &L,int pos,ElemType e){
    int n=L.length;
    if (pos<1||pos>n+1) return ERROR;
    if (pos==n+1)
    {
        L.elem[n]=e;
        L.length++;
    }
    for (int i = n-1; i >= pos-1; i--)
    {
        L.elem[i+1]=L.elem[i];
    }
    L.elem[pos-1]=e;
    L.length++;
    return OK;
}

//3.删除一个给定位置pos的元素,时间复杂度为O(N)
/*
应试：
Status ListDelete_Sq(SqList &L,int pos){
    int n=L.length;
    if (pos<1||pos>n) return ERROR;
    for (int i = pos; i <=n-1; i++)
    {
        L.elem[i-1]=L.elem[i];
    }
    L.length--;
    return OK;
}
*/
Status ListDelete_Sq(SqList &L,int pos){
    int n=L.length;
    if (pos<1||pos>n) return ERROR;
    for (int i = pos; i <=n-1; i++)
    {
        L.elem[i-1]=L.elem[i];
    }
    L.length--;
    return OK;
}


void showList(SqList L){
    for (int i = 0; i < L.length; i++)
    {
        printf("%d--",L.elem[i].value);
    }
    printf("length is %d\n",L.length);
}

int main(){
    SqList L;
    InitList_Sq(L);
    //赋值顺序表
    ElemType elems[10];
    for (int i = 0; i < 10; i++)
    {
        elems[i].value=i;
        L.elem[i]=elems[i];
        L.length++;
    }
    showList(L);
    //测试插入
    ElemType e;
    e.value=11;
    ListInsert_Sq(L,1,e);
    showList(L);
    //测试删除
    ListDelete_Sq(L,5);
    showList(L);
}
