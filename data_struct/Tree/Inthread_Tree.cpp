#include<iostream>
#include<stack>
#include<queue>
using namespace std;

typedef char ElementType;

typedef struct TreeNode* PtrToTNode;
struct TreeNode {
    PtrToTNode Left;
    bool Ltag;//false 表示左子树 true表示前驱
    ElementType Data;
    PtrToTNode Right;
    bool Rtag;//true 表示右子树 true表示后继
};
typedef PtrToTNode Tree;

void CreateTree(Tree* T) {
    ElementType ch;
    ch = getchar();
    if(ch=='.') {
        *T = nullptr;
    }else{
        *T = new struct TreeNode;
        (*T)->Data = ch;
        (*T)->Ltag=false;
        (*T)->Rtag=false;
        CreateTree(&((*T)->Left));
        CreateTree(&((*T)->Right));
    }
}

void PreOrder(Tree T) {
    if(nullptr != T) {
        cout << T->Data << " ";
        PreOrder(T->Left);
        PreOrder(T->Right);
    }
}

void Inorder(Tree T) {
    if( nullptr != T) {
        Inorder(T->Left);
        cout << T->Data << " ";
        Inorder(T->Right);
    }
}

void PostOrder(Tree T) {
    if(nullptr != T) {
        PostOrder(T->Left);
        PostOrder(T->Right);
        cout << T->Data <<" ";
    }
}

void LayerOrder(Tree T) {
    queue<PtrToTNode> q;
    if(T) {
        q.push(T);
        while(!q.empty()) {
            PtrToTNode p = q.front();
            q.pop();
            cout << p->Data << " "; 
            if(p->Left) {
                q.push(p->Left);
            }
            if(p->Right) {
                q.push(p->Right);
            }
        }
    }
}

void PrintLeaf(Tree T,int &count) {
    if( nullptr != T){
        PrintLeaf(T->Left,count);
        PrintLeaf(T->Right,count);
        if(!T->Left && !T->Right) {
            cout << T->Data << " ";
            count++;
        }
    }
}

int LeafCount(Tree T) {
    if( nullptr== T) {
        return 0;
    }else if( !T->Left && !T->Right) {
        return 1;
    }else {
        return LeafCount(T->Left)+LeafCount(T->Right);
    }
}

int PostTreeDepth(Tree T) {
    if(nullptr==T){
        return 0;
    }else{
        int left = PostTreeDepth(T->Left);
        int right = PostTreeDepth(T->Right);
        return (left>right ? left:right)+1;
    }
}

void PreTreeDepth(Tree T,int &depth,int h) {
    if( nullptr !=T ){
        PreTreeDepth(T->Left,depth, h+1);
        if(h>depth) depth = h;
        PreTreeDepth(T->Right,depth, h+1);
    }
}

void PrintTree(Tree T,int nlayer) {
    if( nullptr != T) {

        PrintTree(T->Right,nlayer+1);

        for(int i =0 ; i< nlayer ; ++i) {
            cout << "  ";
        }
        cout << T->Data << endl;

        PrintTree(T->Left,nlayer+1);
    }
}

void inorder_array(Tree T) {
    PtrToTNode array[10000];
    int top = 0;
    PtrToTNode p = T;
    do{
        while(p!=nullptr){
            top++;
            array[top] = p;
            p = p->Left;
        }
        if(top!=0){
            p = array[top];
            top--;
            cout << p->Data << " ";
            p = p->Right;
        }
    }while(top!=0 || p!=nullptr);
}

void inorder_stack(Tree T) {
    stack<PtrToTNode> s;
    PtrToTNode p = T;
    while(!s.empty() || p!=nullptr) {
        if(p!=nullptr){
            s.push(p);
            p = p->Left;
        }else{
            p = s.top();
            s.pop();
            cout << p->Data << " ";
            p = p->Right;
        }
    }
}

void Preorder_array(Tree T) {
    PtrToTNode array[10000];
    int top = 0;
    PtrToTNode p = T;
    do{
        while(p!=nullptr){
            top++;
            array[top] = p;
            cout << p->Data << " ";
            p = p->Left;
        }
        if(top!=0){
            p = array[top];
            top--;
            p = p->Right;
        }
    }while(top!=0 || p!=nullptr);
}

void Preorder_stack(Tree T) {
    stack<PtrToTNode> s;
    PtrToTNode p = T;
    while(!s.empty() || p!=nullptr) {
        if(p!=nullptr){
            s.push(p);
            cout << p->Data << " ";
            p = p->Left;
        }else{
            p = s.top();
            s.pop();
            p = p->Right;
        }
    }
}

