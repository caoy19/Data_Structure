#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define Status int

/*
链表是链式存储的线性表。一般讨论的是带头节点的链表(优点是不需要额外讨论首元节点的操作，空表和非空表统一处理)
1.查找O(N)--顺序存取
2.删除，插入O(1)(不计算找位置的过程)，但对于单链表仍然是O(N)
*/

typedef struct{
    int value;
}ElemType;

struct Lnode{
    ElemType e;
    struct Lnode *next;
};
typedef struct Lnode LNode,*LinkList;


//1.初始化
Status ListInit(LinkList &L){
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    return OK;
}

//2.单链表头插法，(这只是插入一个元素)建立一个链表需要O(N);与此类似，尾插法也是O(N)
Status InsertFromHead(LinkList &L, ElemType e){
    LNode *node=(LNode*)malloc(sizeof(LNode));
    node->e=e;
    //注意空表的情况
    if (!L->next)
    {
        L->next=node;
        node->next=NULL;//这句话一定记住了！！
    }else{
        //经典操作 或者LNode *p=L->next;node->next=p;L->next=node;
        node->next=L->next;
        L->next=node;
    }
    return OK;
}

//3.求表长n, O(N)
int ListLength(LinkList L){
    int count=0;
    LNode *p;
    p=L->next;
    while (p)
    {
        p=p->next;
        count++;
    }
    return count;
}

//4.***按值查找，返回序号 O(N)
/*
应试：
int LocateElem(LinkList L,ElemType e){
    LNode *p=L->next;
    int index=1;
    while (p && p->e!=e)  //不等于不需要写方法判断
    {
        p=p->next;
        index++;
    }
    if (p) return index;
    else return 0;
}
*/
int equal(ElemType a, ElemType b){
    return a.value==b.value?1:0;
}
int LocateElem(LinkList L,ElemType e){
    LNode *p=L->next;
    int index=1;
    while (p && !equal(p->e,e))
    {
        p=p->next;
        index++;
    }
    if (p) return index;
    else return 0;
}

//5.***按序号查找，返回在ElemType中,认真体会 O(N)
Status GetElem(LinkList L,int pos,ElemType &e){
    if (pos<1) return ERROR;//或者这句话不用写
    LNode *p=L->next;
    int index=1;
    while (p && index<pos)
    {
        p=p->next;
        index++;
    }
    if (!p) return ERROR; //或者if(!p||j>i) return ERROR;
    e=p->e;
    return OK;
}

//6.***在第i给元素之前插入元素e， 对于单链表来说需要找到结点，所以是O(N),但对于其他的链表来说可以是O(1)
Status ListInsert(LinkList &L,int i,ElemType e){
    //先找到第i-1个结点
    LNode *p=L->next;
    int index=1;
    while(p && index<i-1){
        p=p->next;
        index++;
    }
    if (!p || index>i-1) return ERROR;
    //现在p指向的就是第i-1个节点
    LNode *node=(LNode*)malloc(sizeof(LNode));
    node->e=e;
    //重要操作！！
    node->next=p->next;
    p->next=node;
    return OK;
}

//7.***删除第i个元素，对于单链表来说需要找到结点，所以是O(N),但对于其他的链表来说可以是O(1)
Status ListDelete(LinkList &L, int i, ElemType &e){
    //先寻找第i-1个节点
    //先找到第i-1个结点
    LNode *p=L->next;
    int index=1;
    while(p && index<i-1){
        p=p->next;
        index++;
    }
    if (!p || index>i-1) return ERROR;
    //现在p指向的就是第i-1个节点
    LNode *q=p->next;//指向第i个
    p->next=p->next->next;
    e=q->e;
    delete(q);
    return OK;
}

int ListEmpty(LinkList L){
    if (L->next)//非空《==》L->next!=null,简写需要记住
      return 0;
    else return 1;
}

Status ClearList(LinkList L){
    LNode *p,*q;
    p=L->next;
    while (p)
    {
        q=p->next;
        delete(p);
        p=q;
    }
    L->next=NULL;
    return OK;
}

void show(LinkList L){
    LNode *p=L->next;
    while (p)
    {
        printf("%d-",p->e.value);
        p=p->next;
    }
    printf("\n");
}

//test
int main(){
    LinkList L;
    ListInit(L);
    ElemType e[10];
    for (int i = 0; i < 10; i++)
    {
        e[i].value=i;
        InsertFromHead(L,e[i]);
    }
    //测试头插法
    show(L);
    //测试按值查找
    printf("查找得到的位置为%d\n",LocateElem(L,e[0]));
    //测试按位查找
    GetElem(L,1,e[0]);
    printf("查找得到的值为%d\n",e[0].value);
    //测试插入元素
    ListInsert(L,5,e[0]);
    show(L);
    //测试删除元素
    ListDelete(L,5,e[0]);
    show(L);
}