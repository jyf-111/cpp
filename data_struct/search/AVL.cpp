#include<iostream>
using namespace std;
#define Max(a,b) ((a>b)?a:b)

typedef struct TreeNode* Tree;
struct TreeNode {
    Tree Left;
    Tree Right;
    int data;
    int height;
    TreeNode(int X) :Left(0),Right(0),height(0) { data = X;}
};

int GetNodeHeight(Tree T) {
    return (T? T->height:-1);
}

Tree SingleLeftRotation(Tree A) {
    Tree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->height = Max(GetNodeHeight(A->Left),GetNodeHeight(A->Right))+1;
    B->height = Max(GetNodeHeight(B->Left),GetNodeHeight(B->Right))+1;
    return B;
}

Tree SingleRightRotation(Tree A) {
    Tree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    A->height = Max(GetNodeHeight(A->Left),GetNodeHeight(A->Right))+1;
    B->height = Max(GetNodeHeight(B->Left),GetNodeHeight(B->Right))+1;
    return B;
}

Tree DoubleLeftRightRotation(Tree A) {
    A->Left = SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}

Tree DoubleRightLeftRotation(Tree A) {
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}

Tree insert(Tree T,int t) {
    if(!T) {
        T = new struct TreeNode(t);
    }else {
        if(t>T->data) {
            T->Right = insert(T->Right,t);
            if(GetNodeHeight(T->Right)-GetNodeHeight(T->Left)==2) {
                if(t>T->Right->data) {
                    T = SingleRightRotation(T);
                }else{
                    T = DoubleRightLeftRotation(T);
                }
            }
        }else {
            T->Left = insert(T->Left,t);
            if(GetNodeHeight(T->Left)-GetNodeHeight(T->Right)==2) {
                if(t<T->Left->data) {
                    T = SingleLeftRotation(T);
                }else{
                    T = DoubleLeftRightRotation(T);
                }
            }
        }
    }
    T->height = Max(GetNodeHeight(T->Left),GetNodeHeight(T->Right))+1;
    return T;
}

void Remove(Tree &T,int t) {
    
        if(t>T->data) {
            Remove(T->Right,t);
            if(GetNodeHeight(T->Right)-GetNodeHeight(T->Left)==2) {
                if(t>T->Right->data) {
                    T = SingleRightRotation(T);
                }else{
                    T = DoubleRightLeftRotation(T);
                }
            }
        }else if(t<T->data){
            Remove(T->Left,t);
            if(GetNodeHeight(T->Left)-GetNodeHeight(T->Right)==2) {
                if(t<T->Left->data) {
                    T = SingleLeftRotation(T);
                }else{
                    T = DoubleLeftRightRotation(T);
                }
            }
        }else if(T->Left && T->Right) {
            Tree p = T->Left;
            while(p->Right) {
                p = p->Right;
            }
            T->data = p->data;
            Remove(T->Left,p->data);
            if(GetNodeHeight(T->Right)-GetNodeHeight(T->Left)==2) {
                if(T->Right->Right!=nullptr) {
                    T = SingleRightRotation(T);
                }else{
                    T = DoubleRightLeftRotation(T);
                }
        
            }else{
                Tree tmp = T;
                T =( T->Left !=nullptr ? T->Left:T->Right);
                delete tmp;
                tmp = nullptr;
            }
        }
    if(T !=nullptr)
        T->height = Max(GetNodeHeight(T->Left),GetNodeHeight(T->Right))+1;
}

int main()
{

}