void Postorder_stack(Tree T) {
    PtrToTNode p,q;
    stack<PtrToTNode> s;
    p = T;
    q = nullptr;
    while( p!=nullptr || !s.empty()) {
        if( p !=nullptr) {
            s.push(p);
            p = p->Left;
        }else {
            p = s.top();
            if((p->Right==nullptr) || (p->Right == q)) {
                cout << p->Data << " ";
                q = p;
                s.pop();
                p = nullptr;
            }else {
                p = p->Right;
            }
        }
    }
}

void Inthread(Tree T) {
static PtrToTNode pre = T;
    if( T ) {
        Inthread(T->Left);

        if(T->Left==NULL){
            T->Left = pre;
            T->Ltag = true;
        } 
        if( pre!=nullptr && pre->Right == nullptr){
            pre->Right = T;
            pre->Rtag = true;
        }
        pre = T;
        
        Inthread(T->Right);
    }
}

PtrToTNode InPre(PtrToTNode T){
    if(T->Ltag==true) return T->Left;
    else{
        PtrToTNode p,pre;
        pre = T->Left;
        for(p = T->Left ;p->Rtag==false;p=p->Right){
            pre = p;
        }
        return p;
    }
}

PtrToTNode InNext(PtrToTNode T){
    if(T->Rtag==true){
        return T->Right;
    }else{
        if(T->Right){
            PtrToTNode q = T->Right;
            PtrToTNode Next = q;
            for(q = T->Right ; q->Ltag == false ;q = q->Left){
                Next = q;
            }
            return  q;
        }else{
            return nullptr;
        }
    }
}

PtrToTNode InFirst(Tree T){
    PtrToTNode p = T;
    if(!p) {return nullptr;}
    else{
        while(p->Ltag==false){
            p = p->Left;
        }
        return p;
    }
}

void TInOrder(Tree T){
    PtrToTNode p;
    p = InFirst(T);
    while(p!=nullptr){
        cout << p->Data << " ";
        p = InNext(p);
    }
} 

int like(Tree t1,Tree t2) {
    int like1,like2;
    if(t1==nullptr && t2==nullptr) {
        return 1;
    }else if(t1==nullptr || t2==nullptr) {
        return 0;
    }else {
        like1 = like(t1->Left,t2->Left);
        like2 = like(t1->Right,t2->Right);
        return (like1 && like2);
    }
}

void path(Tree T,PtrToTNode r) {
    stack<PtrToTNode> s;
    if(!T) return ;
    PtrToTNode p = T;
    PtrToTNode pre = nullptr;
    while(p || !s.empty()){
        while(p) {
            s.push(p);
            p = p->Left;
        }
        if(!s.empty()) {
            p = s.top();
            if(p->Right==nullptr || p->Right== pre){
                if(p == r) {
                    while(!s.empty()) {
                        cout << s.top()->Data << "->" ;
                        s.pop();
                    }
                    cout << endl;
                    return;
                }
                //cout << p->Data << " "; 
                pre = p;
                s.pop();
                p = nullptr;
                
            }else{
                p = p->Right;
            }
        }
    }
}

int main()
{
//AB.DF..G..C.E.H..
    Tree T;
    CreateTree(&T);

    cout << "PreOrder:" << endl;
    PreOrder(T); 

    cout << endl << "InOrder:" << endl;
    Inorder(T);

    cout << endl << "PostOrdere:" << endl;
    PostOrder(T);

    cout << endl << "LayerOrder:" << endl;
    LayerOrder(T);

    int count = 0;
    cout << endl << "Leaf:" << endl;
    PrintLeaf(T,count);
    cout << "Leafnum : " << count << endl;

    cout << "Leafcount : " << LeafCount(T) << endl;

    cout << "PostTreeDepth : " << PostTreeDepth(T) << endl;

    cout << "PreTreeDepth : " ;
    int depth = 0;//最大深度
    int h = 1;//当前深度
    PreTreeDepth(T,depth,h);
    cout << depth << endl; 

    cout << "Tree : " << endl;
    int nlayer = 1;
    PrintTree(T,nlayer);

    cout << "inorder_array : " << endl;
    inorder_array(T);
    cout << endl << "inorder_stack:" << endl;
    inorder_stack(T);

    cout << endl << "Preorder_array : " << endl;
    Preorder_array(T);
    cout << endl << "Preorder_stack" << endl;
    Preorder_stack(T);

    cout << endl << "Postorder_stack" << endl;
    Postorder_stack(T);

    cout << endl << "like : " << endl;
    cout << (like(T,T)) << endl;

    cout << endl << "path" << endl;
    path(T,T->Right->Right->Right);

    cout << endl << "thread traversal:" << endl;
    Inthread(T);

    TInOrder(T);
    
}