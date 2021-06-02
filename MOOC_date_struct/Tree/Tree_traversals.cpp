#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历， */
void InorderTraversal( BinTree BT );  /* 中序遍历， */
void PostorderTraversal(BinTree BT);  /* 后序遍历， */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
BinTree Insert( BinTree BST, ElementType X )
{
    if(!BST){
        BST=(BinTree)malloc(sizeof(struct TNode));//找到了插入的地方
        BST->Data=X;
        BST->Left=NULL;
        BST->Right=NULL;
    }else if(X<BST->Data){
        BST->Left=Insert(BST->Left,X);//小于走左边
    }else if(X>BST->Data){
        BST->Right=Insert(BST->Right,X);//大于走右边
    }
    return BST;
}
BinTree Delete( BinTree BST, ElementType X )
{
    Position Tmp;
    if(!BST){
        printf("Not Found\n");
    }else if(X < BST->Data){
        BST->Left=Delete(BST->Left,X);//走左边删除
    }else if(X > BST->Data){
        BST->Right=Delete(BST->Right,X);//走右边删除
    }else {
        if(BST->Left&&BST->Right){  //如果左右儿子都不空
            Tmp=FindMax(BST->Left);
            BST->Data=Tmp->Data;
            BST->Left=Delete(BST->Left,Tmp->Data);
        }else{
            Tmp=BST;
            if(!BST->Left){ //左儿子空
                BST=BST->Right;
            }else              //又儿子空或者都空
                BST=BST->Left;
            free(Tmp);
        }
    }
    return BST;
}
Position Find( BinTree BST, ElementType X )
{
    while(BST&&(BST->Data!=X)){
        if(BST->Data>X){
            BST=BST->Left;
        }else{
            BST=BST->Right;
        }
    }
    return BST;
}
Position FindMin( BinTree BST )
{
    if(BST) {
        while(BST->Left){
            BST=BST->Left;
        }
    }
    return BST;
}
Position FindMax( BinTree BST )
{
    if(BST){
        while(BST->Right){
            BST=BST->Right;
        }
    }
    return BST;
}
void PreorderTraversal( BinTree BT ){
    if(!BT) return ;
    printf(" %d",BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}
void InorderTraversal( BinTree BT )
{
    if(!BT)return ;
    InorderTraversal(BT->Left);
    printf(" %d",BT->Data);
    InorderTraversal(BT->Right);
}
void PostorderTraversal(BinTree BT)
{
    if(!BT)return ;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %d",BT->Data);
}