#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;

typedef struct LNode *PtrToLNode,*Position;

struct LNode
{
    ElementType Date;
    PtrToLNode Next;
};
/*寻找*/
int Find(PtrToLNode L,ElementType X);
/*插入*/
bool Insert(PtrToLNode L,ElementType X,int P);
/*删除*/
bool Delete(PtrToLNode L,int P);

int main()
{
    /*默认L是带头节点的链表*/
    PtrToLNode L = (PtrToLNode)malloc(sizeof(LNode));
    L->Next=NULL;
    /*插入*/
    int flag = 1 ;
    do{
        ElementType X;
        int P;
        scanf("%d %d",&X,&P);
        flag=Insert(L,X,P);
    }while(flag);
    /*寻找元素*/
    flag=Find(L,3);
    if(flag!=-1){
        printf("find number at %d position\n",flag);
    }
    /*删除节点*/
    Delete(L,0);
    return 0;
}

int Find(PtrToLNode L,ElementType X)
{
    int cnt=0;
    Position P;
    for(P=L->Next ; P->Date != X && P!=NULL;P=P->Next){
        cnt++;
    }
    if(P==NULL){
        printf("No this number\n");
        return -1;
    }
    return cnt;
}

bool Insert(PtrToLNode L,ElementType X,int P)
{
    int cnt = 0;
    Position pre = L;
    Position temp ;
    /*pre定位到P前一个*/
    while(pre&&cnt++!=P){
        pre=pre->Next;
    }
    if(pre==NULL){
        /*位置不正确*/
        printf("false\n");
        return false;
    }else{
        /*新节点*/
        PtrToLNode temp;
        temp=(PtrToLNode)malloc(sizeof(LNode));
        temp->Date=X;
        temp->Next=pre->Next;
        pre->Next=temp;
        return true;
    }
}
bool Delete(PtrToLNode L,int P)
{
    Position pre,temp;
    int cnt = 0;
    /*定位到删除节点前一个*/
    for(pre = L ; cnt++!=P ; pre= pre->Next);
    temp = pre->Next;
    if(pre==NULL||pre->Next==NULL){
        printf("Error");
        return 0;
    }else{
        pre->Next=temp->Next;
        printf("number %d has deleted\n",temp->Date);
        free(temp);
        return 1;
    }
}