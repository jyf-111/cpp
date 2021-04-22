#include<stdio.h>
#include<stdlib.h>
typedef int Position;
typedef int ElementType;
typedef struct SNode *Stack;

struct SNode
{
    ElementType *Data;
    Position Top;
    int MaxSize;
};
/*创建堆栈*/
Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data=(ElementType*)malloc(MaxSize*sizeof(ElementType));
    S->Top=-1;
    S->MaxSize=MaxSize;
    return S;
}
/*判断堆栈是不是满了*/
bool isFull(Stack S)
{
    return (S->Top==S->MaxSize-1);
}
/*判断堆栈是不是空的*/
bool isEmpty(Stack S)
{
    return S->Top==-1;
}
/*入栈*/
bool Push(Stack S,ElementType X)
{
    if(isFull(S)){
        printf("The stack is full\n");
        return false;
    }else{
        S->Data[++(S->Top)]=X;
        return true;
    }

}
/*出栈*/
ElementType Pop(Stack S)
{
    if(isEmpty(S)){
        printf("The stack is empty\n");
        return false;
    }else{
        return S->Data[(S->Top)--];
    }
}
int main()
{
    Stack S;
    S=CreateStack(5);
    int n=S->MaxSize;
    while(n--){
        int a;
        scanf("%d",&a);
        Push(S,a);
    }
    for(int i=0 ;i<S->MaxSize ;i++){
        printf("%d\n",Pop(S));
    }
}