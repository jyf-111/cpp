/*Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

Input Specification:
Each input file contains one test case. For each case, 
the first line gives a positive integer N (≤10)
which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1.
Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node.
If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6

Output Specification:
For each test case, print in one line all the leaves' indices in the order of top down, 
and left to right. There must be exactly one space between any adjacent numbers, 
and no extra space at the end of the line.   4 1 5
*/
//借助循环队列层序遍历
#include<iostream>
#include<stdlib.h>
#define Maxsize 11
#define Null -1
using std::cin;
using std::cout;
using std::endl;


typedef struct TNode
{
    int left;
    int right;
}Tree;

typedef struct Node* Queue;
struct Node
{
    int Data[Maxsize];
    int Front;
    int Rear;
    int num;//队列当前高度
};

//建树返回根节点
int InitTree(int n,Tree (&tree)[Maxsize]);

void InitQueue(Queue Q);

bool Push(Queue Q,int X);

int Pop(Queue Q);

int main()
{
    Tree tree[Maxsize];
    Queue Q = (Queue)malloc(sizeof(struct Node));
    
    int root;
    int n;
    cin >> n;//树的节点数

    root = InitTree(n,tree);

    InitQueue(Q);

    //层序遍历

    //压入根节点
    int flag = 0;
    int value = Null;
    Push(Q,root);
    while(Q->num>0){
        value = Pop(Q);
        if(tree[value].left != Null){
            Push(Q,tree[value].left);
        }
        if(tree[value].right!= Null){
            Push(Q,tree[value].right);
        }
        if(tree[value].left == Null&&tree[value].right==Null)
        if(flag == 0){
            cout << value;
            flag = 1;
        }else{
            cout <<' '<< value ;
        }
    }


    return 0;
}

int InitTree(int n,Tree (&tree)[Maxsize])
{
    int mark[n]={0};//标记节点
    int root = Null;
    char left;
    char right;
    
    for(int i = 0 ; i< n ; i++)
    {
        cin >> left >> right;
        if(left !='-'){
            tree[i].left = left - '0';
            mark[left-'0'] = 1;
        }else{
            tree[i].left = Null;
        }
        if(right != '-'){
            tree[i].right = right - '0';
            mark[right-'0'] = 1;
        }else{
            tree[i].right = Null;
        }

        for(int i = 0; i < n ; ++i)
        {
            if(mark[i]==0){
                root = i;
                break;
            }
        }
        
    }
    return root;
}

void InitQueue(Queue Q)
{
    Q->Front = 0;
    Q->Rear = 0;
    Q->num = 0;
    for(int i = 0 ; i < Maxsize ; ++i){
        Q->Data[i] = 0;
    }
}

bool Push(Queue Q,int X)
{
    if(Q->num == Maxsize){
        cout << "Queue is full ,push fail" << endl;
        return false;
    }
    Q->Data[Q->Rear] = X;
    Q->num++;
    Q->Rear = (Q->Rear+1)%Maxsize;
    return true;
}

int Pop(Queue Q)
{
    if(Q->num <= 0){
        cout << "the Queue is empty ,Pop fail" <<endl;
        return Null;
    }
    int num = Q->Data[Q->Front];
    Q->Front = (Q->Front+1)%Maxsize;
    Q->num--;
    return num;
}

