typedef struct Node *PtrToNode;
typedef int ElementType;
typedef PtrToNode Position;
typedef struct QNode *Queue;

struct Node
{
    /* 队列中的结点 */
    ElementType Data;
    PtrToNode Next;
};
struct QNode
{
    Position Front,Rear;

};
#include<stdio.h>
#include<stdlib.h>

Queue CreateQueue(PtrToNode Node)
{
    /*队列要素*/
    Queue Q;
    Q=(Queue)malloc(sizeof(QNode));
    Q->Front=Q->Rear=Node;
    
    return Q;
}

bool isEmpty(Queue Q)
{
    return (Q->Front==Q->Rear);
}
Queue EnQueue(Queue Q,ElementType X)
{
    PtrToNode Node=(PtrToNode)malloc(sizeof(Node));
    Node->Next=NULL;
    Node->Data=X;
    Q->Rear->Next=Node;
    Q->Rear=Node;
    return Q;
}

Queue DeQueue(Queue Q)
{
    if(isEmpty(Q)){
        printf("The queue is empty,\
        delete fail!");
    }else{
        PtrToNode temp;
        temp=Q->Front->Next;
        Q->Front->Next=Q->Front->Next->Next;
        
        printf("delete the number %d\n",temp->Data);
        free(temp);
    }
    return Q;
}
int main()
{
    /*链表
     *头节点
     */
    PtrToNode Node;
    Node = (PtrToNode)malloc(sizeof(Node));
    Node->Next=NULL;
    /*队列要素*/
    Queue Q;
    Q=CreateQueue(Node);
    for(int i=0;i<5;i++){
        Q=EnQueue(Q,i);
    }
    for(int i=0;i<5;i++){
        Q=DeQueue(Q);
    }
}