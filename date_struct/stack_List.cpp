typedef struct SNode *PtrToSNode;
typedef int ElementType;
typedef PtrToSNode Stack;
struct SNode
{
    ElementType Date;
    PtrToSNode Next;
};

#include<stdio.h>
#include<stdlib.h>

/*创建一个堆栈*/
Stack CreateStack()
{
    /* 构建一个堆栈的头结点，返回该结点指针 */
    Stack S=(Stack)malloc(sizeof(SNode));
    S->Next=NULL;
    return S;
}

/*判断堆栈为空*/
bool isEmpty(Stack S)
{
    return (S->Next==NULL);
}

/*入栈*/
bool Push(Stack S,ElementType X)
{
    /* 将元素X压入堆栈S */
    PtrToSNode TempCell;
    TempCell =(PtrToSNode)malloc(sizeof(struct SNode));
    TempCell->Date=X;
    /*头插法*/
    TempCell->Next=S->Next;
    S->Next=TempCell;
    return true;
}
ElementType Pop(Stack S)
{
    if(isEmpty(S)){
        printf("The stack is empty");
        return false;
    }else{
        /* 删除并返回堆栈S的栈顶元素 */
        PtrToSNode FirstCell=S->Next;
        ElementType FirstElement;
        S->Next=FirstCell->Next;
        FirstElement=FirstCell->Date;
        free(FirstCell);
        return FirstElement;
    }
    
}
int main()
{
    Stack S;
    S=CreateStack();
    int n=5;
    while(n--){
        int a;
        scanf("%d",&a);
        Push(S,a);
    }
    for(int i=0 ;i<5 ;i++){
        printf("%d\n",Pop(S));
    }
}