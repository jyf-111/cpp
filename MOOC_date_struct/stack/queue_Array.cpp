/*队列是一个环，n个格n+1种状态，
1.size，tag域：标记队列是空还是满
2.只用n-1个格
这里用法二
*/

typedef int Position;
typedef int ElementType;
typedef struct QNode *Queue;
struct QNode
{
    ElementType *Data;
    Position Front,Rear;
    int MaxSize;
};
#include<stdio.h>
#include<stdlib.h>
/*创建一个队列*/
Queue CreateQueue(int MaxSize)
{
    Queue Q=(Queue)malloc(sizeof(struct QNode));
    Q->Data=(ElementType*)malloc(MaxSize*sizeof(ElementType));
    Q->Front=Q->Rear=0;
    Q->MaxSize=MaxSize;
    return Q;
}
/*判断队列是不是满*/
bool isFull(Queue S)
{
    return (S->Rear+1)%S->MaxSize==S->Front;
}
/*判断队列是不是空*/
bool isEmpty(Queue S)
{
    return S->Front==S->Rear;
}
/*入队*/
bool AddQ(Queue S,ElementType X)
{
    if(isFull(S)){
        printf("The queue is full\n");
        return false;
    }else{
        S->Rear=(S->Rear+1)%S->MaxSize;
        S->Data[S->Rear]=X;
        return true;
    }
}
/*出队*/
ElementType DeleteQ(Queue Q)
{
    if(isEmpty(Q)){
        printf("The queue is empty\n");
        return false;
    }else{
        Q->Front =(Q->Front+1)%Q->MaxSize;
        return  Q->Data[Q->Front];
    }
}
int main()
{
    Queue Q;
    Q=CreateQueue(5);
    int n=4;
    while(n--){
        int a;
        scanf("%d",&a);
        AddQ(Q,a);
    }
    for(int i=1 ;i<5 ;i++){
        printf("%d ",DeleteQ(Q));
    }
    //第二轮
    n=3;
    while(n--){
        int a;
        scanf("%d",&a);
        AddQ(Q,a);
    }
    for(int i=1 ;i<4 ;i++){
        printf("%d ",DeleteQ(Q));
    }
}