/*
*An AVL tree is a self-balancing binary search tree. In an AVL tree,
the heights of the two child subtrees of any node differ by at most one;
if at any time they differ by more than one, rebalancing is done to restore this property. 
Figures 1-4 illustrate the rotation rules.
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

Input Specification:
Each input file contains one test case. For each case, 
the first line contains a positive integer N (≤20) which is the total number of keys to be inserted.
Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

5
88 70 61 96 120

7
88 70 61 96 120 90 65

Output Specification:
For each test case, print the root of the resulting AVL tree in one line.

70

88
*/

#include<iostream>
using namespace std;
#define Max(a,b) (a>b?a:b)

typedef struct TreeNode *Tree;
struct TreeNode
{
    Tree Left;
    Tree Right;
    int date;
    int height;
};

Tree NewNode(int t)
{
    Tree T = new struct TreeNode;
    T->date = t;
    T->height = 0;
    T->Left = T->Right = nullptr;
    return T;
}

int GetNodeHeight(Tree T)//判断一个结点的高度：到叶子节点的最短路径
{
    return (T ? T->height : -1) ;
}

Tree SingleLeftRotation(Tree A)//左单旋 向右转
{
    Tree B = A->Left;
    A->Left = B->Right;//防止忽略B的右子树
    B->Right = A;
    //调整结束
    A->height = Max(GetNodeHeight(A->Left),GetNodeHeight(A->Right))+1;
    B->height = Max(GetNodeHeight(B->Left),GetNodeHeight(B->Right))+1;
    return B;
}

Tree SingleRightRotation(Tree A)
{
    Tree B = A->Right;
    A->Right = B->Left;
    B->Left = A;

    A->height = Max(GetNodeHeight(A->Left),GetNodeHeight(A->Right))+1;
    B->height = Max(GetNodeHeight(B->Left),GetNodeHeight(B->Right))+1;
    return B;
}

Tree DoubleLeftRightRotation(Tree A)
{
    //B和C做右单旋，返回C
    A->Left = SingleRightRotation(A->Left);
    //A和C做左单旋
    return SingleLeftRotation(A);
}

Tree DoubleRightLeftRotation(Tree A)
{
    //B和C做zuo单旋，返回C
    A->Right = SingleLeftRotation(A->Right);
    //A和C做you单旋
    return SingleRightRotation(A);
}

Tree insert(Tree T, int t) {
	if (!T) {
		T = NewNode(t);//建立一棵树的头结点 
	}
	else {
		if (t > T->date) {//待插入的数据大于当前结点数据，则应该插在其右子树上面
			T->Right = insert(T->Right, t);
			if (GetNodeHeight(T->Right) - GetNodeHeight(T->Left) == 2) {
				if (t > T->Right->date) {
					T = SingleRightRotation(T);
				}
				else T = DoubleRightLeftRotation(T);
			}
		}
		else {
			T->Left = insert(T->Left, t);
			if (GetNodeHeight(T->Left) - GetNodeHeight(T->Right) == 2) {
				if (t < T->Left->date) {
					T = SingleLeftRotation(T);
				}
				else T = DoubleLeftRightRotation(T);
			}
		}
	}
	T->height = Max(GetNodeHeight(T->Left), GetNodeHeight(T->Right)) + 1;
	return T;
}
int main() {
	int N,t;
	cin >> N>>t;
	Tree T = NewNode(t);
	for (int i = 1; i < N; i++)
	{		
		cin >> t;
		T = insert(T, t);
	}
	if (T)cout << T->date << endl;//T里面有内容认为是真，否则为假
	//system("pause");
	return 0;
}