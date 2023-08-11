//括号匹配
/*
1.从左往右遍历表达式中括号元素：
若当前括号元素是左括号则将其入栈
若当前括号元素是右括号，则弹出栈顶元素，与当前元素匹配。
若匹配则继续遍历，若不匹配则字符串匹配失败
2.遍历完成后，若栈空则匹配成功，若栈非空则匹配失败
*/
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include "_1SequenceStack.h"
bool Match(char *s){
    Stack signStack;//
    InitStack(signStack);
    for (int i = 0; i < strlen(s); i++){
        //考试时候不用写这俩步，这地方写是因为为了运行，就是因为栈实现写的还不够完美(要支持泛型)
        ElemType elem;
        elem.value=s[i];
        //考试直接从这开始
        if(s[i]=='(' || s[i]=='[') push(signStack,elem);
        if(s[i]==')'){
            pop(signStack,elem);
            if (elem.value!='(') return false; 
        }
        if(s[i]==']'){
            pop(signStack,elem);
            if (elem.value!='[') return false; 
        }
    }
    if (StackEmpty(signStack)) return true;
    return false;
}

int main(){
    char s[50]="(2+3)*4-[5*(2-3)]*2";
    //scanf("%s",s);//给出字符串
    if(Match(s)) printf("匹配成功"); 
    else printf("匹配失败"); 
}