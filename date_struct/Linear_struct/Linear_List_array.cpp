#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef int Position;
typedef int ElementType;
typedef struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];
    Position last;
};
/*初始化*/
List MakeEmpty();
/*插入*/
bool Insert(List L,ElementType X,Position P);
/*删除*/
bool Delete(List L,Position P);

int main()
{
    List L;
    L=MakeEmpty();
    /*插入*/
    int flag = 1 ;
    do{
        ElementType X;
        Position P;
        scanf("%d %d",&X,&P);
        flag=Insert(L,X,P);
    }while(flag);
    
    return 0;
}

List MakeEmpty()
{
    List L;
    L=(List)malloc(sizeof(struct LNode));
    L->last=-1;
    return L;
}

bool Insert(List L,ElementType X,Position P)
{
    /* 在L的指定位置P前插入一个新元素X */
    if(L->last==MAXSIZE-1){
        printf("表满");
        return false;
    }
    if( P<0 || P>L->last+1 ){
        printf("位置不合法");
        return false;
    }
    for(Position i = L->last ; i>=P ; i-- ){
        L->Data[i+1]=L->Data[i];
    }
    L->Data[P]=X;
    ++L->last;
    return true;
}

bool Delete(List L,Position P)
{
    /* 从L中删除指定位置P的元素 */
    if( P<0 || P>L->last+1 ){
        printf("位置不合法");
        return false;
    }
    for(Position i = P ; i < L->last ; i++ ){
        L->Data[i]=L->Data[i+1];
    } 
    --L->last;
    return true;
}