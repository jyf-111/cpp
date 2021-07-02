#include<iostream>
using namespace std;
typedef struct TreeNode* Tree;
struct TreeNode {
    int data;
    Tree Left;
    Tree Right;
};

Tree Insert(Tree T,int data) {
    if(!T) {
        T = new struct TreeNode;
        T->data = data;
        T->Left = T->Right = nullptr;
    }else if(T->data > data) {
        T->Left = Insert(T->Left,data);
    }else {
        T->Right = Insert(T->Right,data);
    }
    return T;
}

void PrintTree(Tree T,int n) {
    if(T) {
        PrintTree(T->Right,n+1);
        for(int i=0;i<n;i++) {
            cout << "  " ;
        }
        cout << T->data <<endl;
        PrintTree(T->Left,n+1);
    }
}

Tree FindMax(Tree T) {
    if(T) {
        while(T->Right) {
            T = T->Right;
        }
    }
    return T;
}

Tree FindMin(Tree T) {
    if(T) {
        while(T->Left) {
            T = T->Left;
        }
    }
    return T;
}

void Delete(Tree &T,int data) {
    if(!T) return ;
    if(T->data > data) {
        Delete(T->Left,data);
    }else if(T->data < data) {
        Delete(T->Right,data);
    }else {
        if(T->Left && T->Right) {
            Tree temp = FindMax(T->Left);
            T->data = temp->data;
            Delete(T->Left,temp->data);
        }else {
            Tree temp = T;
            if(!T->Left) {
                T = T->Right;
            }else {
                T = T->Left;
            }
            delete(temp);
        }
    }
}

Tree Delete_two(Tree T,int data) {
    Tree p,f,s,q;
    p = T;
    f = nullptr;
    while(p) {
        if(p->data==data) break;
        f = p;
        if(data>p->data) {
            p = p->Right;
        }else{
            p = p->Left;
        }
    }
    if(p==nullptr) return T;
    if(!p->Left) {
        if(f==nullptr) T = p->Right;
        else if(f->Left==p) {
            f->Left = p->Right;
        }else{
            f->Right = p->Right;
        }
        delete p;
    }else{
        q = p;
        s = p->Left;
        while(s->Right) {
            q = s;
            s = s->Right;
        }
        if(q==p) {
            q->Left = s->Left;
        }else{
            q->Right = s->Left;
        }
        p->data = s->data;
        delete s;
    }
    return T;
}

Tree Search(Tree T,int data) {
    if(!T) return nullptr;
    else if(T->data==data) return T;
    else if(T->data > data) {
        return Search(T->Left,data);
    }else {
        return Search(T->Right,data);
    }
}

Tree Search_two(Tree T,int data) {
    Tree p = T;
    while(p) {
        if(p->data==data) {
            return p;
        }else {
            if(data>T->data) {
                p = p->Right;
            }else {
                p = p->Left;
            }
        }
    }
    return nullptr;
}

int main()
{
    int a[10]={5,6,7,8,9,10,4,3,2,1};
    Tree T = nullptr;
    for(int i=0;i<10;i++) {
        T = Insert(T,a[i]);
    }
    PrintTree(T,0);
    Delete(T,3);
    Delete_two(T,4);
    PrintTree(T,0);

    Tree p = Search(T,9);
    cout << p->data <<endl;
    p = Search_two(T,9);
    cout << p->data <<endl;
}