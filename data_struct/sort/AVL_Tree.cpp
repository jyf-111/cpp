#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct AVLTNode* AVLTree;
struct AVLTNode{
    int data;
    AVLTree Left;
    AVLTree Right;
    int bf;//平衡因子
};

void ins_AVLTree(AVLTree* avlt,int k) {
    AVLTree S = (AVLTree)malloc(sizeof(struct AVLTNode));
    S->data = k;
    S->Left = S->Right = nullptr;
    S->bf = 0;
    if(*avlt == nullptr) *avlt = S;
    else {
        AVLTree A = *avlt;
        AVLTree FA = nullptr;
        AVLTree p = *avlt;
        AVLTree fp = nullptr;
        AVLTree B = nullptr;
        AVLTree C = nullptr;
        while(p!=nullptr) {
            if(p->bf!=0) {
                A = p;
                FA = fp;
            }
            fp = p;
            if(k < p->data) {
                p = p->Left;
            }else p = p->Right;
        }
        //插入
        if(k<fp->data) fp->Left = S;
        else fp->Right = S;
        //调成A的因子
        if(k<A->data) {
            B = A->Left;
            (A->bf) ++;
        }else {
            B = A->Right; (A->bf)--;
        }
        //调整p->S的因子
        p = B;
        while(p!=S) {
            if(k<p->data){
                p->bf = 1;
                p = p->Left;
            }else{
                p->bf = -1;
                p = p->Right;
            }
        }

        if(A->bf==2 && B->bf==1){
            //LL
            A->Left = B->Right;
            B->Right = A;
            A->bf=0;
            B->bf=0;
            if(FA==nullptr) *avlt = B;
            else if(A==FA->Left) FA->Left = B;
            else FA->Right = B;
        }else if(A->bf==2 && B->bf==-1){
            //LR
            C = B->Right;
            B->Right = C->Left;
            A->Left = C->Right;
            C->Left = B;
            C->Right = A;
            if(S->data<C->data) {
                A->bf = -1;
                B->bf = 0;
                C->bf = 0;
            }else if(S->data>C->data) {
                A->bf = 0;
                B->bf = 1;
                C->bf = 0;
            }else {
                A->bf = 0;
                B->bf = 0;
            }
            if(FA==nullptr) *avlt = C;
            else if(A==FA->Left)FA->Left = C;
            else FA->Right = C;
        }else if(A->bf==-2 && B->bf==1) {
            //RL
            C = B->Left;
            B->Right = C->Right;
            A->Right = C->Left;
            C->Left = A;
            C->Right = B;
            if(S->data < C->data) {
                A->bf = 0;
                B->bf = -1;
                C->bf = 0;
            }else if(S->data > C->data) {
                A->bf  =1;
                B->bf = 0;
                C->bf = 0;
            }else {
                A->bf = 0;
                B->bf = 0;
            }
            if(FA==nullptr) {*avlt = C;}
            else if(FA->Left == A) FA->Left = C;
            else FA->Right = C;
        }else if(A->bf==-2 && B->bf==-1) {
            //RR
            A->Right = B->Left;
            B->Left = A;
            A->bf = 0;
            B->bf = 0;
            if(FA==nullptr) {*avlt = B;}
            else if(FA->Left == A) FA->Left = B;
            else FA->Right = B;
        }
    }
}

void PrintTree(AVLTree T,int n=0) {
    if(T) {
        PrintTree(T->Right,n+1);
        for(int i=0;i<n;i++) {
            cout << "  ";
        }
        cout << T->data << endl;
        PrintTree(T->Left,n+1);
    }
}

int main()
{
    AVLTree T=nullptr;
    for(int i=0;i<5;i++) {
        ins_AVLTree(&T,i);
        PrintTree(T);
        cout << "----------------" <<endl;
    }
}