/*循环链表设尾指针*/
#include<iostream>
#include<stdlib.h>
using std::cout;
using std::endl;
using ElementType = int;
using CList = struct LNode*;
using Node = struct LNode*;

struct LNode
{
    ElementType Data;
    CList Next;
};

CList InitCLintList()
{
    CList L; 
    L =(CList)malloc(sizeof(struct LNode));
    L->Next = L; //循环
    L->Data=100;
    return L;
}

Node Insert(CList L ,Node Rear,ElementType X)
{
    Node node =(Node)malloc(sizeof(struct LNode));
    node->Data = X;
    node->Next = L;
    Rear->Next = node;
    Rear = node;
    return Rear;
}

void printCList(CList L)
{
    Node ptr = L->Next;
    while(ptr != L){
        //cout << ptr->Data << endl;
        printf(" %d",ptr->Data);
        ptr = ptr->Next;
    }
    cout << endl;
}

void Delete(CList L,int i)
{
    if(L->Next==L)
    {
        cout<<" the list is empty"<<endl;
        return;
    }
    Node ptr = L->Next;   //指向删除元素
    Node pre = L;
    int cnt = 1;
    while(ptr != L  && cnt != i)
    {
        ptr = ptr->Next;
        pre = pre->Next;
        cnt++;
    }
    if(ptr == L){
        cout <<"can not find position" << endl;
        return ;
    }else{
        Node temp = pre->Next;
        pre->Next = pre->Next->Next;
        free(temp);
    }
}
int main()
{
    CList L ;   //野指针不可以作为参数传参
    Node Rear;
    L = InitCLintList();
    Rear = L;
    
    for(int i=0;i<10;i++){
        Rear = Insert(L,Rear,i);
    }
    
    printCList(L);

    Delete(L,11);

    printCList(L);
    return 0;
}