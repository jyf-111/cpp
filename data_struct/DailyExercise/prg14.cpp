//ʹ���������ݽṹ
#include<iostream>
//#define NULL 0
#define N 100
using namespace std;

typedef  struct  BiTNode {  
	int  data;
   	struct  BiTNode *lchild, *rchild;
}BiTNode, * BiTree;

int datagroup[N];
int index;
/*
��Ƶ�һ������
void CreateTree(BiTree *t);�ú����Ĺ����ǽ�����datagroup�е����ݣ��������������ʽ�����һ��������
datagroup�����Ԫ�ص�ֵ��Ϊ���и����ڵ�����ݣ����涨���ĳ��Ԫ�ص�ֵΪ-1����ʾ��Ӧ�Ľڵ���NULL�ڵ㡣*/
void CreateTree(BiTree *t) {
	*t = new struct BiTNode;	
	(*t)->lchild = nullptr;
	(*t)->rchild = nullptr;
	(*t)->data = datagroup[index];
	if(datagroup[index++]!=-1){
		CreateTree(&(*t)->lchild);
		CreateTree(&(*t)->rchild);
	}
}
//��Ƶڶ�������
//�ú����Ĺ�����ͳ��t��ָ������ķ�Ҷ�ӽڵ����������ظ�ֵ��
int NodeNum( BiTree t ) {
	if(t->lchild->data==-1 && t->rchild->data==-1 || !t->lchild && !t->rchild) {
		return 0;
	}else{
		if(t->lchild->data==-1) {
			return NodeNum(t->rchild)+1;
		}else if(t->rchild->data==-1){
			return NodeNum(t->lchild)+1;
		}else{
			return NodeNum(t->lchild)+NodeNum(t->rchild)+1;
		}
	}
}

void PrintfTree(BiTree T,int n) {
	if(T) {
		PrintfTree(T->rchild,n+1);
		for(int i=0;i<n;i++) {
			cout << "  " ;
		}
		cout << T->data << endl;
		PrintfTree(T->lchild,n+1);
	}
}

int main(int argc, char* argv[])
{
	BiTree root; 
	int i;

	for(i = 0; i < 15;i++)
		scanf("%d", &datagroup[i]); 
	index = 0;
	CreateTree(&root);
	index = 0;
	PrintfTree(root,index+1);

	printf("%d\n",  NodeNum(root));
}
/*
1 2 4 -1 -1 5 -1 -1 3 6 -1 7 -1 -1 -1
ִ�еĽ��Ϊ
4
*/