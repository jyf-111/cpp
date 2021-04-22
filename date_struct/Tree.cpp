#include<iostream>
#include<queue>
#include<malloc.h>
using namespace std;
using ElementType = int;
using BinTree = class TreeNode*;
using Position = BinTree;
void PreorderTraversal( BinTree BT ); /* 先序遍历， */
void InorderTraversal( BinTree BT );  /* 中序遍历， */
void PostorderTraversal(BinTree BT);  /* 后序遍历， */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

class TreeNode {
public:
    ElementType data;
    BinTree left;
    BinTree right;

    TreeNode() = default;
    TreeNode(ElementType X) : data(X),left(nullptr),right(nullptr) {} 
};

BinTree Insert(BinTree T,ElementType X) {
        if(T == nullptr) {
            T = new TreeNode(X);

        }else if(X > T->data) {
            T->right = Insert(T->right,X);
        }else{
            T->left = Insert(T->left,X);
        }
        return T;
}

BinTree Delete(BinTree T,ElementType X) {
    if(T == nullptr) return nullptr;
    else if(X > T->data) {
        T->right = Delete(T->right,X);
    }else if(X <T->data){
        T->left = Delete(T->left,X);
    }else{
        if(T->left&&T->right) {
            Position temp = FindMax(T->left);
            T->data = temp->data;
            T->left = Delete(T->left,temp->data);
        }else {
            Position temp = T;
            if(!T->left){
                T = T->right;
            }else{
                T = T->left;
            }
            delete (temp);
        }
    }
    return T;
}

Position FindMax(BinTree T) {
    if(T){
        while(T->right){
            T = T->right;
        }
    }
    return T;
}

void PreOrderTraverse(TreeNode* root){
	if(NULL == root)
		return;
	cout<<root->data << " ";
	PreOrderTraverse(root->left);
	PreOrderTraverse(root->right);
}


int main()
{
    
    ElementType X;
    int N, i;
    BinTree BST;
    BST = NULL;

    for ( i=0; i<5; i++ ) {

        BST = Insert(BST, i);
    }
    Delete(BST,3);
    PreOrderTraverse(BST);
}