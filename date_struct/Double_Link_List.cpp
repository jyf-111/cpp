#include<iostream>
#include<stdlib.h>
using std::cout;
using std::endl;
using ElementType = int;
using DLList = struct LNode*;
using PtrToDLList = DLList;

struct LNode
{
    ElementType Data;
    PtrToDLList prior,next;
};

DLList InitDLList()
{
    PtrToDLList node = (PtrToDLList)malloc(sizeof(struct LNode));
    node->Data = 0;
    node->next = node;
    node->prior = node;
    return node;
}

void printDLList(DLList L)
{
    PtrToDLList ptr = L->next;
    while(ptr != L)
    {
        cout << ptr->Data <<' ';
        ptr = ptr->next;
    }
    cout << endl;
}

//第i个位置后插入
void Insert(DLList L,int i,ElementType X)
{
    
    PtrToDLList ptr = L->next;
    if(L->next == L){
        //链表为空
        PtrToDLList node = (PtrToDLList)malloc(sizeof(struct LNode));
        node->Data = X;
        ptr->next = node;
        node->next = L;
        node->prior = ptr;
        L->prior = node;
        return;
    }else
    {
        int cnt = 1;
        while(ptr != L && cnt != i)
        {
            ptr = ptr->next;
            cnt++;
        }
        if(ptr->next == L){
            //在最后一个位置后插入
            PtrToDLList node = (PtrToDLList)malloc(sizeof(struct LNode));
            node->Data = X;
            ptr->next = node;
            node->next = L;
            node->prior = ptr;
            L->prior = node;
        }else if(ptr == L){
            cout <<" Position is not found" << endl;
            return ;
        }else {
            PtrToDLList node = (PtrToDLList)malloc(sizeof(struct LNode));
            node->Data = X;
            node->next = ptr->next;
            node->prior = ptr;
            ptr->next->prior = node;
            ptr->next = node;
        }
    }
}
//删除第i个元素
void Delete(DLList L,int i)
{
    if(L->next == L)
    {
        cout << "the list is empty" <<endl;
        return ;
    }
    PtrToDLList ptr = ptr->next;
    PtrToDLList pre = L;
    int cnt = 1;
    while(ptr!=L && cnt++ != i){
        ptr = ptr->next;
        pre = pre->next;
    }
    if(ptr == L){
        cout << "the positon is invalid" << endl;
        return ;
    }else{
        ptr->next->prior = pre;
        pre->next = ptr->next;
        free(ptr);
    }
}

int main()
{
    DLList L;

    L = InitDLList();

    for(int i = 0 ; i < 10 ; i++){
        Insert(L,i,i);
    }
    
    printDLList(L);

    for(int i = 10 ; i >0 ; i--){
        Delete(L,i);
        printDLList(L);
    }

    return 0;
}