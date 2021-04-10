#include <iostream>
using namespace std;

typedef struct TreeNode *Tree;
struct TreeNode {
	Tree Left;
	Tree Right;
	int data;
	int height;
};

Tree NewNode(int t) {
	Tree T;
	T = new struct TreeNode;
	T->Left = T->Right = NULL;
	T->data = t;
	T->height = 0;//二叉树中结点的高度即该结点到叶子结点的路径长度
	return T;
}
int Max(int a, int b) {
	return a > b ? a : b;
}
int GetNodeHeight(Tree T) {//判断一个结点的高度：到叶子节点的最短路径
	if (!T)return -1;
	else {
		return T->height;
	}
}

Tree SingleLeftRotation(Tree A) {//左单旋 向右转
	Tree B = A->Left;
	A->Left = B->Right;//防止忽略B的右子树
	B->Right = A;
	//调整结束
	A->height = Max(GetNodeHeight(A->Left), GetNodeHeight(A->Right))+1;
	B->height = Max(GetNodeHeight(A), GetNodeHeight(B->Left)) + 1;
	return B;
}
Tree SingleRightRotation(Tree A) {//
	Tree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->height = Max(GetNodeHeight(A->Left), GetNodeHeight(A->Right)) + 1;
	B->height = Max(A->height, GetNodeHeight(B->Right)) + 1;
	return B;
}
Tree DoubleLeftRightRotation(Tree A) {
	//B和C做右单旋，返回C
	A->Left = SingleRightRotation(A->Left);
	//A和C做左单旋
	return SingleLeftRotation(A);
}
Tree DoubleRightLeftRotation(Tree A) {
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
		if (t > T->data) {//待插入的数据大于当前结点数据，则应该插在其右子树上面
			T->Right = insert(T->Right, t);
			if (GetNodeHeight(T->Right) - GetNodeHeight(T->Left) == 2) {
				if (t > T->Right->data) {
					T = SingleRightRotation(T);
				}
				else T = DoubleRightLeftRotation(T);
			}
		}
		else {
			T->Left = insert(T->Left, t);
			if (GetNodeHeight(T->Left) - GetNodeHeight(T->Right) == 2) {
				if (t < T->Left->data) {
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
	if (T)cout << T->data << endl;//T里面有内容认为是真，否则为假
	system("pause");
	return 0;
}
