#include<iostream>
using namespace std;

struct Node {
    char data;
    int parent;
};

struct SeqList {
    char elem[10000];
    int last;
};

struct ParentTree{
    Node tree[10000];
    int nodenum;
};

typedef ParentTree ParentForest;
typedef ParentForest MFSst;

void Initialization(MFSst *SS,SeqList* S) {
    SS->nodenum = S->last+1;
    for(int i=0 ; i<SS->nodenum ; ++i) {
        SS->tree[i].data = S->elem[i];
        SS->tree[i].parent = -1;
    }
}

int Located(MFSst *SS,char x) {
    for(int i=0 ;i<SS->nodenum ; ++i) {
        if(x == SS->tree[i].data) {
            return i;
        }
    }
    return -1;
}

int Find_1(MFSst *SS,char x) {
    int pos = Located(SS,x);
    if(pos==-1) {
        return -1;
    }
    while(SS->tree[pos].parent>=0){
        pos = SS->tree[pos].parent;
    }
    return pos;
}

int Find_2(MFSst *SS,char x) {
    int pos = Located(SS,x);
    if(pos == -1) return -1;
    int i = pos;
    while(SS->tree[i].parent>=0) {
        i = SS->tree[i].parent;
    }
    int root = i;
    i = pos;
    while(i!=root) {
        int temp = SS->tree[i].parent;
        SS->tree[i].parent = root;
        i = temp;
    }
    return root;
}

bool Merge_1(MFSst* SS,int root1,int root2) {
    if(root1<0 || root1>SS->nodenum-1) return false;
    if(root2<0 || root2>SS->nodenum-1) return false;
    SS->tree[root2].parent = root1;
    return true;
}

bool Merge_2(MFSst* SS,int root1,int root2) {
    if(root1<0 || root1>SS->nodenum-1) return false;
    if(root2<0 || root2>SS->nodenum-1) return false;

    if(SS->tree[root1].parent<SS->tree[root2].parent) {
        SS->tree[root2].parent = root1;
        SS->tree[root1].parent +=SS->tree[root2].parent;
    }else{
        SS->tree[root1].parent = root2;
        SS->tree[root2].parent +=SS->tree[root1].parent;
    }
    return true;
}


int main()
{
    MFSst SS;
    SeqList S = {{'A','B','C','E','F','G'},5};
    Initialization(&SS,&S);

    for(int i=0 ;i<SS.nodenum ;i++){
        cout << SS.tree[i].data << ' '<<SS.tree[i].parent << endl;
    }

    Merge_1(&SS,0,1);
    Merge_1(&SS,0,2);
    Merge_1(&SS,3,4);
    Merge_1(&SS,4,5);

    for(int i=0 ;i<SS.nodenum ;i++){
        cout << SS.tree[i].data << ' '<<SS.tree[i].parent << endl;
    }

    for(int i=0;i<SS.nodenum;++i) {
        cout << Find_2(&SS,'A'+i) << " ";
    }
}